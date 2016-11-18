#include <iostream>
#include <fstream>
#include "punto.h"

using namespace std;

void Avanzar(std::istream& is)
{
  while (isspace(is.peek()) || is.peek()=='#') {
	if (is.peek()=='#')
		is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
	else is.ignore();
  }
}

double Longitud(istream& is) 
{
 	Punto p1, p2;
	double distancia = 0;

	Avanzar(is);

	Leer(is,p1);
	
	while (Leer(is,p2)) {
    	distancia = distancia + Distancia(p1, p2);
		p1 = p2;
		Avanzar(is);
	}

  return distancia;
}

int main(int argc, char* argv[1]){

	double longitud = 0;
	bool fin_entrada;

	cout << "Programa para sumar la longitud de una serie de puntos:" << endl;

	if (argc==1) { // Si no hemos dado parámetros en la línea de órdenes
		longitud = Longitud(cin);
		fin_entrada=cin.eof();
	}
	else {
		ifstream f(argv[1]); // Como parámetro, el nombre del archivo
		if (!f) {
			cerr << "Error: no se abre " << argv[1] << endl;
			return 1;
		}
		longitud=Longitud(f);
		fin_entrada=f.eof();
	}

	if (!fin_entrada) {
		cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
		return 1;
	}
	cout << longitud << endl;
}
