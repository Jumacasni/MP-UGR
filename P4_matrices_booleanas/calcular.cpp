/* 
Programa para trabajar con matrices introduciendo diversas
opciones.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "matriz_operaciones.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	MatrizBit m1, m2, res;

	if (argc == 1)
	{
		cerr << "Error: Introduzca un argumento." << endl;
		return 1;
	}
	else if(argc == 2)
	{
	
		if(strcmp(argv[1], "AND") == 0)
		{
			Leer(cin, m1);
			Leer(cin, m2);
			And(res, m1, m2);
		}
		else if(strcmp("OR", argv[1]) == 0)
		{
			Leer(cin, m2);
			Or(res, m1, m2);
		}
		else if(strcmp(argv[1], "NOT") == 0){
			Leer(cin, m1);
			Not(res, m1);
		}	
		else{
			Leer(cin, m1);
			Traspuesta(res, m1);
		}
	
		Escribir(cout, res);
	}
	else if(argc == 3)
	{
		Leer(argv[2], m1);	
			
		if(strcmp("AND", argv[1]) == 0)
		{
			Leer(cin, m2);
			And(res, m1, m2);
		}
		else if(strcmp("OR", argv[1]) == 0)
		{
			Leer(cin, m2);
			Or(res, m1, m2);
		}
		else if(strcmp("NOT", argv[1]) == 0)
			Not(res, m1);
		else 
			Traspuesta(res, m1);

		Escribir(cout, res);
	}
	else if(argc == 4)
	{
		Leer(argv[2], m1);

		if(strcmp("AND", argv[1]) == 0)
		{
			Leer(argv[3], m2);
			And(res, m1, m2);
		}
		else if(strcmp("OR", argv[1]) == 0)
		{
			Leer(argv[3], m2);
			Or(res, m1, m2);
		}
		else if(strcmp("NOT", argv[1]) == 0)
			Not(res, m1);
		else 
			Traspuesta(res, m1);

		Escribir(cout, res);
	}
	else
		cerr << "Error: Demasiados argumentos." << endl;
}


