#ifndef _RECTANGULO_H
#define _RECTANGULO_H
#include <iostream>
#include "punto.h"

struct Rectangulo{
	Punto esquina_inf_izda, esquina_sup_dcha;
};

bool Leer(std::istream& is, Rectangulo& r);

bool Escribir(std::ostream& os, const Rectangulo& r);

void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2);

Punto InferiorIzquierda (const Rectangulo& r);

Punto SuperiorDerecha (const Rectangulo& r);

double Area(const Rectangulo& r);

bool Interior (const Punto& p, const Rectangulo& r);

#endif
