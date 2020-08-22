#ifndef VENTAS
#define VENTAS

#include <string.h>
#include "Producto.h"
#include "Cliente.h"
#define TAM 5
class Ventas{
private:
    int noFactura;
    Cliente cliente;
    //string cliente;
    Producto lstProductosVendidos[TAM];
    int contadorProductos;
public:
    Ventas(){
    this->noFactura = 0;
    this-> contadorProductos = 0;
    }
    Ventas(int nf, Cliente c){
    //Ventas(int nf, string c){
        this->noFactura = nf;
        this->cliente = c;
        this->contadorProductos = 0;
    }
    void setNumeroFactura(int nf){
        this->noFactura = nf;
    }
    int getNumeroFactura(){
        return this->noFactura;
    }
    void setCliente(Cliente c){
    //void setCliente(string c){
        this->cliente = c;
    }
    Cliente getCliente(){
    //string getCliente(){
        return this->cliente;
    }
    void addLstProducto(Producto p){
        if (this->contadorProductos<TAM){
            this->lstProductosVendidos[this->contadorProductos] = p;
            this->contadorProductos++;
        }
        else{
            cout << "La lista de productos esta llena\n";
        }
    }
    Producto *getLstProducto(){
        return this->lstProductosVendidos;
    }
    int getContadorProducto(){
        return this->contadorProductos;
    }
};

#endif // VENTAS
