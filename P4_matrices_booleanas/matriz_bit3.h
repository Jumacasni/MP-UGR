#ifndef _MATRIZ_BIT3_H
#define _MATRIZ_BIT3_H

struct MatrizBit
{

	char matriz[100];
	unsigned int tamanio;
};

bool Inicializar(MatrizBit& m, int fils, int cols);
int Filas (const MatrizBit& m);
int Columnas (const MatrizBit& m);
bool Get(const MatrizBit& m, int fils, int cols);
void Set(MatrizBit& m, int fils, int cols, bool v);

#endif
