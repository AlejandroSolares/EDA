#ifndef TRABAJADORPORHORA
#define TRABAJADORPORHORA

class TrabajadorPorHora : public Trabajador{
private:
    int numHT;
    float salarioPorHora;
public:
    TrabajadorPorHora(){
        this->numHT = 0;
        this->salarioPorHora = 0;
    }
    TrabajadorPorHora(int idP, string nP, string aP, int nHT, float sPH) : Trabajador(idP,nP,aP){
        this->numHT = nHT;
        this->salarioPorHora = sPH;
        this->sueldo = nHT * sPH;
        this->descuentoIsr = this->sueldo * 0.1;
        this->totalDescuentos = this->descuentoIsr;
        this->totalPagar = this->sueldo - this->totalDescuentos;
    }
    int getNumHT(){
        return this->numHT;
    }
    int getSalarioPorHora(){
        return this->salarioPorHora;
    }
    int getTipoTrabajador(){
        return 1;
    }

};

#endif // TRABAJADORPORHORA
