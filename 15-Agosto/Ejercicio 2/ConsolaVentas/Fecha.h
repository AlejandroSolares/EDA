#ifndef FECHA
#define FECHA

class Fecha
{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(){
    }
    Fecha(int d, int m, int a){
            this->dia = d;
            this->mes = m;
            this->anio = a;
    }
    void MostrarFecha(){
            cout << this->dia << "/";
            cout << this->mes << "/";
            cout << this->anio;
    }
};

#endif // FECHA
