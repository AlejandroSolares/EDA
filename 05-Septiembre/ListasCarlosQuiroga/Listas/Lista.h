#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"
class Lista{
private:
    Nodo *Primero;
    Nodo *Ultimo;
    bool ListaVacia(){
        return (this->Primero == NULL);
    }
public:
    Lista(){
        this->Primero = NULL;
        this->Ultimo = NULL;
    }
    void Insertar(int v){
        Nodo *nuevo = new Nodo(v);
        if (this->ListaVacia()){
            this->Primero = nuevo;
        }
        else {
            this->Ultimo->Siguiente = nuevo;
        }
        this->Ultimo = nuevo;
    }

    void Mostrar(){
        Nodo *tmp = this->Primero;
        while (tmp){
            cout << tmp->Valor << "-->";
            tmp = tmp->Siguiente;
        }
        cout << "NULL ";

    }
    void Modificar(int v1, int v2)
    {
        Nodo *elemento=Buscar(v1);
        if(elemento){
            elemento->Valor=v2;
        }
        else
        {
            cout << "Numero no encontrado\n";
        }
    }
    Nodo *Buscar(int v)
    {
        Nodo *elemento=NULL;
        Nodo *temporal = this->Primero;
        bool encontrado = false;
        while(temporal && encontrado==false)
        {
            if(temporal->Valor == v)
            {
                encontrado = true;
                elemento=temporal;
            }
            else
            {
                temporal = temporal->Siguiente;
                elemento=NULL;
            }
        }
        if(encontrado == true){
            cout << "\nNumero encontrado\n";
        }else{
            cout << "Numero no encontrado\n";
        }
        return elemento;
    }
    bool Eliminar(int ve){
        Nodo *anterior = NULL;
        Nodo *tmp = this->Primero;
        Nodo *resultado = NULL;
        bool confirmacionEliminacion = false;
        bool encontrado = false;
        while(tmp && !encontrado){
            if(tmp->Valor == ve){
                encontrado = true;
                resultado = tmp;
            }
            else{
                anterior = tmp;
                tmp = tmp->Siguiente;
            }
        }
        if(resultado){
            confirmacionEliminacion = true;
            if(resultado == this->Primero){
                this->Primero = this->Primero->Siguiente;
            }else{
            if(resultado == this->Ultimo){
                anterior->Siguiente = NULL;
            }else{
            anterior->Siguiente = tmp->Siguiente;
            }
            }
            delete resultado;
        }
        return confirmacionEliminacion;
    }
};

#endif // LISTA_H_INCLUDED
