#ifndef PRODUCTO
#define PRODUCTO
#include <string.h>
class Producto{
private:
    int idProducto;
    string nombreProducto;
    float existencia;
public:
    Producto(){
        this->idProducto = 0;
        this->existencia = 0;
    }
    Producto (int id, string n){
        this->idProducto = id;
        this->nombreProducto = n;
        this->existencia = 0;
    }
    void setIdProducto(int id){
        this->idProducto = id;
    }
    int getIdProducto(){
        return this->idProducto;
    }
    void setNombreProducto(string n){
        this->nombreProducto = n;
    }
    string getNombreProducto(){
        return this->nombreProducto;
    }
    void setExistencia (float e){
        this->existencia = e;
    }
    float getExistencia (){
        return this->existencia;
    }
};


#endif // PRODUCTO
