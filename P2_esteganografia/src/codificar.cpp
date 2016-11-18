// Fichero que contiene las declaraciones de las funciones de codificar.h

#include "codificar.h"

// FIXME: Función para ocultar un mensaje en una imagen PPM o PGM:

bool Ocultar(char mensaje[], unsigned char buffer[], TipoImagen tipo, const char nombre[], int f, int c)
{
	char letra;
	int k = 0;
	int tamanio_PGM = f * c;
	int tamanio_PPM = (f * c) * 3;
	int tamanio_msj;

	for (tamanio_msj = 0 ; mensaje[tamanio_msj] != '\0' ; ++tamanio_msj);

	if  (((tipo == IMG_PGM) && (tamanio_msj < tamanio_PGM)) ||
		((tipo == IMG_PPM) && (tamanio_msj < tamanio_PPM)))
	{ 

		for (int j = 0 ; mensaje[j] != '\0' ; ++j)
		{
			letra = mensaje[j];
			
			for (int i = 7 ; i >= 0 ; --i)
			{
				if(((1<<i) & letra) != 0)
				{
					buffer[k] = buffer[k] | 1;
					k++;
				}
				else
				{
					buffer[k] = buffer[k] &~ 1;
					k++;
				}
			}
		}
		
		// Introducción del '\0' al final del mensaje:

		for (int i = 0 ; i < 8 ; ++i)
			buffer[i+k] = buffer[i+k] &~ 1;

		// Escritura de la nueva imagen:

		if (tipo == IMG_PGM)
			EscribirImagenPGM(nombre, buffer, f, c);
		else 
			EscribirImagenPPM(nombre, buffer, f, c);

		return true;
	}

	else
		return false;
}

// FIXME: Función para revelar un mensaje en una imagen:

int Revelar(char mensaje[], unsigned char buffer[], const int MAXMENSAJE, const int MAXBUFFER)
{	
	char bit = 0;
	int k = 0;
	int tamanio_msg = 0;
	bool final_encontrado = false;

	// Lectura anticipada:

	for (int i = 7 ; i >= 0 ; --i)
	{
		if ((buffer[k] & 1) != 0)
			bit = bit | (1<<i);
	
		k++;
	}
	
	while (bit != '\0' && k < MAXBUFFER)
	{
		if (tamanio_msg < MAXMENSAJE)
		{
			mensaje[tamanio_msg] = bit;
			tamanio_msg++;
		}
		bit = 0;

		for (int i = 7 ; i >= 0 ; --i)
		{
			if ((buffer[k] & 1) != 0)
				bit = bit | (1<<i);
		
			k++;
		}
		
		if (bit == '\0')
			final_encontrado = true;
	}
	
	if (tamanio_msg >= MAXMENSAJE)
		return 2; // No entra el mensaje.
	else if (! final_encontrado)
		return 1; // No tiene mensaje.
	else
		return 0; // Éxito;
}
