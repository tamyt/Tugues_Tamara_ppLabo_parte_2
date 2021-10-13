#include <stdio.h>
#include "utn.h"
#include "avion.h"
#include "viaje.h"
#include "marca.h"
#include "piloto.h"

#define CANTA 2
#define QTY 5
#define QTYM 4
//#define QTYP 4

int main()
{
    setbuf(stdout,NULL);
    int rta;
    int contIdAvion;
    //int contIdMarca;
    //int contIdViaje;
    int contIdPiloto;
    int flag;
    contIdAvion = 1;
    //contIdMarca = 1;
    //contIdViaje = 1;
    contIdPiloto = 1;
    flag = 0;



	eAvion arrayAviones[QTY];

    eMarca arrayMarcas[QTYM] = {{1000, "Boeing",0},
								{1001, "Airbus",0},
								{1002, "ATR",0},
								{1003, "Bombardier",0}};
	eViaje arrayViajes[QTY]= {{100, "Salta", "1462,5 kms",0},
								{101, "Tucuman", "1247,6 kms",0},
								{102, "Neuquen", "1139,4 kms",0},
								{103, "Corrientes", "670 kms",0},
								{104, "Chubut", "1735,8 kms",0}};

	ePiloto arrayPilotos[QTYM] = {{10,1, "Sanchez"},
									{11,2, "Ana"},
									{12,3, "Juan"},
									{13,4, "Sol"}};

	if(inicializarAviones(arrayAviones,QTY)==0)
	{
		printf("Array inicializado correctamente. \n");
	}
	if(inicializarPilotos(arrayPilotos,QTYM)==0)
	{
			printf("ArrayPilotos inicializado correctamente. \n");
	}

	do{
        if(utn_getNumero(&rta, "\n1.Alta avion\n2.Modificar avion\n3.Baja avion\n4.Listar aviones\n5.Listar viajes\n6.Listar Marcas\n7.Salir\n",
            "Opción inválida\n\n", 1, 7, 2) == 0){
            switch(rta){
                case 1://Alta avion
                    printf("Ud. ha seleccionado la opción 1-Alta \n\n");
                    /*if(altaForzadaAvion(arrayAviones, QTY, &contIdAvion, 503,15,2, 2009, 100,1002, 2010, 50) == 0 &&
                        altaForzadaAvion(arrayAviones, QTY, &contIdAvion, 312,10,5, 2019, 101,1001, 2000, 23) == 0 &&
                        altaForzadaAvion(arrayAviones, QTY, &contIdAvion, 300,19,9, 2008, 102,1002, 1996, 159) == 0 &&
                        altaForzadaAvion(arrayAviones, QTY, &contIdAvion, 202,25,3, 2020, 103,1003, 1802, 255) == 0 &&
                        altaForzadaAvion(arrayAviones, QTY, &contIdAvion, 215,5,11, 2006, 104,1000, 1982, 528) == 0 )*/
                    if(alta_Avion(arrayAviones, QTY, &contIdAvion, arrayViajes, QTY, arrayMarcas, QTYM, arrayPilotos, QTYM, &contIdPiloto) == 0){
                        printf("\nEl alta se ha realizado con exito\n\n");
                        flag = 1;
                    }
                    else{
                        printf("\nError\n\n");
                    }
                    break;
                case 2: // Modificacion de avion
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción 2-Modificación \n\n");
                        if(modificar_Avion(arrayAviones, QTY,arrayViajes,QTY,arrayMarcas, QTYM ,arrayPilotos, QTYM) != 0){
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de avion para poder modificarlo\n\n");
                    }
                    break;
                case 3:// Baja de avion
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción 3-Baja \n\n");
                        if(baja_Avion(arrayAviones, QTY,arrayViajes,QTY,arrayMarcas, QTYM ,arrayPilotos, QTYM) != 0){
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de avion para poder darlo de baja\n\n");
                    }
                    break;
                case 4: // Listar aviones
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción 4-Listar aviones \n\n");
                        if(listarAvionesOrdenados(arrayAviones, QTY,arrayViajes,QTY,arrayMarcas, QTYM ,arrayPilotos, QTYM) == 0){
                        //if(listarAviones(arrayAviones, QTY,arrayViajes,QTY,arrayMarcas, QTY)==0){
                           printf("\nSe ha informado con exito \n\n");
                        }
                        else{
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de avion para poder listarlo\n\n");
                    }
                    break;
                case 5:// Listado viajes
                    printf("Ud. ha seleccionado la opción 5-Listar viajes \n\n");
                    if(listarViajes(arrayViajes,QTY) == 0){
                       printf("\nSe ha informado con exito \n\n");
                    }
                    else{
                        printf("\nError\n\n");
                    }
                    break;
                case 6:// Listado marcas
                    printf("Ud. ha seleccionado la opción 6-Listar marcas \n\n");
                    if(listarMarcas(arrayMarcas,QTYM) == 0){
                       printf("\nSe ha informado con exito \n\n");
                    }
                    else{
                        printf("\nError\n\n");
                    }
                    break;
                default:
                    break;
            }
		}
    }
    while(rta < 7);

    return 0;
}
