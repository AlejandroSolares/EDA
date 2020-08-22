#ifndef FECHA
#define FECHA

class Fecha
{
private:
    int dia;
    int mes;
    int anio;
    string fecha;
public:
    Fecha(){
    }
    Fecha(int d, int m, int a){
            this->dia = d;
            this->mes = m;
            this->anio = a;
    }
    string MostrarFecha(){
            fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
            return this -> fecha;
    }
};

#endif // FECHA
