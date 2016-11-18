#include <iostream>
#include "tablero.h"

using namespace std;

Tablero::Tablero(int f, int c, int fichas, int introducir):m(f,c) {
	nfichas = fichas;
	pfinalizada = false;
	turno = 1;
	ganador = 0;
	puntuacion_tab = 0;
	fichas_introducir = introducir;
}

int Tablero::Filas() const{
	return m.filas();
}

int Tablero::Columnas() const{
	return m.columnas();
}

int Tablero::FichasIntroducir() const{
	return fichas_introducir;
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

int Tablero::Insertar(char c, bool cambia_turno) {
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
	
	if(turno == 1 && cambia_turno)
		turno = 2;
		
	else if(turno == 2 && cambia_turno)
		turno = 1;
	
	return 0;
}

void Tablero::Reinicia() {
	
	// Comprobación de quién empieza:
	
	int num_turnos= 0;
		for(int z=0; z<Filas(); ++z)
			for(int j=0; j<Columnas(); ++j)
				if(Posicion(z,j)!=0)
					num_turnos++;
	if(num_turnos % 2 == 0) {
		if(turno == 1)
			turno = 2;
		else
			turno = 1;
	
	}
	
	for(int i=0; i<Filas(); ++i)
		for(int j=0; j<Columnas(); ++j)
			m.modificar(i,j,0);

	pfinalizada = false;
	ganador = 0;
	puntuacion_tab = 0;
}

void Tablero::ImprimeTablero(ostream& os) const {
	char columna = 'a';
	
	os << "   ";
	for(int i=0; i<Columnas(); ++i)
		os << columna++ << " ";
	os << endl;

	for(int i=0; i<Filas(); ++i) {
		os << "  ";  
		for(int j=0; j<Columnas(); ++j) {
			os << "\e[1;30m|\e[0m";

			if(Posicion(i,j) == 1)
				os << "\e[1;31mX\e[0m";
			else if(Posicion(i,j) == 2)
				os << "\e[1;33mO\e[0m";
			else 
				os << " ";
		
		}
		os << "\e[1;30m|\e[0m" << endl;
	}

	cout << "  ";
	for(int i=0; i<=2*Columnas(); ++i)
		os << "\e[1;30m=\e[0m";
	os << endl;
}

int Tablero::GetPuntuacion() const{
	return puntuacion_tab;
}

ostream& operator<<(ostream& os, const Tablero& t){
	os << t.m;
	os << t.nfichas << " " << t.puntuacion_tab << " " << t.ganador
	   << " " << t.pfinalizada << " " << t.turno << " " << t.fichas_introducir;
	
	return os;
}

istream& operator>>(istream& is, Tablero& t){
	Matriz m(0,0);
	int num_fichas, t_turno, puntuacion, t_ganador, t_introducir;
	bool p_finalizada;
	
	is >> m;
	is >> num_fichas >> puntuacion >> t_ganador >> p_finalizada >> t_turno >> t_introducir;
	t = Tablero(m.filas(), m.columnas(), num_fichas, t_introducir);

	for (int i=0; i < m.filas(); ++i)
		for(int j=0; j < m.columnas(); ++j)
			t.m.modificar(i,j, m.elemento(i,j));
			
	return is;
}
