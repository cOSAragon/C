// burbujacadena.cpp: define el punto de entrada de la aplicación de consola.
//#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define NUMCADENAS 100
#define LARGOCADENA 20
using namespace std;
main()
{
	int i,j,k,opc,a,comp,intercambios=0,compi=0,l=48;
	clock_t generacion,orden;
	//declaracin estructuras
	struct cadenita{
		char cadenota[LARGOCADENA];
	};
	//arreglo de estructuras
	struct cadenita cadenon[NUMCADENAS];
	char cadena[LARGOCADENA];
	srand ( time (NULL) );
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
	/*creacion de numeros desordenados*/
	generacion=clock();
	for(j=0;j<NUMCADENAS;j++)
	{
		for(i=0; i<LARGOCADENA-1; i++)
		{
			cadena[i] =l;
			l++;
		}
		cadena[i] = '\0';
		strcpy(cadenon[j].cadenota,cadena);
		cout<<cadenon[j].cadenota<<endl;
	}
	printf( "Numero de segundos transcurridos desde el comienzo del programa: %f s\n", (clock()-generacion)/(double)CLOCKS_PER_SEC );
	/*ordenarlos*/
	orden=clock();
	for(j=0;j<NUMCADENAS-1;j++)
	{
		for(i=0;i<NUMCADENAS-1;i++)
		{
			comp=strcmp(cadenon[i].cadenota,cadenon[i+1].cadenota);
			compi++;
			if(comp==a)
			{
				strcpy(cadena,cadenon[i].cadenota);
				strcpy(cadenon[i].cadenota,cadenon[i+1].cadenota);
				strcpy(cadenon[i+1].cadenota,cadena);
				intercambios++;
			}
		}
	}
	/*mostrar datos ordenados*/
	for(j=0;j<NUMCADENAS;j++)
	{
		cout<<cadenon[j].cadenota<<endl;
	}
	cout<<"El numero de comparaciones fue "<<compi<<endl;
	cout<<"El numero de intercambios fue "<<intercambios<<endl;
	printf( "Numero de segundos transcurridos durante el ordenamiento: %f s\n", (clock()-(generacion+orden))/(double)CLOCKS_PER_SEC );
	getch();
	return 0;
}

