#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include "utn.h"

int esNumerica(char* cadena)// char cadena[]
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

 int esSoloLetras(char* cadena, int longitud)// char cadena[]
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && longitud > 0)
    {
        for(i = 0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
    }
    return retorno;
}

int esAlfanumericoFlotante(char* cadena)// char cadena[]
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if((cadena[i] != ' ') && (cadena[i] != '.') &&
            (cadena[i] < 'a' || cadena[i] < 'z')&&
            (cadena[i] < 'A' || cadena[i] < 'Z') &&
            (cadena[i] < '0' || cadena[i] > '9'))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}


int myGets(char* cadena, int longitud)
{
    int retorno=-1;
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin); // fflush o __fpurge
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}


int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}


int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}


int utn_getNumero(int* resultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
		   printf("%s", mensaje);
		   if(getInt(&bufferInt)== 0){
		       if(bufferInt >= minimo && bufferInt <= maximo){
    			   *resultado = bufferInt;
    			   retorno = 0;
    			   break;
    		   }
    		   else
    		   {
    			   printf("%s",mensajeError);
    			   reintentos --;
    		   }
		   }
		}
	    while(reintentos >= 0);
	}
	return retorno;
}



int utn_getCaracter(char* resultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
		   printf("%s", mensaje);
		   fflush(stdin);//__fpurge(stdin);
		   scanf("%c",&bufferChar);
		   if(bufferChar >= minimo && bufferChar <= maximo)
		   {
			   *resultado = bufferChar;
			   retorno = 0;
			   break;
		   }
		   else
		   {
			   printf("%s",mensajeError);
			   reintentos --;
		   }
		}
	    while(reintentos >= 0);
	}
	return retorno;
}

int utn_getCadena(char* resultado,int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(resultado != NULL && longitud > 1 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
	    do{
	        printf("%s", mensaje);
	        fflush(stdin);//__fpurge(stdin);
    		if(getString(buffer,sizeof(buffer))== 0 &&
        		esSoloLetras(buffer,sizeof(buffer)) &&
    			strnlen(buffer,sizeof(buffer)) < longitud)
        	{
        		strncpy(resultado,buffer,longitud);
    			retorno = 0;
    			break;
    		}
    		else
		   {
			   printf("%s",mensajeError);
			   reintentos --;
		   }
	    }
	    while(reintentos >= 0);
	}
	return retorno;
}


int utn_getCadenaKms(char* resultado,int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(resultado != NULL && longitud > 1 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
	    do{
	         printf("%s", mensaje);
	         fflush(stdin);//__fpurge(stdin);
    		if(	getString(buffer,sizeof(buffer))== 0 &&
        		esAlfanumericoFlotante(buffer) &&
    			strnlen(buffer,sizeof(buffer)) < longitud)
        	{
        		strncpy(resultado,buffer,longitud);
    			retorno = 0;
    		}
    		else
		   {
			   printf("%s",mensajeError);
			   reintentos --;
		   }
	    }
	    while(reintentos >= 0);
	}
	return retorno;
}
