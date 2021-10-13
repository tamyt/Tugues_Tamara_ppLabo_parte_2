#include "avion.h"

/**
 * \brief Inicializa el array
 * \param array Array de aviones a ser inicializado
 * \param cant Limite del array de aviones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int inicializarAviones(eAvion array[], int cant){
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
 * \param array Array de aviones donde se busca la posicion libre
 * \param cant Limite del array de aviones
 * \return Retorna posicion (EXITO) y -1 (ERROR)
 *
 */
int buscarLibre(eAvion array[],int cant){
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
 * \brief Da de alta un avion
 * \param array Array de aviones donde se guarda el avion dado de alta
 * \param cant Limite del array de aviones
 * \param id puntero autoincrementable, id del avion siendo dado de alta
 * \param arrayV Array de viajes usado para listar viajes y validar el id de viaje
 * \param cantV Limite del array de viajes
 * \param arrayM Array de marcas usado para listar marcas y validar el id de marca
 * \param cantM Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int alta_Avion(eAvion array[], int cant, int* id, eViaje arrayV[], int cantV, eMarca arrayM[],int cantM, ePiloto arrayP[], int cantP, int* idP){
    int respuesta = -1;
    int indice;
	eAvion bufferAvion;
    indice = buscarLibre(array,cant);
	if(array != NULL && cant > 0 && indice < cant && indice >= 0 && id != NULL && arrayV != NULL
			&& cantV > 0 && arrayM != NULL && cantM > 0 && arrayP != NULL && cantP > 0 && idP != NULL)
	{
		if(utn_getNumero(&bufferAvion.matricula,"Ingrese la matricula\n","\nERROR\n",200,1000,2) == 0 &&
			utn_getNumero(&bufferAvion.fecha.dia,"Ingrese el dia\n","\nERROR\n",1,31,2) == 0 &&
			utn_getNumero(&bufferAvion.fecha.mes,"Ingrese el mes\n","\nERROR\n",1,12,2) == 0 &&
			utn_getNumero(&bufferAvion.fecha.anio,"Ingrese el año\n","\nERROR\n",2010,2021,2) == 0 &&
			listarViajes(arrayV,cantV) == 0 &&
			utn_getNumero(&bufferAvion.idViaje,"\nIngrese el id del viaje\n","\nERROR\n",50,1000,2) == 0 &&
			validaIdViaje(bufferAvion.idViaje,arrayV,cantV)== 0 &&
			listarMarcas(arrayM,cantM) == 0 &&
			utn_getNumero(&bufferAvion.idMarca,"\nIngrese el id de la marca\n","\nERROR\n",1000,1007,2) == 0 &&
			validaIdMarca(bufferAvion.idMarca,arrayM,cantM)== 0 &&
			utn_getNumero(&bufferAvion.modelo,"Ingrese el modelo\n","\nERROR\n",1800,2021,2) == 0 &&
			utn_getNumero(&bufferAvion.cantAsientos,"Ingrese la cantidad de asientos\n","Cantidad incorrecta\n",2,1000,2)==0 &&
			alta_Piloto(arrayP, cantP, idP) == 0)
		{
			respuesta = 0;
			bufferAvion.idAvion = *id;
			bufferAvion.idPiloto = *idP;
			bufferAvion.isEmpty = 0;
			array[indice] = bufferAvion;

			printf("idP: %d",array[indice].idPiloto);
			(*id)++;
		}

	}
	return respuesta;
}
/**
 * \brief Da de alta forzada un avion
 * \param array Array de aviones donde se guarda el avion dado de alta
 * \param cant Limite del array de aviones
 * \param id puntero autoincrementable, id del avion siendo dado de alta
 * \param matricula valor a ser guardado en el campo del mismo nombre en bufferAvion
 * \param dia valor a ser guardado en el campo del mismo nombre en fecha en bufferAvion
 * \param mes valor a ser guardado en el campo del mismo nombre en fecha en bufferAvion
 * \param anio valor a ser guardado en el campo del mismo nombre en fecha en bufferAvion
 * \param idViaje valor a ser guardado en el campo del mismo nombre en bufferAvion
 * \param idMarca valor a ser guardado en el campo del mismo nombre en bufferAvion
 * \param modelo valor a ser guardado en el campo del mismo nombre en bufferAvion
 * \param cantAsientos valor a ser guardado en el campo del mismo nombre en bufferAvion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaForzadaAvion(eAvion array[], int cant, int* id, int matricula,int dia,int mes,int anio,
    int idViaje,int idMarca, int modelo, int cantAsientos){
    int retorno = -1;
    int indice;
	eAvion bufferAvion;

    indice = buscarLibre(array, cant);
	if(array != NULL && cant > 0 && id != NULL  && matricula > 0 && dia >0 && mes >0 && anio >0 &&
	    idViaje > 0 && idMarca > 0&& modelo > 0 && cantAsientos > 0 && indice >= 0)
	{
			bufferAvion.idAvion = *id;
			bufferAvion.matricula = matricula;
			bufferAvion.fecha.dia = dia;
			bufferAvion.fecha.mes = mes;
			bufferAvion.fecha.anio = anio;
			bufferAvion.idViaje = idViaje;
			bufferAvion.idMarca = idMarca;
			bufferAvion.modelo = modelo;
			bufferAvion.cantAsientos = cantAsientos;
			bufferAvion.isEmpty = 0;

			array[indice] = bufferAvion;
			(*id)++;
			retorno = 0;
	}
	return retorno;
}
/**
 * \brief ordena el array de estructuras de aviones por marca y por matricula
 * \param array Array de aviones para poder ordenar por matricula
 * \param cant Limite del array de aviones
 * \param arrayM Array de marcas usado para poder ordenar tomando la descripcion de la marca
 * \param cantM Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int ordenaAvionesPorMarcaYMatricula(eAvion array[], int cant, eMarca arrayM[], int cantM){
    int retorno = -1;
    int indiceI;
    int indiceJ;
    eAvion avionAux;
    if(array != NULL && cant > 0 && arrayM != NULL && cantM > 0){
        for(int i = 0;i<cant-1;i++){
            for(int j = i + 1;j < cant;j++){
                indiceI = buscaIndDescrPorId(arrayM, cantM, array[i].idMarca);
                indiceJ = buscaIndDescrPorId(arrayM, cantM, array[j].idMarca);
                if(strcmp(arrayM[indiceI].descripcion, arrayM[indiceJ].descripcion) > 0 ||
                (strcmp(arrayM[indiceI].descripcion, arrayM[indiceJ].descripcion) == 0 && array[i].matricula > array[j].matricula)){
                    avionAux = array[i];
                    array[i] = array[j];
                    array[j] = avionAux;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief lista 1 avion
 * \param unAvion una estructura de tipo eAvion
 * \param descr char donde se pasa la descripcion de la marca
 * \param descrV char donde se pasa la descripcion del viaje
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarAvion(eAvion unAvion, char descr[], char descrV[], char nombreP[]){ // 10 y 15
    if(unAvion.isEmpty != 1){
    	fflush(stdin);//__fpurge(stdin);
        printf("%8d- \t\t%d/%d/%d\t%8s-\t%8s - \t%8d - \t%8d-\t%8s\n",unAvion.matricula,
    	    unAvion.fecha.dia,unAvion.fecha.mes,unAvion.fecha.anio,
    	    descrV, descr, unAvion.modelo, unAvion.cantAsientos, nombreP);
    }
    return 0;
}

/**
 * \brief Lista aviones ordenados
 * \param array Array de aviones
 * \param cant Limite del array de aviones
 * \param arrayV Array de viajes
 * \param cantV Limite del array de viajes
 * \param arrayM Array de marcas
 * \param cantM Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarAvionesOrdenados(eAvion array[], int cant,eViaje arrayV[], int cantV, eMarca arrayM[], int cantM, ePiloto arrayP[], int cantP){
    int retorno = -1;
    int indice;
    int indiceV;
    int indiceP;
    if(array != NULL && cant > 0 && arrayV != NULL && cantV > 0 && arrayM != NULL && cantM > 0 && arrayP != NULL && cantP > 0){
       if(ordenaAvionesPorMarcaYMatricula(array,cant, arrayM,cantM) == 0){
           printf("\n\t\t\tAviones ordenados por marca y matricula\n\n");
           printf("Matricula\t\tFecha\t\tViaje\t\tMarca\t\tModelo\t\tCantidad de asientos\t\tPiloto\n");
           printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
           for(int i = 0;i<cant;i++){
               indice = buscaIndDescrPorId(arrayM, cantM,array[i].idMarca);
               indiceV = buscaIndiceDescrViajePorId(arrayV, cantV,array[i].idViaje);
               indiceP = buscaIndDescrPilotoPorId(arrayP, cantP,array[i].idPiloto);
               printf("id piloto en listar :%d",array[i].idPiloto);
               listarAvion(array[i], arrayM[indice].descripcion, arrayV[indiceV].descripcionViaje, arrayP[indiceP].nombre);
            }
            retorno = 0;
        }
        else{
            printf("Error, listar ordenado");
        }
    }
    return retorno;
}

/**
 * \brief Lista aviones desordenados, es decir que no llama a la funcion de "ordenaAvionesPorMarcaYMatricula"
 * \param array Array de aviones
 * \param cant Limite del array de aviones
 * \param arrayV Array de viajes
 * \param cantV Limite del array de viajes
 * \param arrayM Array de marcas
 * \param cantM Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarAviones(eAvion array[], int cant,eViaje arrayV[], int cantV, eMarca arrayM[], int cantM, ePiloto arrayP[], int cantP){
    int retorno = -1;
    int indice;
    int indiceV;
    int indiceP;
    if(array != NULL && cant > 0 && arrayV != NULL && cantV > 0 && arrayM != NULL && cantM > 0){
       printf("\n\t\t\tAviones desordenados\n\n");
       printf("Matricula\t\tFecha\t\tViaje\t\tMarca\t\tModelo\t\tCantidad de asientos\t\tPiloto\n");
       printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
       for(int i = 0;i<cant;i++){
           indice = buscaIndDescrPorId(arrayM, cantM,array[i].idMarca);
           indiceV = buscaIndiceDescrViajePorId(arrayV, cantV,array[i].idViaje);
           indiceP = buscaIndDescrPilotoPorId(arrayP, cantP,array[i].idPiloto);
           listarAvion(array[i], arrayM[indice].descripcion, arrayV[indiceV].descripcionViaje, arrayP[indiceP].nombre);
           retorno = 0;
       }

    }
    return retorno;
}


/**
 * \brief Busca una posicion en el array de estructuras de aviones que coincida con una matricula ingresada
 * \param array Array de aviones
 * \param cant Limite del array de aviones
 * \param matricula, dato ingresado para buscar la posicion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int buscarPosicionConMatricula(eAvion array[], int cant, int matricula){
    int posicion;
    posicion = -1;
    if(array != NULL && cant > 0 && matricula > 0){
        for(int i = 0;i < cant;i++){
            if(array[i].matricula == matricula){
              posicion = i;
              break;
            }
         }
    }
    return posicion;
}

/**
 * \brief Modifica el modelo y/o la cantidad de asientos de un avion
 * \param array Array de aviones
 * \param cant Limite del array de aviones
 * \param arrayV Array de viajes
 * \param cantV Limite del array de viajes
 * \param arrayM Array de marcas
 * \param cantM Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modificar_Avion(eAvion array[], int cant,eViaje arrayV[], int cantV, eMarca arrayM[], int cantM , ePiloto arrayP[], int cantP){
    int respuesta = -1;
    int rta;
	int bufferMatricula;
	int bufferModelo;
	int bufferCantAsientos;
	int indice;
	if(array != NULL && cant > 0 && arrayV != NULL && cantV > 0 && arrayM != NULL && cantM > 0)
	{
	    if(listarAviones(array, cant, arrayV, cantV, arrayM,cantM, arrayP, cantP) == 0 &&
            utn_getNumero(&bufferMatricula,"\nIngrese la matricula\n","\nERROR\n",200,1000,2) == 0){
            indice = buscarPosicionConMatricula(array,cant, bufferMatricula);
            //
            if(indice >= 0){
                do{
                    if(utn_getNumero(&rta, "\n1.Modificar modelo\n2.Modificar cantidad de asientos\n3.Salir\n", "Opción inválida\n", 1, 3, 2) == 0){
                        switch(rta){
                            case 1:
                                printf("Ud. ha seleccionado la opción 1.Modificar modelo \n\n");
                                if(utn_getNumero(&bufferModelo,"\nIngrese el modelo\n","\nERROR\n",1800,2021,2) == 0){
                                    array[indice].modelo = bufferModelo;
                                    printf("\nSe ha modificado el modelo con exito: \n");
                                    listarAviones(array, cant, arrayV, cantV, arrayM, cantM, arrayP, cantP);
                                }
                                else{
                                    printf("Error\n");
                                }
                                break;
                            case 2:
                                printf("Ud. ha seleccionado la opción 2.Modificar cantidad de asientos \n\n");
                                if(utn_getNumero(&bufferCantAsientos,"Ingrese la cantidad de asientos\n","Cantidad incorrecta\n",2,1000,2)==0){
                                    array[indice].cantAsientos = bufferCantAsientos;
                                    printf("\nSe ha modificado la cantidad de asientos con exito: \n");
                                    listarAviones(array, cant, arrayV, cantV, arrayM,cantM , arrayP, cantP);

                                }
                                else{
                                    printf("Error\n");
                                }
                                break;
                            default:
                                printf("Ud. ha seleccionado la opción 3.Salir \n\n");
                                break;
                        }
                        respuesta = 0;
                    }
                }
                while(rta < 3);
            }
            else{
                printf("No se ha encontrado la matricula\n");
            }

	    }
    }
	return respuesta;
}
/**
 * \brief Da de baja un avion
 * \param array Array de aviones
 * \param cant Limite del array de aviones
 * \param arrayV Array de viajes
 * \param cantV Limite del array de viajes
 * \param arrayM Array de marcas
 * \param cantM Limite del array de marcas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int baja_Avion(eAvion array[], int cant,eViaje arrayV[], int cantV, eMarca arrayM[], int cantM , ePiloto arrayP[], int cantP){
    int respuesta = -1;
	int indice;
	int bufferMatricula;
	char decision;
	if(array != NULL && cant > 0 && arrayV != NULL && cantV > 0 && arrayM != NULL && cantM > 0)
	{
	    if(listarAviones(array, cant, arrayV, cantV, arrayM,cantM , arrayP, cantP) == 0 &&
            utn_getNumero(&bufferMatricula,"\nIngrese la matricula\n","\nERROR\n",200,1000,2) == 0){
            indice = buscarPosicionConMatricula(array,cant, bufferMatricula);
            if(indice >= 0){
                if(utn_getCaracter(&decision,"\nSeguro que lo quiere dar de baja?(s/n) \n","\nERROR\n",'n','s',2)==0 &&
                    decision == 's'){
                    array[indice].isEmpty = 1;
                    respuesta = 0;
                    fflush(stdin);//__fpurge(stdin);
                    printf("Se ha dado de baja con exito :");
                    listarAviones(array, cant, arrayV, cantV, arrayM,cantM , arrayP, cantP);
                }
            }
        }
    }

	return respuesta;
}



