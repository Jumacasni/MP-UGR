#include <iostream>
#include "jugador.h"

using namespace std;

Jugador::Jugador(char* v, int num_jugador){
	int i;	
	for(i = 0; v[i] != '\0'; ++i)
		nombre[i] = v[i];
	nombre[i] = '\0';
	n_jugador = num_jugador;
	puntuacion = 0;
	ganadas = 0;
}

void Jugador::Puntuacion(Tablero& t) {
	t.Tpuntuacion();
	puntuacion = puntuacion + t.GetPuntuacion();
}

void Jugador::ActualizarGanadas() {
	ganadas = ganadas + 1;
}

void Jugador::EscogeColumna(Tablero& t) const{
	char c;

	t.ImprimeTablero();	

	cout << "Turno: jugador ";
	if (t.Turno() == 1)
		cout << "1: (\e[1;31mX\e[0m) ";
	else
		cout << "2: (\e[1;33mO\e[0m) ";

	cout << Nombre() << ", introduzca una columna: ";
	cin >> c;
	
	while(0 > (c-'a') || (c-'a') > (t.Columnas()-1)){	
		cout << nombre << ", introduzca una columna válida: ";
		cin >> c;
	}

	while(t.Insertar(c) == 1){
		cout << nombre << ", introduzca una columna válida: ";
		cin >> c;			
	}
}

const char* Jugador::Nombre() const{
	return nombre;
}

int Jugador::Ganadas() const{
	return ganadas;
}

int Jugador::Puntuacion() const{
	return puntuacion;
}
