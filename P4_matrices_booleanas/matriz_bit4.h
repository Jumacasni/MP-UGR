#ifndef _MATRIZ_BIT4_H
#define _MATRIZ_BIT4_H

struct MatrizBit
{

	unsigned int matriz[4];
	unsigned short int tamanio;
};

bool Inicializar(MatrizBit& m, int fils, int cols);
int Filas (const MatrizBit& m);
int Columnas (const MatrizBit& m);
bool Get(const MatrizBit& m, int fils, int cols);
void Set(MatrizBit& m, int fils, int cols, bool v);

#endif
