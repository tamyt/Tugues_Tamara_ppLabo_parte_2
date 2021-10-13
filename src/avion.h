#ifndef AVION_H_
#define AVION_H_

#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "viaje.h"
#include "marca.h"
#include "piloto.h"

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
	int idAvion;
	int matricula;
	eFecha fecha;
	int idViaje;
	int idMarca;
	int modelo;
	int cantAsientos;
	int idPiloto;
	int isEmpty;
}eAvion;


int inicializarAviones(eAvion array[], int cant);

int buscarLibre(eAvion array[],int cant);
int alta_Avion(eAvion array[], int cant, int* id, eViaje arrayV[], int cantV, eMarca arrayM[],int cantM, ePiloto arrayP[], int cantP, int* idP);

int altaForzadaAvion(eAvion array[], int cant, int* id, int matricula,int dia,int mes,int anio,
    int idViaje,int idMarca, int modelo, int cantAsientos);

int ordenaAvionesPorMarcaYMatricula(eAvion array[], int cant, eMarca arrayM[], int cantM);
int listarAvion(eAvion unAvion, char descr[], char descrV[], char nombreP[]);

int listarAvionesOrdenados(eAvion array[], int cant,eViaje arrayV[], int cantV, eMarca arrayM[], int cantM, ePiloto arrayP[], int cantP);

int listarAviones(eAvion array[], int cant,eViaje arrayV[], int cantV, eMarca arrayM[], int cantM, ePiloto arrayP[], int cantP);

int buscarPosicionConMatricula(eAvion array[], int cant, int matricula);

int modificar_Avion(eAvion array[], int cant,eViaje arrayV[], int cantV, eMarca arrayM[], int cantM, ePiloto arrayP[], int cantP);

int baja_Avion(eAvion array[], int cant,eViaje arrayV[], int cantV, eMarca arrayM[], int cantM , ePiloto arrayP[], int cantP);



#endif /* AVION_H_ */
