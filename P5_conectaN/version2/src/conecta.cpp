#include <fstream>
#include <cctype>
#include <cstring>
#include "jugador.h"

using namespace std;

bool Cargar(char* archivo, Jugador& j1, Jugador& j2, Tablero& t){
		char cabecera[50];
		ifstream f;
		f.open(archivo);
		f.getline(cabecera,50);
		
		if(strcmp(cabecera,"#MP-CONECTAN-1.0")==0){
			f >> j1 >> j2 >> t;
			return 0;
		}
		else
			return 1;
}

void DialogoSalvar(Jugador& j1, Jugador& j2, Tablero& t){
	char respuesta;
	
	cout << "¿Quiere guardar la partida? (S/N): ";
	cin >> respuesta;
	respuesta = toupper(respuesta);
	
	while(respuesta != 'S' && respuesta != 'N') {
		cout << "Introduzca S/N: ";
		cin >> respuesta;
		respuesta = toupper(respuesta);
	}
		
	if(respuesta == 'S'){
		cout << "Introduzca el nombre el archivo: ";
		char archivo[50];
		cin.ignore(100,'\n');
		cin.getline(archivo,50);
		
		fstream f(archivo, ios::in|ios::out|ios::trunc);
		
		f << "#MP-CONECTAN-1.0" << endl;
		f << j1 << j2 << t;

	}
}

int main(int argc, char* argv[1])
{
	if(argc == 1){
		int f, c, fichas, min, f_alinear;
		char respuesta;

		cout << "Introduzca filas (4-20): ";
		cin >> f;
		while(f < 4 || f > 20)
		{
			cout << "Introduzca filas (4-20): ";
			cin >> f;
		}
	
		cout << "Introduzca columnas (4-20): ";
		cin >> c;
		while(c < 4 || c > 20)
		{
			cout << "Introduzca columnas (4-20): ";
			cin >> c;
		}
	
		min = f;
		if(min > c)
			min = c;
	
		cout << "Introduzca fichas a alinear (3-" << min-1  << "): ";
		cin >> fichas;
	
		while (fichas < 3 || fichas > min-1)
		{
			cout << "Introduzca fichas a alinear (3-" << min-1  << "): ";
			cin >> fichas;
	                
		}
		
		cout << "Introduzca número de fichas por turno (1-" << fichas-2 <<"): ";
		cin >> f_alinear;
		
		while(f_alinear < 1 || f_alinear > fichas-2) {
			cout << "Introduzca número de fichas por turno (1-" << fichas-2 <<"): ";
			cin >> f_alinear;
		}
	
		cin.ignore(100,'\n');
	
		Tablero t(f,c,fichas,f_alinear);
		
		char jugador1[50], jugador2[50];
	
		cout << "Introduzca nombre del primer jugador: ";
		cin.getline(jugador1,50);
		cout << "Introduzca nombre del segundo jugador: ";	
		cin.getline(jugador2,50);
	
		Jugador j1(jugador1, 1);
		Jugador j2(jugador2, 2);

		do{
			while(t.Pfinalizada() == false) {
				if(t.Turno() == 1){
					if(!j1.EscogeColumna(t)) {
						cerr << "Error al insertar la ficha." << endl;
						DialogoSalvar(j1,j2,t);
					}
				}		
				else{
					if(t.Pfinalizada() == false)
						if(!j2.EscogeColumna(t)) {
							cerr << "Error al insertar la ficha." << endl;
							DialogoSalvar(j1,j2,t);
						}
				}
			}
			
			t.ImprimeTablero();
			cout << "Partida finalizada. Resultado: ";
			
			if (t.Ganador() == 1) {
				cout << "¡Ganador jugador 1!" << endl;
				j1.Puntuacion(t);
				j1.ActualizarGanadas();
			}
			else if (t.Ganador() == 2)
			{
				cout << "¡Ganador jugador 2!" << endl;
				j2.Puntuacion(t);
				j2.ActualizarGanadas();
			}
			else
				cout << "¡Empate!" << endl;
	
			cout << "Puntuación tras esta partida:" << endl;
			cout << "\t" << j1.Nombre() << ": " << j1.Ganadas() << " ganadas que acumulan " << j1.Puntuacion() << " puntos." << endl;
			cout << "\t" << j2.Nombre() << ": " << j2.Ganadas() << " ganadas que acumulan " << j2.Puntuacion() << " puntos." << endl;
			cout << "¿Jugar de nuevo (S/N)?: ";
			
			cin >> respuesta;
			respuesta = toupper(respuesta);
	
			while(respuesta != 'S' && respuesta != 'N') {
				cout << "Introduzca S ó N: ";
				cin >> respuesta;
				respuesta = toupper(respuesta);	
			}
	
			if(respuesta == 'S')
				t.Reinicia();
	
		}while(respuesta =='S');
	}
	else {
		char respuesta;
		char nombre[2];
		
		/* Para poder leer los datos necesitamos tener creados los objetos,
		como no tenemos constructor sin parámetros, le asignamos valores por defecto. */
		Jugador j1(nombre,1), j2(nombre,2);
		Tablero t(0,0,0,0);
		
		if(Cargar(argv[1], j1, j2, t)==1){
			cout << "Fichero no válido" << endl;
			return 1;
		}
			
		do{
			while(t.Pfinalizada() == false) {
				if(t.Turno() == 1){
					if(!j1.EscogeColumna(t)) {
						cerr << "Error al insertar la ficha." << endl;
						DialogoSalvar(j1,j2,t);
					}
				}
	
				else{
					if(t.Pfinalizada() == false){
						if(!j2.EscogeColumna(t)) {
							cerr << "Error al insertar la ficha." << endl;
							DialogoSalvar(j1,j2,t);
						}
					}
				}						
			}
			
			t.ImprimeTablero();
			cout << "Partida finalizada. Resultado: ";
			
			if (t.Ganador() == 1){
				cout << "¡Ganador jugador 1!" << endl;
				j1.Puntuacion(t);
				j1.ActualizarGanadas();
			}
			else if (t.Ganador() == 2)
			{
				cout << "¡Ganador jugador 2!" << endl;
				j2.Puntuacion(t);
				j2.ActualizarGanadas();
			}
			else
				cout << "¡Empate!" << endl;
	
			cout << "Puntuación tras esta partida:" << endl;
			cout << "\t" << j1.Nombre() << ": " << j1.Ganadas() << " ganadas que acumulan " << j1.Puntuacion() << " puntos." << endl;
			cout << "\t" << j2.Nombre() << ": " << j2.Ganadas() << " ganadas que acumulan " << j2.Puntuacion() << " puntos." << endl;
			cout << "¿Jugar de nuevo (S/N)?: ";
			
			cin >> respuesta;
			respuesta = toupper(respuesta);
	
			while(respuesta != 'S' && respuesta != 'N') {
				cout << "Introduzca S ó N: ";
				cin >> respuesta;
				respuesta = toupper(respuesta);	
			}
	
			if(respuesta == 'S')
				t.Reinicia();
	
		}while(respuesta =='S');
	}
}
