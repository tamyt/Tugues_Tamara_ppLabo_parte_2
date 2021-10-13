//#include <stdio_ext.h>
#include "viaje.h"

/**
 * \brief Valida que el id pasado exista en el array de viajes
 * \param id, id pasado para comparar con los id del array de marcas
 * \param array Array de viajes
 * \param cant Limite del array de viajes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int validaIdViaje(int id, eViaje array[],int cant){
    int retorno = -1;
    for(int i = 0;i<cant;i++){
        if(array[i].idViaje == id){
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Devuelve la posicion de la estructura donde el id coincida
 * \param array Array de viajes
 * \param cant Limite del array de viajes
 * \param id, id pasado para comparar con los id del array de viajes
 * \return Retorna i (EXITO) y -1 (ERROR)
 *
 */
int buscaIndiceDescrViajePorId(eViaje array[],int cant,int id){
    int retorno = -1;
    for(int i = 0;i < cant;i++){
        if(array[i].idViaje == id){
           retorno = i;
        }
    }
    return retorno;
}

/**
 * \brief lista 1 viaje
 * \param unViaje una estructura de tipo eViaje
 * \return void
 *
 */
void listarViaje(eViaje unViaje){
    if(unViaje.isEmpty != 1){
    	fflush(stdin);//__fpurge(stdin);
        printf("%d- \t\t%s - \t\t%s\n",unViaje.idViaje,
	     unViaje.descripcionViaje, unViaje.kms);
    }
}

/**
 * \brief Lista viajes
 * \param array Array de viajes
 * \param cant Limite del array de viajes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarViajes(eViaje array[],int cant){
    int retorno = -1;
    if(array != NULL && cant > 0){
       printf("\n\t\t\tViajes\n\n");
       printf("Id\t\tDescripcion\t\tKms\n");
       printf("------------------------------------------------------\n");
       for(int i = 0;i<cant;i++){
    	   fflush(stdin);//__fpurge(stdin);
           listarViaje(array[i]);
           retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Inicializa el array
 * \param array Array de viajes a ser inicializado
 * \param cant Limite del array de viajes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int inicializarViajes(eViaje array[],int cant){
     int retorno = -1;
     if(array != NULL && cant > 0){
         for(int i = 0;i < cant;i++){
             array[i].isEmpty = 1;
         }
         retorno = 0;
     }
     return retorno;
}

/**
 * \brief Busca la primera posicion libre del array
 * \param array Array de viajes donde se busca la posicion libre
 * \param cant Limite del array de viajes
 * \return Retorna posicion(EXITO) y -1 (ERROR)
 *
 */
int buscarLibreViaje(eViaje array[],int cant){
    int posicion;
    posicion = -1;
    for(int i = 0;i < cant;i++){
        if(array[i].isEmpty == 1){
          posicion = i;
          break;
        }
     }
    return posicion;
 }

/**
 * \brief Da de alta un viaje
 * \param array Array de viaje donde se guarda el viaje dada de alta
 * \param cant Limite del array de viajes
 * \param id puntero autoincrementable, id del viaje siendo dada de alta
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int alta_Viaje(eViaje array[],int cant,int* id){
    int respuesta = -1;
    int indice;
	eViaje bufferViaje;
    indice = buscarLibreViaje(array,cant);
	if(array != NULL && cant > 0 && indice < cant && indice >= 0 && id != NULL)
	{
	    if(utn_getCadena(bufferViaje.descripcionViaje, DESCR,"\nIngrese la descripcion\n","\nERROR\n",2) == 0 &&
	        utn_getCadenaKms(bufferViaje.kms, CANT,"\nIngrese los kms\n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			bufferViaje.idViaje = *id;
			bufferViaje.isEmpty = 0;
			array[indice] = bufferViaje;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta forzada un viaje
 * \param array Array de viajes donde se guarda el viaje dado de alta
 * \param cant Limite del array de viajes
 * \param id puntero autoincrementable, id del viaje siendo dado de alta
 * \param descripcion valor a ser guardado en el campo "descripcionViaje" en bufferMarca
 * \param descripcionKms valor a ser guardado en el campo "kms" en bufferMarca
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaForzadaViaje(eViaje array[],int cant,int* id, char descripcion[], char descripcionKms[]){
    int retorno = -1;
    int indice;
	eViaje bufferViaje;

    indice = buscarLibreViaje(array, cant);
	if(array != NULL && cant > 0 && id != NULL  && descripcion != NULL && descripcionKms != NULL && indice >= 0)
	{
			bufferViaje.idViaje = *id;
			strcpy(bufferViaje.descripcionViaje, descripcion);
			strcpy(bufferViaje.kms, descripcionKms);
			bufferViaje.isEmpty = 0;
			array[indice] = bufferViaje;
			(*id)++;
			retorno = 0;
	}
	return retorno;
}


/**
 * \brief Modifica la descripcion del viaje y los kms
 * \param array Array de viajes
 * \param cant Limite del array de viajes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modificar_Viaje(eViaje array[], int cant){
    int respuesta = -1;
	int bufferId;
	int indice;
	char descripcion[10];
	char descripcionKms[20];
	if(array != NULL && cant > 0)
	{
	    if(listarViajes(array, cant) == 0 &&
            utn_getNumero(&bufferId,"\nIngrese el id del viaje a ser modificado\n","\nERROR\n",100,104,2) == 0){
            indice = buscaIndiceDescrViajePorId(array,cant, bufferId);
            if(indice >= 0){
                    if(utn_getCadena(descripcion, CANT,"\nIngrese la descripcion\n","\nERROR\n",2) == 0 &&
                        utn_getCadenaKms(descripcionKms, CANT,"\nIngrese los kms\n","\nERROR\n",2) == 0){
                       strcpy(array[indice].descripcionViaje, descripcion);
                       strcpy(array[indice].kms, descripcionKms);
                       respuesta = 0;
                    }
            }
            else{
                printf("No se ha encontrado el id\n");
            }

	    }
    }
	return respuesta;
}

/**
 * \brief Da de baja un viaje
 * \param array Array de viajes
 * \param cant Limite del array de viajes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int baja_Viaje(eViaje array[], int cant){
    int respuesta = -1;
	int indice;
	int bufferId;
	char decision;
	if(array != NULL && cant > 0)
	{
	    if(listarViajes(array, cant) == 0 &&
            utn_getNumero(&bufferId,"\nIngrese el id del viaje a ser dado de baja\n","\nERROR\n",100,104,2) == 0){
            indice = buscaIndiceDescrViajePorId(array,cant, bufferId);
            if(indice >= 0){
                if(utn_getCaracter(&decision,"\nSeguro que lo quiere dar de baja?(s/n) \n","\nERROR\n",'n','s',2)== 0 &&
                    decision == 's'){
                    array[indice].isEmpty = 1;
                    respuesta = 0;
                    fflush(stdin);//__fpurge(stdin);
                    printf("Se ha dado de baja con exito :");
                    listarViajes(array, cant);
                }
            }
        }
    }
	return respuesta;
}
