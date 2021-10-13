
#include "piloto.h"

/**
 * \brief Devuelve la posicion de la estructura donde el id coincida
 * \param array Array de marcas
 * \param cant Limite del array de marcas
 * \param id, id pasado para comparar con los id del array de marcas
 * \return Retorna i (EXITO) y -1 (ERROR)
 *
 */
int buscaIndDescrPilotoPorId(ePiloto array[], int cant,int id){
    int retorno = -1;
    for(int i = 0;i < cant;i++){
        if(array[i].idPiloto == id){
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
void listarPiloto(ePiloto unPiloto){
    if(unPiloto.isEmpty != 1){
        fflush(stdin);//__fpurge(stdin);
        printf("\t%d - \t\t%s\n",unPiloto.dni,
    	     unPiloto.nombre);
    }
}

/**
 * \brief Lista marcas
 * \param array Array de marcas
 * \param cant Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarPilotos(ePiloto array[],int cant){
    int retorno = -1;
    if(array != NULL && cant > 0){
       printf("\n\t\tPilotos\n\n");
       printf("\tDNI\t\tNombre\n");
       printf("--------------------------------------------\n");
       for(int i = 0;i<cant;i++){
    	   fflush(stdin);//__fpurge(stdin);
           listarPiloto(array[i]);
           retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Inicializa el array
 * \param array Array de pilotos a ser inicializado
 * \param cant Limite del array de pilotos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int inicializarPilotos(ePiloto array[], int cant){
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
 * \param array Array de pilotos donde se busca la posicion libre
 * \param cant Limite del array de pilotos
 * \return Retorna posicion (EXITO) y -1 (ERROR)
 *
 */
int buscarLibre_pilotos(ePiloto array[],int cant){
    int posicion;
    posicion = -1;
    if(array != NULL && cant > 0){
        for(int i = 0;i < cant;i++){
            if(array[i].isEmpty == 1){
              posicion = i;
              break;
            }
        }
    }
    return posicion;
 }

/**
 * \brief Da de alta un piloto
 * \param array Array de pilotos donde se guarda el piloto dado de alta
 * \param cant Limite del array de pilotos
 * \param id puntero autoincrementable, id del piloto siendo dado de alta
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int alta_Piloto(ePiloto array[], int cant, int* id){
    int respuesta = -1;
    int indice;
	ePiloto bufferPiloto;
    indice = buscarLibre_pilotos(array,cant);
	if(array != NULL && cant > 0 && indice < cant && indice >= 0 && id != NULL)
	{
		if(utn_getNumero(&bufferPiloto.dni,"Ingrese el dni del piloto\n","\nERROR\n",1,4,2) == 0 &&
				utn_getCadena(bufferPiloto.nombre, NOM,"Ingrese el nombre del piloto\n","\nERROR\n",2) == 0)
			{
			fflush(stdin);
			respuesta = 0;
			bufferPiloto.idPiloto = *id;
			bufferPiloto.isEmpty = 0;
			array[indice] = bufferPiloto;
			printf("id piloto en alta :%d",array[indice].idPiloto);
			(*id)++;
		}
	}
	return respuesta;
}
/**
 * \brief Da de alta forzada un piloto
 * \param array Array de pilotos donde se guarda el piloto dado de alta
 * \param cant Limite del array de pilotos
 * \param id puntero autoincrementable, id del piloto siendo dado de alta
 * \param dni valor a ser guardado en el campo del mismo nombre en bufferPiloto
 * \param nombre valor a ser guardado en el campo del mismo nombre en bufferPiloto
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaForzada_Piloto(ePiloto array[], int cant, int* id, int dni, char nombre[]){
    int retorno = -1;
    int indice;
	ePiloto bufferPiloto;

    indice = buscarLibre_pilotos(array, cant);
	if(array != NULL && cant > 0 && id != NULL  && dni > 0 && nombre != NULL && indice >= 0)
	{
			bufferPiloto.idPiloto = *id;
			bufferPiloto.dni = dni;
			strcpy(bufferPiloto.nombre, nombre);
			bufferPiloto.isEmpty = 0;
			array[indice] = bufferPiloto;
			(*id)++;
			retorno = 0;
	}
	return retorno;
}
