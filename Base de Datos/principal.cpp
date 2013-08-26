#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SALIR 1
#define OPCION 15
#define LARGO 20
#define LARGOT 20
using namespace std;
int menu(char cad[]);
void CrearFichero(FILE *Fichero);
void InsertarDatos(FILE *Fichero);
void VerDatos(FILE *Fichero);
void Abrir(FILE *Fichero);
void Borrando(void);
void Vaciar(void);
void Ordenar(void);
struct sRegistro
{
	char Nombre[25];
	int Edad;
	float Sueldo;
} registro;
char cNombre[LARGOT];
 main ()
{
	char cOpc[LARGO];
	int iOpc,i,est;
	FILE *Fichero;
	do
	{
		system("cls");
		cout<<"Bienvenido a GEODATOS"<<endl;
		cout<<"Escriba su comando"<<endl;
		scanf("%s",cOpc);
		iOpc=menu(cOpc);
		switch(iOpc)
		{
			case 1:	
				CrearFichero(Fichero);
			break;
			case 2:
				Vaciar();
			break;
			case 3:
				InsertarDatos(Fichero);
			break;
			case 4:
				Borrando();
			break;
			case 5:
				Abrir(Fichero);
			break;
			case 6:
				Fichero=fopen(cNombre, "r");
				fclose(Fichero);
			break;
			case 7:
				//Ordenar();
			break;
			case 8:
				VerDatos(Fichero);
			break;
			case 9:
			break;
			case 10:
			break;
			case 11:
			break;
			case 12:
			break;
			case 13:
			break;
			case 14:
			break;
			case 15:
				est=SALIR;
				cout<<"Gracias por utilizar nuestro sistema"<<endl;
				cout<<"FES inc"<<endl;
			break;
			default:
				cout<<"Digite un comando valido"<<endl;
				cout<<"Para ver los comandos validos escriba el comando:"<<endl<<"AYUDA"<<endl;
			break;
		}
		getch();
	}while(est!=SALIR);
}
int menu(char cad[])
{
	struct cadenita
	{
		char cadena[LARGO];
	};
	struct cadenita cadenon[OPCION];
	int i=0,j,f;
	strcpy(cadenon[i].cadena,"CREAR"); i++;
	strcpy(cadenon[i].cadena,"VACIAR"); i++;
	strcpy(cadenon[i].cadena,"INSERTAR"); i++;
	strcpy(cadenon[i].cadena,"ELIMINAR"); i++;
	strcpy(cadenon[i].cadena,"ABRIR"); i++;
	strcpy(cadenon[i].cadena,"CERRAR"); i++;
	strcpy(cadenon[i].cadena,"ORDENAR"); i++;
	strcpy(cadenon[i].cadena,"LISTAR"); i++;
	strcpy(cadenon[i].cadena,"BUSCAR"); i++;
	strcpy(cadenon[i].cadena,"IR_PRIMERO"); i++;
	strcpy(cadenon[i].cadena,"IR_ULTIMO"); i++;
	strcpy(cadenon[i].cadena,"IR"); i++;
	strcpy(cadenon[i].cadena,"BORRA"); i++;
	strcpy(cadenon[i].cadena,"AYUDA"); i++;
	strcpy(cadenon[i].cadena,"SALIR"); i++;
	i=0;
	do
	{
		j=strcmp(cadenon[i].cadena,cad);
		if(j==0)
			f=1;
		i++;
	}while(f!=1);
	return i;
}
void CrearFichero(FILE *Fichero)
{
	
	int i;
	cout<<"Introduzca el nombre del archivo que desea crear"<<endl;
	cout<<"No mas de 10 caracteres"<<endl;
	scanf("%s",cNombre);
	i=strlen(cNombre);
	cNombre[i]='.';
	i++; cNombre[i]='d';
	i++; cNombre[i]='b';
	i++; cNombre[i]='f';
	i++; cNombre[i]='\0';
	Fichero=fopen(cNombre,"r");
	if(!Fichero)
	{
		Fichero=fopen(cNombre,"w");
		cout<<"Archivo Creado"<<endl;
	}
	else
	{
		cout<<"El archivo ya existe"<<endl;
	}
	fclose(Fichero);
	system("PAUSE");
}
void InsertarDatos(FILE *Fichero)
{
	Fichero=fopen(cNombre, "a+");
 
        if(Fichero == NULL)
        {
                printf("\nFichero no existe! \nPor favor creelo");
                
        }
		else
		{
			printf("\nDigita el nombre: ");
			scanf("%s", &registro.Nombre);
			printf("\nDigita la edad: ");
			scanf("%d", &registro.Edad);
			printf("\nDigita el sueldo: ");
			scanf("%f", &registro.Sueldo);
			fwrite(&registro, sizeof(struct sRegistro), 1, Fichero);
		}
		fclose(Fichero);
		getch();
}
void VerDatos(FILE *Fichero)
{
	int num=1;
	Fichero=fopen(cNombre,"r");
	if(Fichero==NULL)
	{
		cout<<"El fichero no existe."<<endl;
		cout<<"Por Favor Crearlo"<<endl;
	}
	else
	{
		fread(&registro,sizeof(struct sRegistro),1,Fichero);
		printf("\nNumero \tNombre \tEdad \tSueldo");
		while(!feof(Fichero))
		{
			 printf("\n%d \t%s \t%d \t%.2f", num, registro.Nombre,registro.Edad, registro.Sueldo);
             fread(&registro, sizeof(struct sRegistro), 1, Fichero);
             num++;
		}
	}
	fclose(Fichero);
	getch();
	}
void Abrir(FILE *Fichero)
{
	int i;
	cout<<"Introduzca el nombre el archivo"<<endl;
	scanf("%s",cNombre);
	i=strlen(cNombre);
	cNombre[i]='.';
	i++; cNombre[i]='d';
	i++; cNombre[i]='b';
	i++; cNombre[i]='f';
	i++; cNombre[i]='\0';
	Fichero=fopen(cNombre, "r");
    if(Fichero == NULL)
    {
      cout<<"\nFichero no existe! \nPor favor creelo"<<endl;
    }
	else
	{
		cout<<"\n El fichero ha sido exitosamente abierto"<<endl;
	}
	fclose(Fichero);
}
void Borrando(void)
{
	int i;
	cout<<"Introduzca el nombre del archivo que desea borrar"<<endl;
	cout<<"No mas de 10 caracteres"<<endl;
	scanf("%s",cNombre);
	i=strlen(cNombre);
	cNombre[i]='.';
	i++; cNombre[i]='d';
	i++; cNombre[i]='b';
	i++; cNombre[i]='f';
	i++; cNombre[i]='\0';
	if( remove(cNombre) == -1 )
		perror( "Hubo un problema al eliminar\n asegurese de que el archivo exista" );
	else
		puts( "Archivo Exitosamente Eliminado" );
}
void Vaciar(void)
{
	char ch, source_file[20], target_file[20];
    FILE *source, *target;
	source=fopen("temp.dbf","w");
	fclose(source);
    source = fopen("temp.dbf", "r");
    target = fopen(cNombre, "w");
    while( ( ch = fgetc(source) ) != EOF )
       fputc(ch, target);
    printf("El archivo ha sido exitosamente vaciado\n");
    fclose(source);
    fclose(target);
	remove("temp.dbf");
	getch();
 } 
