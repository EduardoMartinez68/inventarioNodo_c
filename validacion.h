#include <stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>

using namespace std;
//libreria de interfaz 
#include "interfaz.h"
float validaFlotante(const char mensaje[],int x,int y){
	int continuar=0;
	float flotante=0;
	
	do{
		//printf("%s",mensaje);
		draw_text(x,y,mensaje);
		continuar = scanf("%f", &flotante);	
		fflush(stdin);
		system("cls"); //borrar datos en pantalla
	}while (continuar != 1);
	
	return flotante;
}

int validaEntero(const char mensaje[],int x,int y){
	int continuar=0;
	int entero=0;
	
	do{
		//printf("%s",mensaje);
		draw_text(x,y,mensaje);
		continuar = scanf("%d", &entero);
		fflush(stdin);
		system("cls"); //borrar datos en pantalla
	}while (continuar != 1);
	
	return entero;
}

void validaCadena(const char mensaje[], const char cadena[],int x,int y){
	bool bandera = true;
	while(bandera){
		//system("cls");
		//printf("%s", mensaje);
		draw_text(x,y,mensaje);
		scanf("%[^\n]",cadena);
		fflush(stdin);		
		if(strlen(cadena)>29){
			continue;
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isalpha(cadena[i]) || cadena[i]==' '){
					if (i== (strlen(cadena)-1)){
						bandera=false;
					}
				}else{
					break;
				}
			}
		}
		
		system("cls"); //borrar datos en pantalla				
	} 
}