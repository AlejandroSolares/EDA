#ifndef TRABAJADORTIEMPOCOMPLETO
#define TRABAJADORTIEMPOCOMPLETO
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "Trabajador.h"
class TrabajadorTiempoCompleto : public Trabajador{
private:
    float descuentoIsss;
    float descuentoAfp;
public:
    TrabajadorTiempoCompleto(){
        this->descuentoIsss =0;
        this->descuentoAfp =0;
    }
    TrabajadorTiempoCompleto(int idP, string nP, string aP, float s) : Trabajador(idP,nP,aP){
        this->sueldo = s;
        this->descuentoIsss = s * 0.0725;
        this->descuentoAfp = s * 0.0725;
        this->descuentoIsr = 0;
        for( int i = 0; i < 10; i++ )
        {
           if(this->sueldo >= 0.01 && this->sueldo <= 472)
            {
                this->descuentoIsr = 0;
            }
           else if(sueldo >= 472.01 && sueldo <= 895.24)
            {
                this->descuentoIsr = ((this->sueldo - 472) * 0.10 ) + 17.67;
            }
           else if(sueldo >= 895.25 && sueldo <= 2038.10)
            {
                this->descuentoIsr = ((this->sueldo - 895.25) * 0.20 ) + 60.00;
            }
            else if(sueldo >= 2038.11)
            {
                this->descuentoIsr = ((this->sueldo - 2038.10) * 0.30 ) + 288.57;
            }
        }
        this->totalDescuentos = this->descuentoIsss + this->descuentoAfp + this->descuentoIsr;
        this->totalPagar = this->sueldo - this->totalDescuentos;
    }
    int getDescuentoIsss(){
        return this->descuentoIsss;
    }
    int getDescuentoAfp(){
        return this->descuentoAfp;
    }
    int getTipoTrabajador(){
        return 2;
    }

};
#endif // TRABAJADORTIEMPOCOMPLETO
