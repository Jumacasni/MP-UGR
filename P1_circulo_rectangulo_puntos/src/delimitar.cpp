#include <iostream>
#include <fstream>
#include "rectangulo.h"


using namespace std;

void Avanzar(istream& is)
{
 while (isspace(is.peek()) || is.peek()=='#') {
	if (is.peek()=='#')
		is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
	else is.ignore();
  }
}

Rectangulo BoundingBox(istream& is) 
{
 	int min_x, min_y, max_x, max_y;
	Punto p;
	Rectangulo r;

	Avanzar(is);
	Leer(is, p);
	min_x = max_x = p.x;
	min_y = max_y = p.y;

	while (Leer(is, p)) {
		if (p.x < min_x)
			min_x = p.x;
		if (p.y < min_y)
			min_y = p.y;
		if (p.x > max_x)
			max_x = p.x;
		if (p.y > max_y)
			max_y = p.y;
		
		Avanzar(is);
	}

	r.esquina_inf_izda.x = min_x;
	r.esquina_inf_izda.y = min_y;
	r.esquina_sup_dcha.x = max_x;
	r.esquina_sup_dcha.y = max_y;

	return r;
}

int main(int argc, char* argv[1]){

	Rectangulo r_resultado;
	bool fin_entrada;

	cout << "Programa para buscar un rectángulo que delimita un conjunto de puntos:" << endl;

	if (argc==1) { // Si no hemos dado parámetros en la línea de órdenes
		r_resultado = BoundingBox(cin);
		fin_entrada=cin.eof();
	}
	else {
		ifstream f(argv[1]); // Como parámetro, el nombre del archivo
		if (!f) {
			cerr << "Error: no se abre " << argv[1] << endl;
			return 1;
		}
		r_resultado = BoundingBox(f);
		fin_entrada=f.eof();
	}

	if (!fin_entrada) {
		cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
		return 1;
	}
	cout << "(" << r_resultado.esquina_inf_izda.x << "," << r_resultado.esquina_inf_izda.y << ")-(" << r_resultado.esquina_sup_dcha.x << "," << r_resultado.esquina_sup_dcha.y << ")" << endl;
}	
