/* Programa para revelar un mensaje de una imagen. */

#include <iostream>
#include "codificar.h"

using namespace std;

int main()
{
	const int MAXBUFFER = 1000000;
	const int MAXNOMBRE = 100;
	const int TAMANIO = MAXBUFFER / 8;
	char nombre_imagen[MAXNOMBRE];
	char mensaje[TAMANIO];
	unsigned char buffer[MAXBUFFER];
	int f, c, resultado;
	TipoImagen tipo_imagen;
	
	// Lectura del nombre de la imagen:

	cout << "Introduzca la imagen de entrada: ";
	cin.getline(nombre_imagen, MAXNOMBRE);

	// Comprobación del formato de la imagen y lectura de la misma:

	tipo_imagen = LeerTipoImagen(nombre_imagen, f, c);
	
	if(tipo_imagen == IMG_DESCONOCIDO)
	{
		cerr << "Error: Formato de imagen no válido o imagen no encontrada." << endl;
		return 1;
	}
	
	else if(tipo_imagen == IMG_PGM) 
		LeerImagenPGM(nombre_imagen, f, c, buffer);
		
	else 
		LeerImagenPPM(nombre_imagen, f, c, buffer);	
	
	// Lectura del mensaje oculto:

	cout << "Revelando..." << endl;
	resultado = Revelar(mensaje, buffer, TAMANIO, MAXBUFFER); 

	// Salida del mensaje:

	if (resultado == 2)
	{
		cerr << "Error: El mensaje es demasiado grande." << endl;
		return 1;
	}
	else if (resultado == 1)
	{
		cout << "La imagen no presenta ningún mensaje oculto." << endl;
		return 1;
	} 
	else
		cout << "El mensaje es:\n\t" << mensaje << endl;
}
