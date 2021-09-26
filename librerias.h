#include <stdlib.h>
#include<stdio.h>
#include<iostream> //trabajar en proyecto
#include<fstream>

#include "validacion.h"
using namespace std;

//estructuras que inicializan el nodo 
typedef struct Nodo{
	struct Nodo *sig;
	
	int IDE=0; //no se debe repetir;
	int dia;
	char empleado[30];
	int papas;
	int jugos;
	int helados;
	
}Node;