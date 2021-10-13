#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "marca.h"

/**
 * \brief Valida que el id pasado exista en el array de marcas
 * \param id, id pasado para comparar con los id del array de marcas
 * \param array Array de marcas
 * \param cant Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int validaIdMarca(int id, eMarca array[],int cant){
    int retorno = -1;
    for(int i = 0;i<cant;i++){
        if(array[i].idMarca == id){
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Devuelve la posicion de la estructura donde el id coincida
 * \param array Array de marcas
 * \param cant Limite del array de marcas
 * \param id, id pasado para comparar con los id del array de marcas
 * \return Retorna i (EXITO) y -1 (ERROR)
 *
 */
int buscaIndDescrPorId(eMarca array[], int cant,int id){
    int retorno = -1;
    for(int i = 0;i < cant;i++){
        if(array[i].idMarca == id){
           retorno = i;
        }
    }
    return retorno;
}

/**
 * \brief lista 1 marca
 * \param unEMarca una estructura de tipo eMarca
 * \return void
 *
 */
void listarMarca(eMarca unEMarca){
    if(unEMarca.isEmpty != 1){
        fflush(stdin);//__fpurge(stdin);
        printf("\t%d - \t\t%s\n",unEMarca.idMarca,
    	     unEMarca.descripcion);
    }
}

/**
 * \brief Lista marcas
 * \param array Array de marcas
 * \param cant Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarMarcas(eMarca array[],int cant){
    int retorno = -1;
    if(array != NULL && cant > 0){
       printf("\n\t\tMarcas\n\n");
       printf("\tId\t\tDescripcion\n");
       printf("--------------------------------------------\n");
       for(int i = 0;i<cant;i++){
    	   fflush(stdin);//__fpurge(stdin);
           listarMarca(array[i]);
           retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Inicializa el array
 * \param array Array de marca a ser inicializado
 * \param cant Limite del array de marca
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int inicializarMarcas(eMarca array[],int cant){
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
 * \param array Array de marca donde se busca la posicion libre
 * \param cant Limite del array de marca
 * \return Retorna posicion(EXITO) y -1 (ERROR)
 *
 */
int buscarLibreM(eMarca array[],int cant){
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
 * \brief Da de alta una marca
 * \param array Array de marca donde se guarda la marca dada de alta
 * \param cant Limite del array de marca
 * \param id puntero autoincrementable, id de la marca siendo dada de alta
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int alta_Marca(eMarca array[],int cant,int* id){
    int respuesta = -1;
    int indice;
	eMarca bufferMarca;
    indice = buscarLibreM(array,cant);
	if(array != NULL && cant > 0 && indice < cant && indice >= 0 && id != NULL)
	{
	    if(utn_getCadena(bufferMarca.descripcion, CANTD,"\nIngrese la descripcion\n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			bufferMarca.idMarca = *id;
			bufferMarca.isEmpty = 0;
			array[indice] = bufferMarca;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta forzada una marca
 * \param array Array de marca donde se guarda la marca dada de alta
 * \param cant Limite del array de marca
 * \param id puntero autoincrementable, id de la marca siendo dada de alta
 * \param descripcion valor a ser guardado en el campo del mismo nombre en bufferMarca
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaForzadaMarca(eMarca array[],int cant,int* id, char descripcion[]){
    int retorno = -1;
    int indice;
	eMarca bufferMarca;

    indice = buscarLibreM(array, cant);
	if(array != NULL && cant > 0 && id != NULL  && descripcion != NULL && indice >= 0)
	{
			bufferMarca.idMarca = *id;
			strcpy(bufferMarca.descripcion, descripcion);
			bufferMarca.isEmpty = 0;
			array[indice] = bufferMarca;
			(*id)++;
			retorno = 0;
	}
	return retorno;
}


/**
 * \brief Modifica la descripcion de la marca
 * \param arrayM Array de marcas
 * \param cantM Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modificar_Marca(eMarca array[], int cant){
    int respuesta = -1;
	int bufferId;
	int indice;
	char descripcion[10];
	if(array != NULL && cant > 0)
	{
	    if(listarMarcas(array, cant) == 0 &&
            utn_getNumero(&bufferId,"\nIngrese el id de la marca a ser modificada\n","\nERROR\n",1000,1003,2) == 0){
            indice = buscaIndDescrPorId(array,cant, bufferId);
            if(indice >= 0){
                    if(utn_getCadena(descripcion, CANTD,"\nIngrese la descripcion\n","\nERROR\n",2) == 0){
                       strcpy(array[indice].descripcion, descripcion);
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
 * \brief Da de baja una marca
 * \param array Array de marcas
 * \param cant Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int baja_Marca(eMarca array[], int cant){
    int respuesta = -1;
	int indice;
	int bufferId;
	char decision;
	if(array != NULL && cant > 0)
	{
	    if(listarMarcas(array, cant) == 0 &&
            utn_getNumero(&bufferId,"\nIngrese el id de la marca a ser dada de baja\n","\nERROR\n",1000,1003,2) == 0){
            indice = buscaIndDescrPorId(array,cant, bufferId);
            if(indice >= 0){
                if(utn_getCaracter(&decision,"\nSeguro que lo quiere dar de baja?(s/n) \n","\nERROR\n",'n','s',2)== 0 &&
                    decision == 's'){
                    array[indice].isEmpty = 1;
                    respuesta = 0;
                    fflush(stdin);//__fpurge(stdin);
                    printf("Se ha dado de baja con exito :");
                    listarMarcas(array, cant);
                }
            }
        }
    }
	return respuesta;
}
