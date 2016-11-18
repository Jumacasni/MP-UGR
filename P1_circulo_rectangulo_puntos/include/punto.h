#ifndef _PUNTO_H
#define _PUNTO_H
#include <iostream>


struct Punto {
    double x,y;
};

Punto LeerPunto();

bool Leer(std::istream& is, Punto& p);

bool Escribir(std::ostream& os, const Punto& p);

void EscribirPunto (Punto p);

void InicializarPunto (Punto &p, double cx, double cy);

double GetX (Punto p);

double GetY (Punto p);

double Distancia (Punto p1, Punto p2);

Punto PuntoMedio (Punto p1, Punto p2);

#endif
