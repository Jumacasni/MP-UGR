#ifndef _TABLERO_
#define _TABLERO_

	#include "matriz.h"

	class Tablero{
		private:
			Matriz m;
			int nfichas;
			bool pfinalizada;
			int ganador;
			int turno;
			int puntuacion_tab;

		public:
			Tablero(int f, int c, int fichas);
			int Filas() const;
			int Columnas() const;
			int Posicion(int f, int c) const;
			bool Pfinalizada() const;
			int Turno() const;
			int Ganador() const;
			void Tpuntuacion();
			int Insertar(char c);
			void Reinicia();
			void ImprimeTablero() const;
			int GetPuntuacion() const;
	};

#endif
