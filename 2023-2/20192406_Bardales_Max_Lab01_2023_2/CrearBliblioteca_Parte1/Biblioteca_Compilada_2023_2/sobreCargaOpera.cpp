#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "sobreCargaOpera.h"
#include "Estructuras.h"

bool operator >>(ifstream &arch, struct Cliente &cli){
    
//    79464412,PORTUGAL RAFFO ALEXANDER,3902394
//    16552775,YALLICO PAREDES LOURDES CARMELA,960176666
    int dni;
    arch >> dni;
    if (arch.eof()) return false;
    arch.get();
    arch.getline(cli.nombre,60,',');
    arch >> cli.telefono;
    cli.dni=dni;
    cli.cantidadProductosEntrgados=0;
    cli.montoTotal=0;
    return true;
}


bool operator >>(ifstream &arch, struct Pedido &pedido){
//    JXD-139,50375303
    char buff[8];
    arch.getline(buff,8,',');
    if (arch.eof()) return false;
    arch >> pedido.dniCliente;
    arch.get();
    
    strcpy(pedido.CodigoProducto,buff);
    pedido.precioProducto=0;
    return true;
}

bool operator >>(ifstream &arch, struct Producto &producto){
    char cod[8],c;
//    BIT-434,Campana Extractora modelo Glass,375.09,10
    arch.getline(cod,8,',');
    if (arch.eof()) return false;
    arch.getline(producto.descripcion,60,',');
    arch>>producto.precio>>c; 
    arch>>producto.stock;
    arch.get();
    strcpy(producto.codigo,cod);
    producto.cantidadClientesNoServidos = 0;
    producto.cantidadClientesServidos = 0;
    
    return true;
}

void operator +=(struct Cliente *arrClientes,const struct Pedido &ped){
    int pos=0,flag=0;
    for (pos;arrClientes[pos].dni !=0 ;pos++){
        if (arrClientes[pos].dni== ped.dniCliente){
            flag =1;
            break;
        }
    }
    
    // asignar el pedido en caso haya sido encontrado el pedido 
    if (flag == 1){ //se esta asumiendo que no se repetiran los productos
        int cantProdEnco=arrClientes[pos].cantidadProductosEntrgados;
        strcpy(arrClientes[pos].productosEntregados[cantProdEnco].codigo,ped.CodigoProducto);
        arrClientes[pos].productosEntregados[cantProdEnco].precio=ped.precioProducto;
        arrClientes[pos].cantidadProductosEntrgados++;
        arrClientes[pos].montoTotal+=ped.precioProducto;
    }else cout<<"no se encontro el cliente "<<endl;
    
}

bool operator +=(struct Producto *arrProd,struct Pedido &ped){
    int pos=0,flag=0;
    for (pos;strcmp(arrProd[pos].codigo, "XXXXXXX")  != 0 and arrProd[pos].codigo[0]!='\0'; pos++ ){
        if (strcmp(arrProd[pos].codigo, ped.CodigoProducto)  == 0){
            flag=1;
            break;
        }
    }
    
    //asignacion del precio al pedido 
    if (flag==1){
        if (arrProd[pos].stock > 0){
            arrProd[pos].stock--;
            arrProd[pos].clientesServidos[arrProd[pos].cantidadClientesServidos]=ped.dniCliente;
            arrProd[pos].cantidadClientesServidos++;
            ped.precioProducto=arrProd[pos].precio; //si hay stock le pongo precio
            return true;
        }else{
            arrProd[pos].clientesNoServidos[arrProd[pos].cantidadClientesNoServidos]=ped.dniCliente;
            arrProd[pos].cantidadClientesNoServidos++;
            return false;
        }  
    }
    cout<<"No se encontro el pedido "<<endl;
    return false; 
}


void operator <<(ofstream &arch, const struct Cliente &cli){
    
    arch <<left << setw(10)<<cli.dni  <<cli.nombre  <<setw(50-strlen(cli.nombre))<<' '<< setw(15)<<
            cli.telefono << cli.montoTotal;
    
    if (cli.cantidadProductosEntrgados !=0){
        arch << left << setw(3) << ' ' << "Productos entregados:  ";
        for (int i=0;cli.cantidadProductosEntrgados > i;i++)
            arch<<setw(10)<<cli.productosEntregados[i].codigo;
        arch<<endl;
    }else arch<<"   NO SE LE ENCONTRARON PRODUCTOS"<<endl;
}

void operator <<(ofstream &arch, const struct Producto &prod){
    arch << left << setw(20) << prod.codigo << setw(40) << prod.descripcion  << right <<
            fixed << setprecision (2) << prod.precio << setw(10) << prod.stock << endl;
    
    if(prod.cantidadClientesServidos>0){
        arch << "Clientes atendidos: ";
        for(int i=0;i<prod.cantidadClientesServidos;i++)
            arch << setw(10) << prod.clientesServidos[i];arch << endl;
        
    }else{
        arch << "NO SE ATENDIERON PEDIDOS" << endl;
    }
    
    if(prod.cantidadClientesNoServidos >0){
        arch << "Clientes no atendidos: " ;
        for(int i=0;i<prod.cantidadClientesNoServidos;i++)
            arch << setw(10) << prod.clientesNoServidos[i];arch << endl;
        
    }else{
        arch << "NO HAY CLIENTES SIN ATENDER" << endl;
    }  
}