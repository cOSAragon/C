// pila.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include "pila.h"
#include <string>
PILA::PILA(void)
{
	iTope=0;
	iCodError=EXITO;
}
void PILA::Push(char Dato[])
{
	//hay espacio
	if(iTope<TOPE&&iTope>=0)
	{
		//si hay
		strcpy(cadenas[iTope].cadena,Dato);
		iTope++;
		iCodError=EXITO;
	}
	else
		iCodError=PILALLENA;
}
char PILA::Pop(void)
{
	char dato[LARGOCADENA];
	//verificar si hay datos
	if(iTope>0&&iTope<=TOPE)
	{
		iTope--;
		strcpy(dato,cadenas[iTope].cadena);
		iCodError=EXITO;
	}
	else
		iCodError=PILAVACIA;
	return dato[LARGOCADENA];
}
int PILA::HayError(void)
{
	return iCodError;
}