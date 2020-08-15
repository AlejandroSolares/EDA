/*#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;


    return 0;
}
*/
#include <iostream>

using namespace std;




int menu(){
    int op;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "Seleccione una opcion\n";
    cout << "1. Agregar productos\n";
    cout << "2. Agregar clientes\n";
    cout << "3. Hacer ventas\n";
    cout << "4. Ver lista de productos\n";
    cout << "5. Ver lista de clientes\n";
    cout << "6. Ver lista de ventas\n";
    cout << "7. Ver detalles de venta\n";
    cout << "8. Salir\n";
    cin >> op;
    return op;
}
int main()
{
    int opc;
    do{
        system("cls");
        opc = menu();
        switch (opc)
        {
        case 1:
            ///Agregar productos
            break;
        case 2:
            ///Agregar clientes
            break;
        case 3:
            ///Hacer ventas
            break;
        case 4:
            ///Ver lista de productos
            break;
        case 5:
            ///Ver lista de clientes
            break;
        case 6:
            ///Ver lista de ventas
            break;
        case 7:
            ///Ver detalles de venta
            break;
        case 8:
            cout << "Gracias vuelva pronto\n";
            break;
        default:
            cout << "Error, opcion no valida\n";
            break;
        }
        system("pause");
    }while (opc !=8);
    return 0;
}
