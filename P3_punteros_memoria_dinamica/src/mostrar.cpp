#include <iostream>
#include <fstream> // ifstream
#include <cstring>

using namespace std;

struct VecDin {
   int *datos;
   int usados;
	int reservados;
};

void ReSize(VecDin& v,int nuevo)
{
	int min = nuevo;
	int *p;

	if (nuevo > v.reservados)
	{
		if (nuevo > v.usados)
			min = v.usados;

		p = new int [nuevo];
		v.reservados = nuevo;

		for (int i = 0; i < min; ++i)
			p[i] = v.datos[i];

		delete[] v.datos;

		v.usados = nuevo;
		v.datos = p;

	}
	
	else
		v.usados = nuevo;
}

VecDin LeerVecDin(istream& flujo)
{
	VecDin v = {0,0,0};
	int a;

	while(isspace(flujo.peek()))
		flujo.ignore();

	while (flujo >> a)
	{
		ReSize(v, (v.usados)+1);
		v.datos[(v.usados)-1] = a;
	}

	return v;
}

void Mostrar(const VecDin& v, std::ostream& os)
{
		for(int i = 0; i < v.usados; ++i)
			os << v.datos[i] << " ";
		os << endl;
}

void Liberar(VecDin& v)
{
	
	delete[] v.datos;
}

void Add(VecDin& v,int dato)
{
	if (v.usados < v.reservados)
		ReSize(v, (v.usados)+1);

	else
	{
		ReSize(v, 2*v.usados);
		ReSize(v, v.usados/2+1);
	}

	v.datos[v.usados-1] = dato;
}

void SeleccionRecursivo(int *v, int n)
{
	int min = *v;
	int *p = v;
	int *posicion = v;
	int aux;
	
	for(; p < v+n ; p++)
	{
		if (*p < min)
		{
			min = *p;
			posicion = p;
		}
	}
	
	aux = min;
	*posicion = *v;
	*v = aux;
	
	if(n-- > 1)
		SeleccionRecursivo(++v, n--);
}

void Ordenar(VecDin& v)
{
	SeleccionRecursivo(v.datos, v.usados);
}

int main(int argc, char *argv[])
{
   VecDin v= {0,0};
   
   if (argc==1)
      v= LeerVecDin(cin);
		else if (argc==2)
		{
		   ifstream f(argv[1]);
		   if (!f) {
		      cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
		      return 1;
		   }
		   v= LeerVecDin(f);
		}

			else if (argc==3)
			{
				if (strcmp(argv[1],"-s") == 0)
				{
					ifstream f(argv[2]);
					if (!f) {
						cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
						return 1;
					}
					v = LeerVecDin(f);
					Ordenar(v);
				}
				else
				{	
					cout << "Introduzca un argumento válido" << endl;
					return 1;
				}
			}

	else
	{
		cout << "Demasiados argumentos" << endl;
		return 1;
	}
			

   Mostrar(v,cout);
   Liberar(v); // Libera la memoria reservada
}  
