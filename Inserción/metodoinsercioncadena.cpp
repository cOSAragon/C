// metodoinsercioncadena.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#define LARGOCADENA 20
#define NUMCADENAS 30000
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int i,j,opc,a,b,intercambios=0,c=0;
	char cadena[LARGOCADENA];
	clock_t generacion,orden;
	//declaracion estructura
	struct cadenita
	{
		char cadenota[LARGOCADENA];
	};
	//Arreglo de estructuras
	struct cadenita cadenon[NUMCADENAS];
	srand(time(NULL));
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
			cadena[i] = '0'+ ( rand() % ('0' - '9') );
		}
		cadena[i] = '\0';
		strcpy(cadenon[j].cadenota,cadena);
		cout<<cadenon[j].cadenota<<endl;
	}
	printf( "Numero de segundos transcurridos desde el comienzo del programa: %f s\n", (clock()-generacion)/(double)CLOCKS_PER_SEC );
	/*ordenarlos*/
	orden=clock();
	for(i=0;i<NUMCADENAS-1;i++)
	{
		j=i;
		/*opcion 1*/
		while(a==(strcmp(cadenon[j].cadenota,cadenon[j+1].cadenota)))
		{
			strcpy(cadena,cadenon[j].cadenota);
			strcpy(cadenon[j].cadenota,cadenon[j+1].cadenota);
			strcpy(cadenon[j+1].cadenota,cadena);
			intercambios++;
			if(j!=0)
				j--;
		}
		/* opcion 2*/
		/*
        do
		{
                  if(a==(strcmp(cadenon[j].cadenota,cadenon[j+1].cadenota)))
                  {
                      strcpy(cadena,cadenon[j].cadenota);
			          strcpy(cadenon[j].cadenota,cadenon[j+1].cadenota);
			          strcpy(cadenon[j+1].cadenota,cadena);
			          intercambios++;
			          if(j!=0)
				              j--;
                  }
                  b=(strcmp(cadenon[j].cadenota,cadenon[j+1].cadenota));
                  comp++;
        }
        while(a==b);
        */
	}
	/*Mostrar datos ordenados*/
	for(j=0;j<NUMCADENAS;j++)
	{
		cout<<cadenon[j].cadenota<<endl;
	}
	cout<<"El numero de intercambios fue "<<intercambios<<endl;
	/* si opcion 2 activa quitar comentarios siguiente linea*/
	//cout<<"El numero de comparacion fue "<<comp<<endl;
	printf( "Numero de segundos transcurridos durante el ordenamiento: %f s\n", (clock()-(generacion+orden))/(double)CLOCKS_PER_SEC );
	getch();
	return 0;
}

