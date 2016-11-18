#include <iostream>
#include <cmath>
#include "circulo.h"

using namespace std;

// FIXME: Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
Circulo LeerCirculo()
{
	Circulo circulo;
	char c;

	cin >> circulo.radio >> c;
	circulo.centro = LeerPunto();

	return circulo;
}

// FIXME: Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(Circulo c)
{
	cout << c.radio << '-';
	EscribirPunto(c.centro);
}

// FIXME: Función para controlar el flujo de entrada de círculos:
bool Leer(istream& is, Circulo& c)
{
	char a;

	return is >> c.radio >> a >> a >> c.centro.x >> a >> c.centro.y >> a;	
}

// FIXME: Función para controlar el flujo de salida de círculos:
bool Escribir(ostream& os, Circulo& c)
{
	return os << c.radio << "-(" << c.centro.x << "," << c.centro.y << ")";	
}

// FIXME: Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, Punto centro, double radio)
{
	c.radio = radio;
	c.centro = centro;	
}

// FIXME: Devuelve del centro de c
Punto Centro (Circulo c)
{
	return c.centro;
}

// FIXME: Devuelve el radio de c
double Radio (Circulo c)
{
	return c.radio;
}

// FIXME: Devuelve el área del círculo c
double Area (Circulo c)
{
	double area;
	area = M_PI*c.radio*c.radio;

	return area;
}

// FIXME: Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (Punto p, Circulo c)
{
	return Distancia(c.centro, p) < c.radio;
}

// FIXME: Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (Circulo c1, Circulo c2)
{
	double distancia;
	
	distancia = Distancia(c1.centro, c2.centro) - c1.radio - c2.radio;

	return distancia;
}
