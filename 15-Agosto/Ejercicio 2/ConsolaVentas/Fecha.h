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


/*
#include <iostream>
#include <string>

int main()
{
	int i = 17;
	std::string s = "C++" + std::to_string(i);

	std::cout << s << '\n';

	return 0;
}

*/
