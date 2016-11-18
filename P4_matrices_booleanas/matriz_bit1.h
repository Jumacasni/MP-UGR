/* Archivo de cabecera de matriz_bit1.
*/

#ifndef _MATRIZ_BIT1_H
#define _MATRIZ_BIT1_H

struct MatrizBit{
	
	int f, c;
	bool matriz[10][10];
};

bool Inicializar(MatrizBit& m, int fils, int cols);
int Filas (const MatrizBit& m);
int Columnas( const MatrizBit& m);
bool Get(const MatrizBit& m, int f, int c);
void Set(MatrizBit& m, int f, int c, bool v);

#endif
