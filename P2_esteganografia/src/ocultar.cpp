// Programa para ocultar un mensaje en una imagen.

#include <iostream>
#include "codificar.h"

using namespace std;

int main()
{
	const int MAXBUFFER = 1000000;
	const int MAXNOMBRE = 100;
	const int TAMANIO = MAXBUFFER / 8;
	char nombre_imagen[MAXNOMBRE];
	char img_salida[MAXNOMBRE];
	char mensaje[TAMANIO];
	unsigned char buffer[MAXBUFFER];
	int f, c;
	TipoImagen tipo_imagen;
	
	// Especificación de la imagen de entrada:

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

	// Lectura de la imagen de salida y del mensaje:

	cout << "Introduzca la imagen de salida: ";
	cin.getline(img_salida, MAXNOMBRE);

	cout << "Introduzca el mensaje: ";
	cin.getline(mensaje, TAMANIO);

	// Ocultar la imagen:

	if(Ocultar(mensaje, buffer, tipo_imagen, img_salida, f, c ))
		cout << "Ocultando..." << endl;
	else
		cerr << "Error: Espacio insuficiente en la imagen." << endl;
}
