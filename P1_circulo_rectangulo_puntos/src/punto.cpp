#include <iostream>
#include <fstream>
#include <cmath>
#include "punto.h"

using namespace std;

Punto LeerPunto()
{
	Punto p;
	char c;

	cin >> c >> p.x >> c >> p.y >> c;
	
	return p;
}

// FIXME: Función para controlar el flujo de entrada de puntos:
bool Leer(istream& is, Punto& p)
{
	char c;

	return is >> c >> p.x >> c >> p.y >> c;	
}

// FIXME: Función para controlar el flujo de salida de puntos:
bool Escribir(ostream& os, Punto& p)
{
	return os << "(" << p.x << "," << p.y << ")";
}

// FIXME: Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (Punto p)
{
	cout << '(' << p.x << ',' << p.y << ')';
}

// FIXME: Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto &p, double cx, double cy)
{
	p.x = cx;
	p.y = cy;
}

// FIXME: Devuelve la coordenada X del punto p
double GetX (Punto p)
{
	return p.x;
}

// FIXME: Devuelve la coordenada Y del punto p
double GetY (Punto p)
{
	return p.y;
}

// FIXME: Devuelve la distancia euclídea entre p1 y p2
double Distancia (Punto p1, Punto p2)
{
	double distancia;
	
	distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

	return distancia;
}

// FIXME: Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (Punto p1, Punto p2)
{
	Punto medio;

	medio.x = (p1.x + p2.x) / 2;
	medio.y = (p1.y + p2.y) / 2;

	return medio;
}

