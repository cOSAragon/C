// metodomenorescadena.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define NUMCADENAS 30000
#define LARGOCADENA 20
#define ESMENOR -1
#define ESMAYOR 1
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int iPasada,iComparacion,i,j,iMenor,iPos,iAuxiliar=0,opc,a;
	clock_t generacion,orden;
	/*declaracion estructura*/
	struct cadenita
	{
		char cadenota[LARGOCADENA];
	};
	/*arreglo de estructuras*/
	struct cadenita cadenon[NUMCADENAS];
	char cadena[LARGOCADENA];
	char menor[LARGOCADENA];
	srand (time(NULL));
	do
	{
		system("cls");
		cout<<"Como desea ordenar los numeros:"<<endl;
		cout<<"1. Menor a Mayor"<<endl;
		cout<<"2. Mayor a Menor"<<endl;
		cin>>opc;
		if(opc!=1&&opc!=2)
		{
			cout<<"Seleccione una opcion valida"<<endl;
			getch();
		}
	}
	while(opc!=1&&opc!=2);
	if(opc==1)
		a=1;
	else
		a=-1;
	/*generacion de numeros desordenados*/
	generacion=clock();
	for(j=0;j<NUMCADENAS;j++)
	{
		for(i=0; i<LARGOCADENA-1; i++)
		{
			cadena[i] = '0'+ ( rand() % ('0' - '9') );
		}
		cadena[i] = '\0';
		strcpy(cadenon[j].cadenota,cadena);
		cout<<cadenon[j].cadenota<<endl;
	}
	printf( "Numero de segundos transcurridos desde el comienzo del programa: %f s\n", (clock()-generacion)/(double)CLOCKS_PER_SEC );
	/*ordenarlos*/
	orden=clock();
	for(iPasada=0;iPasada<NUMCADENAS;iPasada++)
	{
		iPos=iPasada;
		/*inicialisamos el menor*/
		if(a==1)
		{
			for(i=0;i<LARGOCADENA-1;i++)
			{
				menor[i]='9';
			}
			menor[i]='\0';
		}
		else if(a==-1)
		{
			menor[0]='-';
			for(i=1;i<LARGOCADENA-1;i++)
			{
				menor[i]='9';
			}
			menor[i]='\0';
		}
		for(iComparacion=iPos;iComparacion<NUMCADENAS;iComparacion++)
		{
			/*if para el desarrollo del menor*/
			if(a==1)
			{
				if(ESMENOR==strcmp(cadenon[iComparacion].cadenota,menor))
				{
					strcpy(menor,cadenon[iComparacion].cadenota);
					iPos=iComparacion;
				}
				iAuxiliar++;
			}
			else if(a==-1)
			{
				if(ESMAYOR==strcmp(cadenon[iComparacion].cadenota,menor))
				{
					strcpy(menor,cadenon[iComparacion].cadenota);
					iPos=iComparacion;
				}
				iAuxiliar++;
			}
		}
		strcpy(cadena,cadenon[iPos].cadenota);
		strcpy(cadenon[iPos].cadenota,cadenon[iPasada].cadenota);
		strcpy(cadenon[iPasada].cadenota,cadena);
	}
	/*pintar datos ordenados*/
	for(j=0;j<NUMCADENAS;j++)
	{
		cout<<cadenon[j].cadenota<<endl;
	}
	cout<<"El numero de intercambios fue "<<iPasada<<endl;
	cout<<"El numero de comparaciones fue"<<iAuxiliar<<endl;
	printf( "Numero de segundos transcurridos durante el ordenamiento: %f s\n", (clock()-(generacion+orden))/(double)CLOCKS_PER_SEC );
	getch();
	return 0;
}
