#ifndef PERSONA
#define PERSONA
#include <string.h>
#include "Fecha.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

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
        this->ApellidoPersona = aP;
    }
    string getApellidoPersona(){
        return this->ApellidoPersona;
    }
    /*void setFechaNac (Fecha f){
        this->fechaNac = f;
    }
    Fecha getFechaNac(){
        return this->fechaNac;
    }*/
};

#endif // PERSONAS
