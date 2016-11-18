/* 
Primera representación de una matriz: 
Utilización de una matriz-C.
*/

#include "matriz_bit1.h"

// FIXME: Función para inicializar una matriz:

bool Inicializar(MatrizBit& m, int fils, int cols)
{

	bool sin_fallos = (fils <= 10) && (cols <= 10);

	if (sin_fallos)
	{
		m.f = fils;
		m.c = cols;
		for (int i = 0 ; i < m.f ; ++i)
			for (int j = 0 ; j < m.c ; ++j)
				m.matriz[i][j] = false;
	}

	return sin_fallos;
}

// FIXME: Función que devuelve el número de filas:

int Filas (const MatrizBit& m)
{
	return m.f;
}

// FIXME: Función que devuelve el número de columnas:

int Columnas( const MatrizBit& m)
{
	return m.c;
}

// FIXME: Función para obtener un elemento de la matriz:

bool Get(const MatrizBit& m, int f, int c)
{
	return m.matriz[f][c];
}

// FIXME: Función para establecer el un elemento de la matriz:

void Set(MatrizBit& m, int f, int c, bool v)
{
	m.matriz[f][c] = v;
}

