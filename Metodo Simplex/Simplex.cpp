#include "stdafx.h"
#include <iostream>
#define MAXIMISAR 1
#define MINIMIZAR -1
#define OPTIMO 1
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int opc,iTam,iLar,iCol,i=0,j=1,k=0,iCodError=OPTIMO,iPivCol=0,iPivReg=1;
	float fAux,fDen,fAct,**fTableu,*fRes;
	char cOtro;
	do
	{
		system("cls");
		cout<<"Metodo de simplex"<<endl;
		cout<<"Seleccione alguna opcion: \n\t 1. Maximizar \n\t 2. Minimizar"<<endl;
		cin>>opc;
	}
	while(opc!=1&&opc!=2);
	if (opc==1)
		fAct=MAXIMISAR;
	else
		fAct=MINIMIZAR;
	/*reservando memoria para la tableu*/
	cout<<"Introduzca el numero de restricciones"<<endl;
	cin>>iTam;
	opc=iTam;
	fTableu= new float *[iTam+1];
	cout<<"Introduzca el numero maximo de variables que tienen las restricciones"<<endl;
	cin>>iLar;
	iCol=iLar+iTam+1;
	for(int n = 0; n <(iTam+1); n++) 
	{
		fTableu[n] = new float[iCol]; /*ftableu es un array de 2 dimensiones*/
	}
	fRes= new float [iCol];
	/*introduciendo la funcion objetivo como zj y como TI*/
	cout<<"Introduzca la ecuacion Objetivo"<<endl;
	while(i<iLar)
	{
		cout<<"Introduzca la variable"<<(i+1)<<endl;
		cin>>fAux;  
		fTableu[0][i]=(-1*fAux)*fAct;
		fRes[i]=fAux;
		i++;
	}
	while(i<iCol)
	{
		fTableu[0][i]=0;
		fRes[i]=0;
		i++;
	}
	/*introduciendo las restricciones*/
	while(j<(iTam+1))
	{
		i=0;
		cout<<"Introduzca los datos de la restriccion "<<(j+1)<<endl;
		while(i<iLar)
		{
			cout<<"Introduzca la variable "<<(i+1)<<endl;
			cin>>fAux;  
			fTableu[j][i]=fAux;
			i++;
		}
		k=0;
		while(i<iCol-1)
		{
			if(j==(k+1))
				fTableu[j][i]=1;
			else
				fTableu[j][i]=0;
			k++;
			i++;
		}
		cout<<"Introduce el valor de b"<<endl;
		cin>>fTableu[j][i];
		j++;
	}
	cout<<endl;
	/*imprimiendo tablas*/
	for(int j=0;j<iTam+1;j++)
	{
		for(int i=0;i<iCol;i++)
		{
			cout<<"\t"<<fTableu[j][i];
		}
		cout<<endl;
	}
	cout<<endl;
	do
	{
		/*obtener columna pivote*/
		for(int i=0;i<iCol-1;i++)
		{
			
			if(fTableu[0][iPivCol]>fTableu[0][i])
				iPivCol=i;
		}		
		/*obtener renglon pivote*/
		for(int i=1;i<iTam+1;i++)
		{
			fAux=fTableu[iPivReg][iCol-1]/fTableu[iPivReg][iPivCol];
			fDen=fTableu[i][iCol-1]/fTableu[i][iPivCol];
			if(fAux>fDen)
			{
				if(fDen>0)
					iPivReg=i;
			}
		}		
		/*mini metodo de gauss*/
			/*Aplicando la metodologia del algoritmo de gauss, al elemento pivote que es el que se intersecta entre la columna pivote y el renglo convertir en 1 
			y aplicar misma operacion al renglon*/
			fDen=fTableu[iPivReg][iPivCol];
			for(int i=0;i<iCol;i++)
			{
				fTableu[iPivReg][i]=(fTableu[iPivReg][i])/(fDen);
			}
			/*Con los datos obtenidos en el proceso anterior aplicar gauss para que en la columna pivote haya ceros excepto el el renglon pivote*/
			float fAyuda=0,fExtra=0;
			for(int i=0;i<iTam+1;i++)
			{
				fAux=fTableu[i][iPivCol];
				if(i!=iPivReg)
				{
					for(int j=0;j<iCol;j++)
					{
						fExtra=fTableu[i][j];
						fDen=fTableu[iPivReg][j];
						fAyuda=(-1*fDen)*fAux;
						fTableu[i][j]=fExtra+fAyuda;	
					}	
				}
			}
		/*impresion nueva tabla*/
		for(int j=0;j<iTam+1;j++)
		{
			for(int i=0;i<iCol;i++)
			{
				cout<<"\t"<<fTableu[j][i];
			}
			cout<<endl;
		}
		cout<<endl;
		/*establecer si es optima o no*/
		k=0;
		for(int i=0;i<iCol;i++)
		{
			if(fTableu[0][i]<0)
				fRes[i]=!OPTIMO;
			else
				fRes[i]=OPTIMO;
			k=k+fRes[i];
		}
		if(k==iCol)
			iCodError=OPTIMO;
		else
			iCodError=!OPTIMO;
		
	}
	while(iCodError!=OPTIMO);
	system("pause");
	return 0;
}