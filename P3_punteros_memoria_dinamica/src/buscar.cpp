#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time

using namespace std;

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
   double u01= std::rand()/(RAND_MAX+1.0); // Uniforme01
   return minimo+(maximo-minimo+1)*u01;
}

void Generar(int *&v, const int n, const int max)
{
	for (int i = 0; i < n; ++i)
		v[i] = Uniforme(0, i%max+1);
}

int Buscar(const int *v, int n, int dato)
{
   for (int i=0;i<n;++i)
      if (v[i]==dato)
         return i;
   return n;
}

int* BuscarGarantizada(int *inicial, int dato)
{
	int i = 0;
	while(*inicial!=dato)
		inicial++;
	
	return inicial;
}

void OrdenarInsercion(int *v, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int a = v[i];
		int b = i - 1;
		while (a < v[b] && b >= 0)
		{
			v[b+1] = v[b];
			b--;
		}
		v[b+1] = a;
	}
}

int BusquedaBinariaRec(int *v, int i, int s, int dato)
{
	int centro = i + (s-i) / 2;
	if (i > s)
		return -1;
		else if (v[centro] > dato)
			BusquedaBinariaRec(v,i,centro-1,dato);
				else if (v[centro] < dato)
						BusquedaBinariaRec(v,centro+1,s,dato);
						else
							return centro;

}

int BusquedaBinariaInterp(int *vec, int n, int dato)
{
	int izq= 0, der= n-1;
	while (izq<=der) {
		int pos = izq + ((dato - vec[izq])/(vec[der] - vec[izq])) * (der-izq);
		if (vec[pos] > dato)
			der= pos-1;
		else if (vec[pos] < dato)
					izq= pos+1;
				else return pos;
	}

	return -1;
}

int BusquedaBinaria (int *vec, int n, int dato)
{
	int izq= 0, der= n-1;
	while (izq<=der) {
		int centro= (izq+der) / 2;
		if (vec[centro] > dato)
			der= centro-1;
		else if (vec[centro] < dato)
					izq= centro+1;
				else return centro;
	}

	return -1;
}

int main(int argc, char *argv[])
{
   if (argc!=3) {
      cerr << "Uso: " << argv[0] << " <número de datos> <máximo dato>" <<endl;
      return 1;
   }
   
   srand(time(0)); // Inicializamos generador de números

   int n= atoi(argv[1]);
   if (n<5) {
      cerr << "Debería especificar al menos 5 elementos" << endl;
      return 2;
   }
   else {
      
      int *v = new int [n+1];
      int max = atoi(argv[2]);
      Generar(v,n,max);
      cout << "Generados: ";
      for (int i=0;i<n;++i)
         cout << v[i] << " "; 
      cout << endl;
      OrdenarInsercion(v,n);
		cout << "Ordenados: ";
		for (int i=0;i<n;++i)
			cout << v[i] << " "; 
		cout << endl;

      int a_buscar;
      cout << "Introduzca un dato a buscar: ";
		cin >> a_buscar;
		v[n] = a_buscar;
		int* pos = BuscarGarantizada(v,a_buscar);
		cout << "Encontrado en: " << pos-v << endl;
		while(pos < v+n)
		{
			pos = BuscarGarantizada(pos+1,a_buscar);
			if(pos != v+n)
				cout << "Encontrado en: " << pos-v << endl;		
      }
		
		cout << "Introduzca un dato a buscar binario: ";
		cin >> a_buscar;
		cout << "Encontrado en: " << BusquedaBinariaRec(v,0,n,a_buscar) << endl;
		cout << "Encontrado en: " << BusquedaBinariaInterp(v,n,a_buscar) << endl;
      
      delete[] v;
      
   }
}
  
  
