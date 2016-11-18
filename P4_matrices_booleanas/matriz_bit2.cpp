/* Segunda representación de una matriz utilizando un vector-C
*/

#include "matriz_bit2.h"

// Función para inicializar una matriz:

bool Inicializar(MatrizBit& m, int fils, int cols)
{

	if ((fils * cols) < 100)
	{
		for (int i = 0; i < (fils * cols) ; ++i)
		{
			m.matriz[i] = false;
		}
		m.f = fils;
		m.c = cols;
		return true;
	}
	else
		return false;
}

// Función que devuelve el número de filas:

int Filas (const MatrizBit& m)
{
	return m.f;
}

// Función que devuelve el número de columnas:

int Columnas (const MatrizBit& m)
{
	return m.c;
}

// Función para obtener un elemento de la matriz:

bool Get(const MatrizBit& m, int fils, int cols)
{
	return m.matriz[fils * Columnas(m) + cols];
}

// Función para establecer el un elemento de la matriz:

void Set(MatrizBit& m, int fils, int cols, bool v)
{
	m.matriz[fils * Columnas(m) + cols] = v;
}
