/**
  * @file codificar.h
  * @brief Fichero cabecera para ocultar y revelar.
  *
  * Permite ocultar y revelar mensajes en imágenes.
  *
  */

#ifndef _CODIFICAR_
#define _CODIFICAR_

	#include "imagenES.h"

	/**
	  * @brief Oculta un mensaje en una imagen.
	  *
	  * @param mensaje Indica el mensaje que se desea ocultar.
	  * @param buffer Vector que contiene los píxeles de la imagen.
	  * @param tipo Contiene el tipo de la imagen en la que se desea escribir.
	  * @param nombre Se trata del nombre que recibirá la nueva imagen.
	  * @param f Número de filas de píxeles de la imagen.
	  * @param c Número de columnas de píxeles de la imagen
	  * @return Devuelve si ha tenido éxito la escritura.
	  *
	  * @see Ocultar
	  */

	bool Ocultar(char mensaje[], unsigned char buffer[], TipoImagen tipo, const char nombre[], int f, int c);

	/**
	  * @brief Oculta un mensaje en una imagen.
	  *
	  * @param mensaje Almacena el mensaje que está oculto.
	  * @param buffer Vector que contiene los píxeles de la imagen.
	  * @param MAXMENSAJE Tamaño máximo del vector que almacena el mensaje.
	  * @param MAXBUFFER Tamaño máximo del vector que contiene la imagen.
	  * @return Devuelve si ha tenido éxito la lectura.
	  *
	  * @see Revelar
	  */

	int Revelar(char mensaje[], unsigned char buffer[], const int MAXMENSAJE, const int MAXBUFFER);

#endif