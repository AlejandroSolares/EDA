#define TRABAJADOR
#include <string.h>
#include "Persona.h"

class Trabajador : public Persona{
protected:
    float sueldo;
    float descuentoIsr;
    float totalDescuentos;
    float totalPagar;
public:
    Trabajador(){
        this->sueldo = 0;
        this->descuentoIsr = 0;
        this->totalDescuentos = 0;
        this->totalPagar = 0;
    }
    Trabajador(int idP, string nP, string aP): Persona(idP,nP,aP){
        this->sueldo = 0;
        this->descuentoIsr = 0;
        this->totalDescuentos = 0;
        this->totalPagar = 0;
    }
    float getDescuentoIsr(){
        return this->descuentoIsr;
    }
    float getTotalDescuentos(){
        return this->totalDescuentos;
    }
    float getTotalPagar(){
        return this->totalPagar;
    }
    virtual int getTipoTrabajador()=0;
};


#endif // TRABAJADOR
