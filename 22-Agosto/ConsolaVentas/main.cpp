#include <iostream>
using namespace std;
#include "Ventas.h"
#include "Cliente.h"
#include "Fecha.h"
#include "Producto.h"
#include "TrabajadorPorHora.h"
#include "TrabajadorTiempoCompleto.h"
#include "Lista.h"
#include "ClienteList.h"

#include <stdlib.h>
#define LON 5
#define TAM 5
int menu(){
    int op;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Menu Principal        " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "Seleccione una opcion\n";
    cout << "1.  Agregar productos\n";
    cout << "2.  Agregar clientes\n";
    cout << "3.  Hacer ventas\n";
    cout << "4.  Ver lista de productos\n";
    cout << "5.  Ver lista de clientes\n";
    cout << "6.  Ver lista de ventas\n";
    cout << "7.  Ver detalles de venta\n";
    cout << "8.  Ingrese trabajador\n";
    cout << "9.  Lista trabajadores\n";
    cout << "10. Detalle trabajador\n";
    cout << "11. Buscar trabajador\n";
    cout << "12. Modificar trabajador\n";
    cout << "13. Eliminar trabajador\n";
    cout << "14. Salir\n";
    cin >> op;
    return op;
}


/* **********************************************
                    CLIENTES
*************************************************/

Cliente addCliente(){
    int id=0;
    int vd,vm,va;
    string nom;
    Fecha fech;
    Cliente cli;
    cout << "Digite el id del cliente : ";
    cin >> id;
    cout << "Digite el nombre del cliente : ";
    cin >> nom;
    cout << "Digite la fecha de nacimiento : ";
    cout << "Dia: ";
    cin >> vd;
    cout << "Mes: ";
    cin >> vm;
    cout << "A�o: ";
    cin >> va;

    fech = Fecha(vd,vm,va);

    cli = Cliente(id,nom, fech);
    //cli.setFechaNac(fech);
    return cli;
}

Cliente buscarCliente(Cliente lst[],int contC,int id){
    bool encontrado = false;
    int c=0;
    Cliente r;
    while(c<contC && !encontrado){
        if (lst[c].getIdCliente() == id){
            encontrado=true;
            r = lst[c];
        }
        else{
            c++;
        }
    }
    return r;
}

void mostrarLstClientes(Cliente lst[], int cont){
    Fecha fch;
    if(cont == 0){
        cout << "La lista esta vacia\n";
    }
    else{
        cout << "No\tCliente\tFecha de Nacimiento\n";
        for(int i=0; i<cont;i++){
            cout << lst[i].getIdCliente() << "\t";
            cout << lst[i].getNombreCliente() << "\t";
            fch = lst[i].getFechaNac();
            cout << fch.MostrarFecha() << "\n";
            //cout << lst[i].getFechaNac() << "\n";
        }
    }
}

/* **********************************************
                    PRODUCTO
*************************************************/
Producto addProducto(){
    int id;
    string nom;
    float e;
    Producto prod;
    cout << "Digite el id : ";
    cin >> id;
    cout << "Digite el nombre del producto : ";
    cin >> nom;
    cout << "Digite la existencia: ";
    cin >> e;
    prod = Producto(id,nom);
    prod.setExistencia(e);
    return prod;
}

Producto buscarProducto(Producto lst[],int contP,int id){
    bool encontrado = false;
    int c=0;
    Producto r;
    while(c<contP && !encontrado){
         if (lst[c].getIdProducto() == id){
            encontrado=true;
            r = lst[c];
        }
        else{
            c++;
        }
    }
    return r;
}

void mostrarLstProducto(Producto lst[], int cont){
    if(cont == 0){
        cout << "La lista esta vacia\n";
    }
    else{
        cout << "id\tNombre\n";
        for(int i=0; i<cont;i++){
            cout << lst[i].getIdProducto() << "\t";
            cout << lst[i].getNombreProducto() << "\n";
        }
    }
}
/* **********************************************
                    VENTAS
*************************************************/
Ventas  addVenta(Producto lst[], Cliente lstc[], int contP){
    int nf, idp, idCli;
    int resp=1;
    Cliente cli;
    //string cli;
    Ventas vta;
    Producto prod;
    cout << "Digite el numero de la factura : ";
    cin >> nf;
    cout << "Digite el id del cliente : ";
    cin >> idCli;

    cli = buscarCliente(lstc, contP, idCli);
        if (cli.getIdCliente() !=0){
            vta.setCliente(cli);
        }
        else{
            cout << "El id no existe\n";
        }
    vta = Ventas(nf,cli);
    do
    {
        cout << "digite el id del producto : ";
        cin >> idp;
        prod = buscarProducto(lst, contP, idp);
        if (prod.getIdProducto() !=0){
            vta.addLstProducto(prod);
        }
        else{
            cout << "El id no existe\n";
        }
        cout << "Desea agregar otro producto Si=1 No=0: ";
        cin >> resp;
    }while(resp==1);


    return vta;
}

