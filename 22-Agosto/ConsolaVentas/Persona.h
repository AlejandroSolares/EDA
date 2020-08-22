#ifndef PERSONA
#define PERSONA
#include <string.h>
#include "Fecha.h"

class Persona{
private:
    int idPersona;
    string nombrePersona;
    string ApellidoPersona;
    //Fecha fechaNac;
public:
    Persona(){
        this->idPersona = 0;
    }
    Persona(int idP, string nP, string aP){
        this->idPersona = idP;
        this->nombrePersona = nP;
        this->ApellidoPersona = aP;
    }
    void setIdPersona(int idP){
        this->idPersona = idP;
    }
    int getIdPersona(){
        return this->idPersona;
    }
    void setNombrePersona(string nP){
        this->nombrePersona = nP;
    }
    string getNombrePersona(){
        return this->nombrePersona;
    }
    void setApellidoPersona(string aP){
        this->nombrePersona = aP;
    }
    string getApellidoPersona(){
        return this->nombrePersona;
    }
    /*void setFechaNac (Fecha f){
        this->fechaNac = f;
    }
    Fecha getFechaNac(){
        return this->fechaNac;
    }*/
};
#endif // PERSONAS
#endif // PERSONAS
