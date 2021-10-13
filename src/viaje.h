#ifndef VIAJE_H_
#define VIAJE_H_

#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include "utn.h"


#define DESCR 26
#define CANT 15


typedef struct
{
	int idViaje;
	char descripcionViaje[DESCR];
	char kms[CANT];
	int isEmpty;
}eViaje;

int validaIdViaje(int id, eViaje array[],int cant);
int buscaIndiceDescrViajePorId(eViaje array[],int cant,int id);
void listarViaje(eViaje unViaje);
int listarViajes(eViaje array[],int cant);

int inicializarViajes(eViaje array[],int cant);
int buscarLibreViaje(eViaje array[],int cant);
int alta_Viaje(eViaje array[],int cant,int* id);
int altaForzadaViaje(eViaje array[],int cant,int* id, char descripcion[], char descripcionKms[]);
int modificar_Viaje(eViaje array[], int cant);
int baja_Viaje(eViaje array[], int cant);
#endif /* VIAJE_H_ */
