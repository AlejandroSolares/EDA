#ifndef CLIENTE
#define CLIENTE

class Cliente{
private:
    int idCliente;
    string nombreCliente;
    Fecha fechaNac;
public:
    Cliente(){
        this->idCliente = 0;
    }
    Cliente(int idC, string nC, Fecha f){
        this->idCliente = idC;
        this->nombreCliente = nC;
        this->fechaNac = f;
    }
    void setIdCliente(int idC){
        this idCliente = idC;
    }
    int getIdCliente(){
        return this->idCliente;
    }
    void setNombreCliente(string nC){
        this->nombreCliente = nC;
    }
    string getNombreCliente(){
        return this->nombreCliente;
    }
    void setFechaNac (Fecha f){
        this->fechaNac = f;
    }
    Fecha getFechaNac(){
        return this->fechaNac;
    }
};

#endif // CLIENTE
