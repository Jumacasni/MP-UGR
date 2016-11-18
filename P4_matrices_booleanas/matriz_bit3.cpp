/* Tercera representación de una matriz utilizando un vector-C
*/

#include "matriz_bit3.h"
#include <iostream>
// Función para inicializar una matriz:

bool Inicializar(MatrizBit& m, int fils, int cols)
{
	m.tamanio = 0;

	if ((fils * cols) < 100)
	{
		m.tamanio = (fils<<16) | cols;

		for (int i = 0 ; i < (fils * cols) ; ++i)
			m.matriz[i] = '0';
		
		return true;
	}
	else 
		return false;
}

// Función que devuelve el número de filas:

int Filas (const MatrizBit& m)
{
	int filas;

	filas = (m.tamanio>>16) & 0xFFFF;
	
	return filas;
}

// Función que devuelve el número de columnas:

int Columnas( const MatrizBit& m)
{
	int columnas;

	columnas = m.tamanio & 0xFFFF;

	return columnas;

}

// Función para obtener un elemento de la matriz;

bool Get(const MatrizBit& m, int f, int c)
{
	return m.matriz[(f * Columnas(m)) + c];
}

// Función para establecer el un elemento de la matriz:

void Set(MatrizBit& m, int f, int c, bool v)
{
	m.matriz[(f * Columnas(m)) + c] = v;
}
