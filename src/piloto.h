

#ifndef PILOTO_H_
#define PILOTO_H_

#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include "utn.h"


#define NOM 20

typedef struct
{
	int idPiloto;
	int dni;
	char nombre[NOM];
	int isEmpty;
}ePiloto;

int buscaIndDescrPilotoPorId(ePiloto array[], int cant,int id);
void listarPiloto(ePiloto unPiloto);
int listarPilotos(ePiloto array[],int cant);
int inicializarPilotos(ePiloto array[], int cant);
int buscarLibre_pilotos(ePiloto array[],int cant);
int alta_Piloto(ePiloto array[], int cant, int* id);
int altaForzada_Piloto(ePiloto array[], int cant, int* id, int dni, char nombre[]);
#endif /* PILOTO_H_ */
