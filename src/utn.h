#ifndef UTN_H_
#define UTN_H_

int esNumerica(char* cadena);

int esAlfanumerico(char* cadena);
int esSoloLetras(char* cadena, int longitud);

int getInt(int* pResultado);

int getString(char* cadena, int longitud);

int myGets(char* cadena, int longitud);
int utn_getNumero(int* resultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int utn_getCaracter(char* resultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
int utn_getCadena(char* resultado,int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getCadenaKms(char* resultado,int longitud,char* mensaje, char* mensajeError, int reintentos);

#endif /* UTN_H_ */
