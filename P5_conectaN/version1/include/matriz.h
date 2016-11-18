#ifndef _MATRIZ_
#define _MATRIZ_

	class Matriz {
		private:
			int m[20][20];
			int f, c;

		public:
			Matriz(int filas, int columnas);
			int filas() const;
			int columnas() const;
			int elemento(int f, int c) const; 
			void modificar(int f, int c, int dato);
	};

#endif
