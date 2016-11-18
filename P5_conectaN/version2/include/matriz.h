#ifndef _MATRIZ_
#define _MATRIZ_
#include <iostream>

	class Matriz {
		private:
			int* datos;
			int f, c;

		public:
			Matriz(int filas, int columnas);
			Matriz(const Matriz& m);
			Matriz& operator=(const Matriz& m);
			~Matriz();
			int filas() const;
			int columnas() const;
			int elemento(int f, int c) const; 
			void modificar(int f, int c, int dato);
			friend	std::istream& operator>>(std::istream& is, Matriz& m);
			friend	std::ostream& operator<<(std::ostream& os, const Matriz& m);	
		
	};

#endif
