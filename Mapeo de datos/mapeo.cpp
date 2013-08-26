// mapeo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	/* Variables para aritmetica*/
	int t,x,w=1,n,m,a,i=0,sub,ind=1,tamdato,datcon,loc,db=1000;
	float z;
	int * indices = NULL;
	/* Variables del enigma del problema*/
	int * ent;
	int * mult = NULL;
	int * mult2 = NULL;
	int * conin = NULL;
	char * car;
	float * flot;
	do{
		printf("Este programa asume una direccion base de 1000\n");
		printf("Por favor seleccion que tipo de dato sera el arreglo\n");
		printf("1. Entero\n2. Caracter\n3. Flotantes\n");
		scanf("%i",&t);
	} while(t!=1&&t!=2&&t!=3);
	do{
		printf("Por favor escriba de que dimension desea el arreglo\n");
		scanf("%i",&n);
	}while(n<1);
	printf("Escriba los valores de los indices de las dimension que establecio\n");
	indices = new int[n];
	conin = new int[n];
	mult = new int[n];
	mult2 = new int[n];
	for(i = 0; i < n; i++)
	{
		do{
			printf("Escriba el valor indice %i \n",(i+1));
			scanf("%i",&sub);
		}while(sub<1);
		indices[i]=sub;
		x=sub*ind;
		ind=x;
	}
	printf("Total de datos a almacenar %i \n",ind);
	switch (t)
	{
		case 1:
			tamdato=sizeof(int);
			ent = new int[ind];
			printf("Introduzca los %i datos de manera secuencial\n",ind);
			for(i=0;i<ind;i++){
				printf("Introduzca el dato %i\n",(i+1));
				scanf("%i",&x);
				ent[i]=x;
			}
			printf("Introduzca los datos que se le piden para consultar la direccion de memoria del dato que desea consultar\n");
			for(i = 0; i < n; i++)
			{
				printf("Introduce el valor entero del indice de la %i dimension del dato que deseas consultar",(n-i));
				scanf("%i",&sub);
				conin[i]=sub;
			}
			printf("El dato a consultar es:\n Dato[");
			for(i = 0; i < n; i++)
			{
					printf("%i,",conin[i]);
			}
			printf("]\n");
			for(i=0; i<n; i++)
			{
				m=i+1;
				a=1;
				for(int j=m;j<n;j++)
				{
					x=indices[j];
					w=x*a;
					a=w;
				}
				mult[i]=w;
			}
			for(i=0; i<n;i++){
				if ((n-1)==i)
				{
					mult2[i]=conin[i]+1;
				}
				else
				{
				mult2[i]=mult[i]*conin[i];
				}
			}
			a=0;
			for(i=0;i<n;i++)
			{
				x=mult2[i]+a;
				a=x;
			}
			datcon=a;
			printf("El numero de dato buscado es: %i\n",datcon);
			loc=db+(datcon*tamdato);
			printf("Su direccion en la memoria es:%i\n",loc);
		break;
		case 2:
			tamdato=sizeof(char);
			car = new char[ind];
			printf("\nIntroduzca los %i datos de manera secuencial\n",ind);
			for(i=0;i<ind;i++)
			{
				printf("Introduzca el dato %i\n",(i+1));
				car[i]=getche();
			}
			printf("Introduzca los datos que se le piden para\n consultar la direccion de memoria del dato que desea consultar");
			for(i = 0; i < n; i++)
			{
				printf("\nIntroduce el valor entero del indice de la %i dimension\n del dato que deseas consultar",(n-i));
				scanf("%i",&sub);
				conin[i]=sub;
			}
			printf("El dato a consultar es:\n Dato[");
			for(i = 0; i < n; i++)
			{
					printf("%i,",conin[i]);
			}
			printf("]\n");
			for(i=0; i<n; i++)
			{
				m=i+1;
				a=1;
				for(int j=m;j<n;j++)
				{
					x=indices[j];
					w=x*a;
					a=w;
				}
				mult[i]=w;
			}
			for(i=0; i<n;i++){
				if ((n-1)==i)
				{
					mult2[i]=conin[i]+1;
				}
				else
				{
				mult2[i]=mult[i]*conin[i];
				}
			}
			a=0;
			for(i=0;i<n;i++)
			{
				x=mult2[i]+a;
				a=x;
			}
			datcon=a;
			printf("El numero de dato buscado es: %i",datcon);
			loc=db+(datcon*tamdato);
			printf("Su direccion en la memoria es:%i\n",loc);
		break;
		case 3:
			tamdato=sizeof(float);
			flot = new float[ind];
			printf("Introduzca los %i datos de manera secuencial\n",ind);
			for(i=0;i<ind;i++){
				printf("Introduzca el dato %i\n",(i+1));
				scanf("%f",&z);
				flot[i]=z;
			}
			printf("Introduzca los datos que se le piden para consultar la direccion de memoria del dato que desea consultar\n");
			for(i = 0; i < n; i++)
			{
				printf("Introduce el valor entero del indice de la %i dimension del dato que deseas consultar",(n-i));
				scanf("%i",&sub);
				conin[i]=sub;
			}
			printf("El dato a consultar es:\n Dato[");
			for(i = 0; i < n; i++)
			{
					printf("%i,",conin[i]);
			}
			printf("]\n");
			for(i=0; i<n; i++)
			{
				m=i+1;
				a=1;
				for(int j=m;j<n;j++)
				{
					x=indices[j];
					w=x*a;
					a=w;
				}
				mult[i]=w;
			}
			for(i=0; i<n;i++){
				if ((n-1)==i)
				{
					mult2[i]=conin[i]+1;
				}
				else
				{
				mult2[i]=mult[i]*conin[i];
				}
			}
			a=0;
			for(i=0;i<n;i++)
			{
				x=mult2[i]+a;
				a=x;
			}
			datcon=a;
			printf("El numero de dato buscado es: %i",datcon);
			loc=db+(datcon*tamdato);
			printf("Su direccion en la memoria es:%i\n",loc);
		break;
	}
	getch();
	return 0;
}


