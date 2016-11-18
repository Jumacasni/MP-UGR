#ifndef _JUGADOR_
#define _JUGADOR_

	#include "tablero.h"

	class Jugador {
		private:
			char nombre[50];
			int n_jugador;
			int puntuacion;
			int ganadas;
			
		public:
			
			Jugador(char* v, int num_jugador);
			void Puntuacion(Tablero& t);
			void ActualizarGanadas();
			void EscogeColumna(Tablero& t) const;
			const char* Nombre() const;
			int Ganadas() const;
			int Puntuacion() const;
	};

#endif


