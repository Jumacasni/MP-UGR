#include <iostream>
#include <fstream>
#include <cstring> // strcmp, strlen

using namespace std;

struct ListadoNombres {
   char** cadenas;
   int ncads;
};

char* LeerLinea(istream& flujo)
{
	char *p;
	char aux[1024];

	if(flujo.getline(aux,1024)){
		int n = strlen(aux);
		p = new char [n];
		for(int i = 0; i < n; ++i)
			p[i] = aux[i];
	}
	
	return p;
}

void AddLineas(istream& is, ListadoNombres& l)
{
	
	while(is){
		char *palabra = LeerLinea(is);
		char** p = new char*[l.ncads+1];

		for(int i = 0; i < l.ncads; i++){
			p[i] = l.cadenas[i];
		}
		delete[] l.cadenas;

		l.cadenas = p;
		l.cadenas[l.ncads] = new char [strlen(palabra)];

		l.cadenas[l.ncads] = palabra;


		l.ncads++;
	}
}

// Función auxiliar para OrdenarShell
int CalcularSaltoInicial(int n)
{
   int salto= 1;
   while (salto<n/9)
      salto= salto*3+1;
   return salto;
}
// FIXME 3: Implementar la función OrdenarShell
// cmp es como strcmp (devuelve un entero negativo, cero o positivo)
// Consultar OrdenarShell para enteros, que se ha entregado resuelta
void OrdenarShell(ListadoNombres, int strcmp)
{
;
}
// FIXME 4: Crear una función que lista las líneas de un ListadoNombres (ver main)
void Mostrar(ostream& os, ListadoNombres l)
{
	for(int i = 0; i < l.ncads-1; ++i)
		os << l.cadenas[i] << endl;
}

// FIXME 5: Crear una función que libera un ListadoNombres (ver main)
void Liberar(ListadoNombres l)
{
	for(int i = 0; i < l.ncads; ++i)
		delete[] l.cadenas[i];
	delete[] l.cadenas;
}

// La función main esta terminada, no se debe tocar
int main(int argc, char* argv[])
{
   ListadoNombres listado= {0,0};
   bool ordenar= false;
   
   if (argc==1)
      AddLineas(cin, listado);
   else if (argc==2) {
      ifstream f(argv[argc-1]);
      if (!f) {
         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
         return 1;
      }
      AddLineas(f, listado);
   }
   else  
   {
      cerr << "Uso: " << argv[0] << " [<fichero>]" << endl;
      return 1;
   }
	
	Mostrar(cout, listado);
 // Libera la memoria reservada
}  
