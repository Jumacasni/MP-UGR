#ifndef _JUGADOR_
#define _JUGADOR_

	#include "tablero.h"

	class Jugador {
		private:
			char* nombre;
			int n_jugador;
			int puntuacion;
			int ganadas;
			
		public:
			
			Jugador(char* v, int num_jugador);
			Jugador(const Jugador& j);
			Jugador& operator=(const Jugador& j);
			~Jugador();
			void Puntuacion(Tablero& t);
			void ActualizarGanadas();
			bool EscogeColumna(Tablero& t) const;
			const char* Nombre() const;
			int Ganadas() const;
			int Puntuacion() const;
			friend std::ostream& operator<<(std::ostream& os, const Jugador& j);
			friend std::istream& operator>>(std::istream& is, Jugador& j);
	}; 

#endif


