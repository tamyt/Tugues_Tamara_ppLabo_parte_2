#ifndef MARCA_H_
#define MARCA_H_

//#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#define SIZE 20
#define CANTD 11

typedef struct
{
	int idMarca;
	char descripcion[SIZE];
	int isEmpty;
}eMarca;

int validaIdMarca(int id, eMarca array[],int cant);
int buscaIndDescrPorId(eMarca array[], int cant, int id);

void listarMarca(eMarca unEMarca);
int listarMarcas(eMarca array[],int cant);

int inicializarMarcas(eMarca array[],int cant);
int buscarLibreM(eMarca array[],int cant);
int alta_Marca(eMarca array[],int cant,int* id);
int altaForzadaMarca(eMarca array[],int cant,int* id, char descripcion[]);
int modificar_Marca(eMarca array[], int cant);
int baja_Marca(eMarca array[], int cant);

#endif /* MARCA_H_ */
