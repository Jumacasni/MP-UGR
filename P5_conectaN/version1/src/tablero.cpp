#include <iostream>
#include "tablero.h"

using namespace std;

Tablero::Tablero(int f, int c, int fichas):m(f,c) {
	nfichas = fichas;
	pfinalizada = false;
	turno = 1;
	ganador = 0;
	puntuacion_tab = 0;
}

int Tablero::Filas() const{
	return m.filas();
}

int Tablero::Columnas() const{
	return m.columnas();
}

int Tablero::Posicion(int f, int c) const{
	if (f<0 || f>=Filas() || c<0 || c>=Columnas())
		return 0;
	
	return m.elemento(f,c);
}

bool Tablero::Pfinalizada() const{
	return pfinalizada;
}

int Tablero::Turno() const{
	return turno;
}

int Tablero::Ganador() const {
	if(pfinalizada)
		return ganador;
	return 0;
}

void Tablero::Tpuntuacion() {
	int num_turnos, k=0;
	int dim_tablero = Filas() * Columnas();

	for(int i=0; i<Filas(); ++i)
		for(int j=0; j<Columnas(); ++j)
			if(Posicion(i,j) == 0)
				k++;
	
	num_turnos = dim_tablero - k;

	if(num_turnos <= dim_tablero/2)
		puntuacion_tab = 200;
	else
		puntuacion_tab = 100;
}

int Tablero::Insertar(char c) {
	int pos = c - 'a';	
	int i = Filas()-1;
	bool introducido = false;
	
	while (i >= 0 && !introducido){
		if(Posicion(i,pos) == 0) {
			m.modificar(i,pos,turno);
			introducido = true;
		}
		else
			i--;
	}

	if(!introducido)
		return 1;

	// Comprobación de si ha finalizado la partida o no:
	// Vertical:

	int k= 0, j = i;
	while(j < Filas() && Posicion(j,pos) == turno) {
		k++;
		j++;
	}
	if(k == nfichas) {
		ganador = turno;
		pfinalizada = true;
	}
	
	// Horizontal:
	
	if(!pfinalizada) {
		k=1; 
		int izq=1, der=1;
	
		while((Posicion(i,pos+der) == turno) || (Posicion(i,pos-izq) == turno)) {
			if((pos+der) < Columnas() && Posicion(i,pos+der) == turno){
				k++;
				der++;
			}
			if((pos-izq) >= 0 && Posicion(i,pos-izq) == turno){
				k++;
				izq++;
			}
		}
		if(k == nfichas) {
			ganador = turno;
			pfinalizada = true;
		}
	}

	// Diagonal sentido 1:

	if(!pfinalizada) {
		k=1;
		int izq=1, der=1;

		while(Posicion(i+der,pos+der) == turno || Posicion(i-izq,pos-izq) == turno) {
			if((i+der) < Filas() && (pos+der) < Columnas() && Posicion(i+der,pos+der) == turno){
				k++;
				der++;
			}
			if((i-izq) >= 0 && (pos-izq) >= 0 && Posicion(i-izq,pos-izq) == turno){
				k++;
				izq++;
			}
		}
		if(k == nfichas) {
			ganador = turno;
			pfinalizada = true;
		}	
	}

	// Diagonal sentido 2:

	if(!pfinalizada) {
		k=1;
		int izq=1, der=1;

		while(Posicion(i-der,pos+der) == turno || Posicion(i+izq,pos-izq) == turno) {
			if((i-der) >= 0 && (pos+der) < Columnas() && Posicion(i-der,pos+der) == turno){
				k++;
				der++;
			}
			if((i+izq) < Filas() && (pos-izq) >= 0 && Posicion(i+izq,pos-izq) == turno){
				k++;
				izq++;
			}
		}
		if(k == nfichas) {
			ganador = turno;
			pfinalizada = true;
		}
	}

	// Comprobacion de empate:

	if(i == 0){
		int vacios = 0;
		for(int z=0; z<Filas(); ++z)
			for(int j=0; j<Columnas(); ++j)
				if(Posicion(z,j)==0)
					vacios++;
		
		if(vacios == 0){
			ganador = 0;
			pfinalizada = true;
		}		

	}

	// Cambio de turno:
	
	if(turno == 1)
		turno = 2;
	else
		turno = 1;
	
	return 0;
}

void Tablero::Reinicia() {
	
	for(int i=0; i<Filas(); ++i)
		for(int j=0; j<Columnas(); ++j)
			m.modificar(i,j,0);

	pfinalizada = false;
	turno = 1;
	ganador = 0;
	puntuacion_tab = 0;
}

void Tablero::ImprimeTablero() const {
	char columna = 'a';
	
	cout << "   ";
	for(int i=0; i<Columnas(); ++i)
		cout << columna++ << " ";
	cout << endl;

	for(int i=0; i<Filas(); ++i) {
		cout << "  ";  
		for(int j=0; j<Columnas(); ++j) {
			cout << "\e[1;30m|\e[0m";

			if(Posicion(i,j) == 1)
				cout << "\e[1;31mX\e[0m";
			else if(Posicion(i,j) == 2)
				cout << "\e[1;33mO\e[0m";
			else 
				cout << " ";
		
		}
		cout << "\e[1;30m|\e[0m" << endl;
	}

	cout << "  ";
	for(int i=0; i<=2*Columnas(); ++i)
		cout << "\e[1;30m=\e[0m";
	cout << endl;
}

int Tablero::GetPuntuacion() const{
	return puntuacion_tab;
}