void mostrarLstVentas(Ventas lst[], int cont){

    Cliente cli;

    if(cont == 0){
        cout << "La lista esta vacia\n";
    }
    else{
        cout << "No\tCliente\tTotal Productos\n";

        for(int i=0; i<cont;i++){
            cout << lst[i].getNumeroFactura() << "\t";
            //cout << lst[i].getCliente() << "\t";
            cli = lst[i].getCliente();
            cout << cli.getNombreCliente() << "\t";
            cout << lst[i].getContadorProducto() << "\n";
        }
    }
}

Ventas buscarVentas(Ventas lst[],int cont,int id){
    bool encontrado = false;
    int c=0;
    Ventas r;
    while(c<cont && !encontrado){
         if (lst[c].getNumeroFactura() == id){
            encontrado=true;
            r = lst[c];
        }
        else{
            c++;
        }
    }
    return r;
}
/* **********************************************
                TRABAJADORES
*************************************************/
Trabajador* addTrabajador(){
    Trabajador* trab;
    int idTrab = 0, tTrab = 0, nHtrab = 0;
    float sHora = 0.0, SMens = 0.0;
    string nom = "",ape = "";

    cout << "Digite el Id: ";
    cin >> idTrab;
    cout << "Digite los nombres: ";
    cin >> nom;
    cout << "Digite los apellidos: ";
    cin >> ape;
    cout << "Tipo de trabajador(Recuerda que Pago por Horas = 1 y Tiempo Completo = 2)";
    cin >> tTrab;
    if (tTrab ==1){
        cout << "Digite el numero de horas trabajadas: ";
        cin >> nHtrab;
        cout << "Digite el salario por hora: ";
        cin >> sHora;
        trab = new TrabajadorPorHora (idTrab,nom,ape,nHtrab,sHora);
    }
    else {
        cout << "Digite el salario mensual: ";
        cin >> SMens;
        trab = new TrabajadorTiempoCompleto (idTrab,nom,ape,SMens);
        }
    return trab;
}


void mostrarLstTrabajador(Trabajador* lst[], int cont){

    if(cont == 0){
        cout << "La lista esta vacia\n";
    }
    else{
        cout << "No\tNombre\tApellido\tPago\n";
        for (int i=0;i<cont;i++){
        cout << lst [i]->getIdPersona() << "\t";
        cout << lst [i]->getNombrePersona() << "\t";
        cout << lst [i]->getApellidoPersona() << "\t";
        cout << "        " << lst [i]->getTotalPagar() << "\n";
        }
    }
}

Trabajador* buscarTrabajador(Trabajador* lst[], int cont, int id){
    bool encontrado=false;
    int c=0;
    Trabajador* trab;


    while (c < cont && !encontrado){
        if (lst[c]->getIdPersona() == id){
        encontrado = true;
        trab = lst[c];
        }
        else {
            c ++;
        }
    }
    return trab;
}

int buscarTipoTrabajador     (Trabajador *lst[], int cont, int id) {
    int tpo = -1;
    int c=0;
    bool encontrado=false;
    while (c < cont && !encontrado){
        if (lst[c]->getIdPersona() == id){
        encontrado = true;
        tpo = c;
    }
    else {
        c ++;
    }
}
    return tpo;
}


/* **********************************************
                    MAIN
*************************************************/


