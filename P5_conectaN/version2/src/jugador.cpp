#include <iostream>
#include <cstdlib>
#include <cstring>
#include "jugador.h"

using namespace std;

Jugador::Jugador(char* v, int num_jugador){
	int i;
	int longitud = strlen(v);
	nombre = new char[longitud];
	for(i = 0; i < longitud; ++i)
		nombre[i] = v[i];
	nombre[i] = '\0';
	n_jugador = num_jugador;
	puntuacion = 0;
	ganadas = 0;
}

Jugador::Jugador(const Jugador& j){
	int longitud = strlen(j.nombre);

	nombre = new char[longitud];
	n_jugador = j.n_jugador;
	puntuacion = j.puntuacion;
	ganadas = j.puntuacion;
	
	for (int i=0; i<longitud; ++i)
		nombre[i] = j.nombre[i];
}

Jugador& Jugador::operator=(const Jugador& j){
	int longitud = strlen(j.nombre);

	if(strlen(nombre) != strlen(j.nombre)){
		delete[] nombre;
		nombre = new char[strlen(j.nombre)];
	}
	n_jugador = j.n_jugador;
	puntuacion = j.puntuacion;
	ganadas = j.puntuacion;
	
	for (int i=0; i < longitud; ++i)
		nombre[i] = j.nombre[i];

	return *this;
}

Jugador::~Jugador(){
	delete[] nombre;
}

void Jugador::Puntuacion(Tablero& t) {
	t.Tpuntuacion();
	puntuacion = puntuacion + t.GetPuntuacion();
}

void Jugador::ActualizarGanadas() {
	ganadas = ganadas + 1;
}

bool Jugador::EscogeColumna(Tablero& t) const{
	char c;
	int f_introducidas = 1;
	bool cambia_t = false;
	
	t.ImprimeTablero();
	
	if(*nombre == '@') {
		cout << "Turno: jugador ";
		if (t.Turno() == 1)
			cout << "1: (\e[1;31mX\e[0m) ";
		else
			cout << "2: (\e[1;33mO\e[0m) ";
		
		while(f_introducidas <= t.FichasIntroducir()){
			cout << Nombre() << " ha introducido una columna para la ficha " << f_introducidas 
				 << " de " << t.FichasIntroducir() << endl;
			
			// Generar una columna aleatoria:

			int numero = rand () % ((t.Columnas()-1)+1);
			c = numero + 'a';
			
			if(f_introducidas == t.FichasIntroducir())
				cambia_t = true;
			
			if(t.Insertar(c,cambia_t) == 1)
				return false;
			
			f_introducidas++;
			
			if(!cambia_t)
				t.ImprimeTablero();
		}
	}
	
   else {
		cout << "Turno: jugador ";
		if (t.Turno() == 1)
			cout << "1: (\e[1;31mX\e[0m) ";
		else
			cout << "2: (\e[1;33mO\e[0m) ";
		
		while(f_introducidas <= t.FichasIntroducir()){
			
			cout << Nombre() << ", introduzca una columna para la ficha " << f_introducidas 
				 << " de " << t.FichasIntroducir() << ": ";
			cin >> c;
			cout << endl;

			if (0 > (c-'a') || (c-'a') > (t.Columnas()-1))
				return false;

			if(f_introducidas == t.FichasIntroducir())
				cambia_t = true;

			if(t.Insertar(c,cambia_t) == 1)
				return false;
			
			f_introducidas++;
			
			if(!cambia_t)
				t.ImprimeTablero();
		}
   }

	return true;
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

ostream& operator<<(ostream& os, const Jugador& j){
	os << '#' << j.nombre << endl;
	os << j.n_jugador << " " << j.puntuacion << " " << j.ganadas << endl;
	
	return os;
}

istream& operator>>(istream& is,  Jugador& j){
	char nombre[50];
	int num_jugador, punt, p_ganadas;
	
	while(is.peek() != '#')
		is.ignore();
	is.ignore();
	
	is >> nombre >> num_jugador >> punt >> p_ganadas;
	j = Jugador(nombre, num_jugador);
	j.puntuacion = punt;
	j.ganadas = p_ganadas;
	
	return is;
}
