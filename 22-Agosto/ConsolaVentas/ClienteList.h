#ifndef __CLIENTELIST_H__
#define __CLIENTELIST_H__
#include <string.h>
class Cliente{
    private:
        int id;
        string nombre;
        string apellido;

    public:
        Cliente(){
            this->id = 0;
        }
        Cliente(int idC, string nC, string aC){
            this->id = idC;
            this->nombre = nC;
            this->apellido = aC;
        }
        void setIdCliente(int idC){
            this->id = idC;
        }
        int getIdCliente(){
            return this->idC;
        }
        void setNombreCliente(string nC){
            this->nombre = nC;
        }
        string getNombreCliente(){
            return this->nombre;
        }
        void setApellidoCliente(string nC){
            this->apellido = nC;
        }
        string getApellidoCliente(){
            return this->apellido;
        }
};
#endif // __CLIENTELIST_H__