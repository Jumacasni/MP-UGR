#include "matriz.h"

using namespace std;

Matriz::Matriz(int filas, int columnas){
	datos = new int[filas*columnas];
	f = filas;
	c = columnas;
	for (int i=0; i<f*c; ++i)
		datos[i] = 0;
}

Matriz::Matriz(const Matriz& m){
	datos = new int[m.f*m.c];
	f = m.f;
	c = m.c;
	for (int i=0; i<m.f*m.c; ++i)
		datos[i] = m.datos[i];
}

Matriz& Matriz::operator=(const Matriz& m){
	if(f*c != m.f*m.c){
		delete[] datos;
		datos = new int[m.f*m.c];
	}
	
	f = m.f;
	c = m.c;
	for (int i=0; i < m.f*m.c; ++i)
		datos[i] = m.datos[i];

	return *this;
}

istream& operator>>(istream& is, Matriz& m){
	int f, c, dato;
		is >> f >> c;
	if(f > 0 && c > 0){
		m = Matriz(f,c);
		for(int i=0; i<m.filas(); ++i)
			for(int j=0; j<m.columnas(); ++j){
				is >> dato;
				m.modificar(i,j,dato);
			}
	}
	return is;
}
		

ostream& operator<<(ostream& os, const Matriz& m){
	os << m.filas() << " " << m.columnas() << endl;
	for(int i=0; i<m.filas(); ++i) {
		for(int j=0; j<m.columnas(); ++j)
			os << m.elemento(i,j) << " ";
		os << endl;
	}
	return os;
}


Matriz::~Matriz (){
	delete[] datos;
}

int Matriz::filas() const {
	return f;
}

int Matriz::columnas() const {
	return c;
}

int Matriz::elemento(int f, int c) const {
	return datos[f*columnas()+c];
}

void Matriz::modificar(int f, int c, int dato){
	datos[f*columnas()+c] = dato;
}

