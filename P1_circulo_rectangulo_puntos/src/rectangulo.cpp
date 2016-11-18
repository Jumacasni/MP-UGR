#include <iostream>
#include <fstream>
#include <cmath>
#include "rectangulo.h"

bool Leer(std::istream& is, Rectangulo& r){

	char c;
	Punto inf_izda, sup_dcha;

	return is >> c >> inf_izda.x >> c >> inf_izda.y >> c >> c >> c >> sup_dcha.x >> c >> sup_dcha.y >> c;
}

bool Escribir(std::ostream& os, const Rectangulo& r) {

return os << "(" << r.esquina_inf_izda.x << "," << r.esquina_inf_izda.y << ")-(" << r.esquina_sup_dcha.x << "," << r.esquina_sup_dcha.y << ")";
}

void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2){

	r.esquina_inf_izda = p1;
	r.esquina_sup_dcha = p2;
}	

Punto InferiorIzquierda (const Rectangulo& r){

	return r.esquina_inf_izda;
}

Punto SuperiorDerecha (const Rectangulo& r){

	return r.esquina_sup_dcha;
}

double Area(const Rectangulo& r){

	Punto inf_izda, sup_dcha;
	
	inf_izda = r.esquina_inf_izda;
	sup_dcha = r.esquina_sup_dcha;

	return (sup_dcha.x - inf_izda.x) * (sup_dcha.y - inf_izda.y);
}
	
bool Interior (const Punto& p, const Rectangulo& r){

	return r.esquina_inf_izda.x <= p.x && p.x <= r.esquina_sup_dcha.x && r.esquina_inf_izda.y <= p.y && p.y <= r.esquina_sup_dcha.y;
}


