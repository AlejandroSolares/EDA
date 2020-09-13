#include <iostream>
using namespace std;
#include "Lista.h"
int main(){
    Lista lst;
    lst.Insertar(5);
    lst.Insertar(1);
    lst.Insertar(4);
    lst.Mostrar();
    lst.Modificar(5,4);
    lst.Mostrar();
    lst.Buscar(7);
    lst.Mostrar();
    lst.Eliminar(1);
    lst.Mostrar();
    return 0;
}
