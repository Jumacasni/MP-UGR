#include "matriz.h"

Matriz::Matriz(int filas, int columnas){
	f = filas;
	c = columnas;
	for (int i=0; i<f; ++i)
		for(int j=0; j<c; ++j)
			m[i][j] = 0;
}


int Matriz::filas() const {
	return f;
}

int Matriz::columnas() const {
	return c;
}

int Matriz::elemento(int f, int c) const {
	return m[f][c];
}

void Matriz::modificar(int f, int c, int dato){
	m[f][c] = dato;
}

