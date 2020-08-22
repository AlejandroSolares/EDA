#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Estudiante.h"
#define LON 5
int menu(){
    int op;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Menu Principal        " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "Seleccione una opcion : \n";
    cout << "1. Agregar Estudiante\n";
    cout << "2. Mostrar lista\n";
    cout << "3. Salir\n";
    cin >> op;
    return op;
}
Estudiante agregarEstudiante(){
    int Id;
    char nom[TAM], apel[TAM];
    float VNota1,VNota2,VNota3;
    Estudiante estd;
    cout << "Digite el codigo : ";
    cin >> Id;
    cout << "Digite su nombre : ";
    cin >> nom;
    cout << "Digite su apellido : ";
    cin >> apel;
    cout << "Digite su nota 1 : ";
    cin >> VNota1;
    cout << "Digite su nota 2 : ";
    cin >> VNota2;
    cout << "Digite su nota 3 : ";
    cin >> VNota3;
    estd.setDatos(Id, nom, apel);
    estd.setNotas(VNota1,VNota2,VNota3);
    return estd;
}

void mostrarLista(Estudiante lista[], int c){
    if (c == 0){
        cout << "La lista esta vacia\n";
    }
    else {
        cout << "Cod\tNombre\tApellido\tPromedio\n";
        for (int i=0;i<c;i++){
            cout << lista[i].getCodigo() << "\t";
            lista[i].mostrarNombre();
            cout << "\t";
            lista[i].mostrarApellido();
            cout << "\t";
            cout << lista[i].getPromedio() << endl;
        }
    }
}

int main(){
    int opc, cont=0;
    Estudiante lista [LON];
    do{
        system ("cls");
        opc = menu();
        switch (opc){
        case 1:
            ///Agregar Estudiante
            if (cont < LON){
                lista[cont] = agregarEstudiante();
                cont++;
            }
            else{
                cout << "Lista llena\n";
            }
            break;
        case 2:
            ///Mostrar lista
            mostrarLista (lista, cont);
            break;
        case 3:
            cout << "Gracias, vuelva pronto\n";
            break;
        default:
            cout << "Error, opcion no valida\n";
            break;
        }
        system ("pause");
    }while (opc!=3);
    return 0;
}
