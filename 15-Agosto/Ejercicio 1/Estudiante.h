#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include <string.h>
#define TAM 15
class Estudiante{
private:
    int codigo;
    char Nombre [TAM];
    char Apellido [TAM];
    float Nota1;
    float Nota2;
    float Nota3;
    float Promedio;
    float SumNotas;
public:
    void setDatos(int cod, char nom[], char ape []){
        this->codigo = cod;
        strcpy (this->Nombre, nom);
        strcpy (this->Apellido, ape);
    }
    void setNotas (float nt1, float nt2, float nt3){
        this->Nota1 = nt1;
        this->Nota2 = nt2;
        this->Nota3 = nt3;
        this->SumNotas = nt1+nt2+nt3;
        this-> Promedio = this->SumNotas/3;
    }
    int getCodigo(){
        return this->codigo;
    }
    void mostrarNombre(){
        cout << this->Nombre;
    }
    void mostrarApellido(){
        cout << this->Apellido;
    }
    float getNota1(){
        return this->Nota1;
    }
    float getNota2(){
        return this->Nota2;
    }
    float getNota3(){
        return this->Nota3;
    }
    float getPromedio(){
        return this->Promedio;
    }
};
#endif // ESTUDIANTE_H_INCLUDED
