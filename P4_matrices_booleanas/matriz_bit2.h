#ifndef _MATRIZ_BIT2_H
#define _MATRIZ_BIT2_H

struct MatrizBit
{
	bool matriz[100];
	int f;
	int c;
};

bool Inicializar(MatrizBit& m, int fils, int cols);
int Filas (const MatrizBit& m);
int Columnas (const MatrizBit& m);
bool Get(const MatrizBit& m, int fils, int cols);
void Set(MatrizBit& m, int fils, int cols, bool v);

#endif
