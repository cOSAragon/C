#include "cola.h"
#include <string>
COLA::COLA(void)
{
	iMetido=0;
	iSacado=0;
	iCodError=EXITO;
}
void COLA::Push(char Dato[])
{
	//verificar que hay espacio
	if(iMetido<TOPE&&iMetido>=0)
	{
		//si hay
		strcpy(cadenas[iMetido].cadena,Dato);
		iMetido++;
		iCodError=EXITO;
	}
	else
		iCodError=COLALLENA;
}
char * COLA::Pop(void)
{
	char dato[LARGOCADENA];
	//verificar si hay datos
	if(iMetido>iSacado&&TOPE>iSacado)
	{
		strcpy(dato,cadenas[iSacado].cadena);
		iCodError=EXITO;
		iSacado++;
	}
	else
		iCodError=COLAVACIA;
	return dato;
}
int COLA::HayError(void)
{
	return iCodError;
}