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
			int fichas_introducir;

		public:
			Tablero(int f, int c, int fichas, int introducir);
			int Filas() const;
			int Columnas() const;
			int Posicion(int f, int c) const;
			bool Pfinalizada() const;
			int Turno() const;
			int FichasIntroducir() const;
			int Ganador() const;
			void Tpuntuacion();
			int Insertar(char c, bool cambia_turno);
			void Reinicia();
			void ImprimeTablero(std::ostream& os=std::cout) const;
			int GetPuntuacion() const;
			friend	std::ostream& operator<<(std::ostream& os, const Tablero& t);
			friend	std::istream& operator>>(std::istream& is, Tablero& t);
	};

#endif