int main()
{
    int opc;
    Producto lstProducto[TAM];
    Ventas lstVentas[TAM];
    Cliente lstClientes [LON];
    Trabajador* lstTrabajadores[LON];

    int contClt=0, contProd=0, contVta=0, contTrb=0;
    do{
        system("cls");
        opc = menu();
        switch (opc)
        {
        case 1:
            ///Agregar productos
            if (contProd< TAM){
                lstProducto[contProd] = addProducto();
                contProd++;
            }
            else {
                cout << "Lista llena\n";
            }
            break;
        case 2:
            ///Agregar clientes addCliente
            if (contClt< TAM){
                lstClientes[contClt] = addCliente();
                contClt++;
            }
            else {
                cout << "Lista llena\n";
            }
            break;
        case 3:
            ///Hacer ventas
            if (contVta< TAM){
                lstVentas[contVta] = addVenta(lstProducto, lstClientes, contProd);
                contVta++;
            }
            else {
                cout << "Lista llena\n";
            }
            break;
        case 4:
            ///Ver lista de productos
            mostrarLstProducto(lstProducto, contProd);
            break;
        case 5:
            ///Ver lista de clientes
            mostrarLstClientes(lstClientes, contClt);
            break;
        case 6:
            ///Ver lista de ventas
            mostrarLstVentas(lstVentas, contVta);
            break;
        case 7:
            {
                ///Ver detalles de venta
                int nf = 0;
                cout << "Digite el numero de factura : ";
                cin >> nf;
                Ventas vta = buscarVentas(lstVentas,contVta,nf);
                Cliente cli;
                if(vta.getNumeroFactura()!=0){
                    cout << "Factura " << vta.getNumeroFactura()<< endl;
                    cli = vta.getCliente();
                    cout << "Cliente " << cli.getNombreCliente() << endl;
                    cout << "\nLista\n " ;
                    Producto *p = vta.getLstProducto();
                    cout << "\nNombre\n " ;
                    for(int i=0;i<vta.getContadorProducto();i++){
                        cout << p[i].getIdProducto() << "\t";
                        cout << p[i].getNombreProducto() << "\t";
                    }
                }
                else{
                    cout << "La factura no existe\n";
                }
            }
            break;
        case 8:
            ///Agregar trabajador
            if (contTrb< LON){
                lstTrabajadores[contTrb] = addTrabajador();
                contTrb++;
            }
            else {
                cout << "Lista llena\n";
            }
            break;

        case 9:
            ///Mostrar lista Trabajador
            mostrarLstTrabajador(lstTrabajadores, contTrb);
            break;

        case 10:
            ///Mostrar detalles del trabajador
            {
                int idT = 0;
                cout << "Digite el id empleado : ";
                cin >> idT;
                Trabajador* trab = buscarTrabajador(lstTrabajadores,contTrb,idT);
                if(trab->getIdPersona()!=0){
                        ///Se encontro
                cout << "Id: "<< trab->getIdPersona() << endl;
                cout << "Empleado : " << trab->getNombrePersona() << " " << trab->getApellidoPersona() << endl;
                //cout << "Apellidos: " << trab->getApellidoPersona << endl;
                switch(trab->getTipoTrabajador()){
                    case 1: cout << "Modalidad :    Pago por hora" << endl;
                        TrabajadorPorHora* trabajadorporhora;
                        trabajadorporhora = static_cast<TrabajadorPorHora*>(trab);
                        cout << "Sueldo por hora: " << trabajadorporhora->getSalarioPorHora()<<endl;
                        cout << "Horas trabajadas: " << trabajadorporhora->getNumHT() << endl;
                        cout << "Descuento ISR: " << trabajadorporhora->getDescuentoIsr() << endl;
                        cout << "Total Descuentos: " << trabajadorporhora->getTotalDescuentos() << endl;
                        cout << "Total a Pagar: " << trabajadorporhora->getTotalPagar() << endl;

                    break;
                    case 2: cout << "Modalidad :    Pago mensual" << endl ;
                        TrabajadorTiempoCompleto* TrabajadorFijo;
                        TrabajadorFijo = static_cast<TrabajadorTiempoCompleto*>(trab);
                        cout << "Descuento ISSS: " << TrabajadorFijo->getDescuentoIsss() << endl;
                        cout << "Descuento AFP: " << TrabajadorFijo->getDescuentoAfp() << endl;
                        cout << "Descuento ISR: " << TrabajadorFijo->getDescuentoIsr() << endl;
                        cout << "Total de Descuentos: " << TrabajadorFijo->getTotalDescuentos()<<endl;
                        cout << "Total a Pagar: " << TrabajadorFijo->getTotalPagar() << endl;

                    break;
                }
                }
                else{
                    cout << "La factura no existe\n";
                }
            }
            break;
            case 11:
            ///Buscar Trabajador
            bscrTrabajador(lstTrabajadores, contTrb);
            break;
            case 12:
            ///Modificar Trabajador
            mostrarLstTrabajador(lstTrabajadores, contTrb);
            break;
            case 13:
            ///Eliminar Trabajador
            mostrarLstTrabajador(lstTrabajadores, contTrb);
            break;
            case 14:
                cout << "Gracias vuelva pronto\n";
                break;
            default:
            cout << "Error, opcion no valida\n";
            break;
        }
        system("pause");
    }while (opc !=11);
    return 0;
}
