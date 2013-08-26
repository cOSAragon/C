#include <iostream>
#include <string>
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#define SALIR 3
#define LARGOCADENA 30
using namespace std;
void main(void)
{
	COLA tortillera;
	int iOpcion;
	char szDato[LARGOCADENA];
	char szAux[LARGOCADENA];
	int iDato;
	iOpcion=(!SALIR);
	while(iOpcion!=SALIR)
	{
		system("cls");
		cout<<"Seleccione que desea hacer"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>iOpcion;
		switch(iOpcion)
		{
			case 1:
				cout<<"Introduzca la cadena de texto"<<endl;
				scanf("%s",szDato);
				szDato[LARGOCADENA-1]='/0';
				tortillera.Push(szDato);
				if(tortillera.HayError())
					cout<<"Overflow en Pila"<<endl;
			break;
			case 2:
				/*algo pasa aqui que no obtiene el valor del metodo pop del objeto tortillera*/
				strcpy(szAux,tortillera.Pop());
				if(tortillera.HayError())
					cout<<"Underflow en Pila"<<endl;
				else
				{
					cout<<"El dato removido fue:"<<endl;
					cout<<szAux<<endl;
				}
			break;
			case 3:
				cout<<"Gracias por usar el programa de la cola"<<endl;
			break;
			default:
				cout<<"Las Opciones validas son 1,2 y 3. Elija una de ellas."<<endl;
			break;
		}
		system("PAUSE");
	}
}