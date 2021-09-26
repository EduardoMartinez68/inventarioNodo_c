#include "ordenamiento.h"
#include<iostream>
//estructuras que llenan el nodo 
Node *acomodar_nodos(Node *Lista,Node *nuevo_nodo){
	//agregar el nodo del ultimo 
	Node *tmp;
	tmp=Lista;
	while(tmp->sig !=NULL){
		tmp=tmp->sig;
	}
	//agregarlo al nuevo nodo
	tmp->sig=nuevo_nodo;
	
	return Lista;
}

Node *llenar_nuevo_nodo(Node *Lista,Node *nuevo_nodo){
	system("cls");
	draw_rectangle(1,1,50,20);
	//comprobar que no existe el ID 
	int ID;
	ID=nueva_ID(Lista);
	
	//apuntar al siguiente
	nuevo_nodo->sig=NULL;
	
	//ver si la lista esta vacia 
	if(Lista==NULL){
		Lista=nuevo_nodo;
	}
	else{
	     Lista=acomodar_nodos(Lista,nuevo_nodo);
	}
	
	//---------agregar datos al nodo 
	draw_rectangle(1,1,50,20); 
	int dia,papas,jugos,helados;
	papas=validaEntero("¿Cuantas papas vendiste?: ",3,3);draw_rectangle(1,1,50,20); 
	jugos=validaEntero("¿Cuantos jugos vendiste?: ",3,3);draw_rectangle(1,1,50,20); 
	helados=validaEntero("¿Cuantos helados vendiste?: ",3,3);draw_rectangle(1,1,50,20); 
	dia=validaEntero("¿Cuantos dias trabajaste?: ",3,3);draw_rectangle(1,1,50,20); 
	
	char m_nombre[30];
	validaCadena("Nombre del empleado: ",m_nombre,3,3);
	
	//llenar los datos en el arreglo  strcpy(pAlumno[num].nombre,m_nombre);
	nuevo_nodo->IDE=ID;
	nuevo_nodo->dia=dia;
	nuevo_nodo->papas=papas;
	nuevo_nodo->jugos=jugos;
	nuevo_nodo->helados=helados;
	strcpy(nuevo_nodo->empleado,m_nombre);
	
	
	return Lista;
}

Node *nuevoNodo(Node *Lista){
	//creando en memoria dinamica el nodo 
	Node *nuevo_nodo;
	nuevo_nodo=(Node *)malloc(sizeof(Node));
	
	//verificar si existe memoria en la pc para crearlo
	if(nuevo_nodo!=NULL){
		Lista=llenar_nuevo_nodo(Lista,nuevo_nodo);
		//returnar la lista modificada 
	    return Lista;
	}
	else{
		cout<<"Memoria llena"<<endl;
	}
}


//menus 
Node *crearNodos(Node *Lista){
	draw_rectangle(1,1,40,5);
	//agregar nodos  
	int arreglos;
	draw_text(3,3,"Cuantos archivos deceas: ");
	cin>>arreglos;
	
	//crear los nuevos datos
	for(int i=0;i<arreglos;i++){
		Lista=nuevoNodo(Lista);
	}
	
	return Lista;
}

int main(){
	//borrar los datos anteriores
	borrar_archivo();
	Node *Lista=Iniciar(Lista); //crear la lista
	
	//menu
	int menu;
	do{
		system("cls"); //borrar datos en pantalla
		//crear la interfaz grafica
		cout<<""; 
		system("COLOR B0");
		draw_rectangle(1,1,77,4);
		draw_text(30,2.5,"MENU DE TIENDA");
	    
	    draw_rectangle(1,4,77,12);
		draw_text(3,5,"1-----Ingresar dato");
		draw_text(3,6,"2-----Borrar primer dato");
		draw_text(3,7,"3-----Borrar ultimo dato");
		draw_text(3,8,"4-----Borrar un dato en especifico");
		draw_text(3,8,"5-----Borrar un id en especifico");
		draw_text(3,9,"6-----Imprimir dato");
		menu=validaEntero("Que deceas hacer: ",3,10);
		system("cls"); //borrar datos en pantalla
		switch(menu){
			case 1:{
				Lista=crearNodos(Lista);
				borrar_archivo();
				Escribir_archivos(Lista);
				break;
			}
			case 2:{
				Lista=eliminar_inicio_final(Lista,1);
				borrar_archivo();
				Escribir_archivos(Lista);
				break;
			}
			case 3:{
				Lista=eliminar_inicio_final(Lista,2);
				borrar_archivo();
				Escribir_archivos(Lista);
				break;
			}
			case 4:{
				borrar_archivo();
				draw_rectangle(1,1,77,10);
    			//borrar archivos 
    			int dato;
    			dato=validaEntero("Ingresar el dato que deceas eliminar: ",3,3);
    			Lista=eliminar(Lista,dato);
				Escribir_archivos(Lista);
				break;
			}
			case 5:{
				borrar_archivo();
				draw_rectangle(1,1,77,10);
    			//borrar archivos 
    			int id;
    			id=validaEntero("Ingresar el id que deceas eliminar: ",3,3);
				Lista=eliminar_id(Lista,id);
				Escribir_archivos(Lista);
				break;
			}
			case 6:{
				int num=0;
				while(num!=1){
					system("cls"); //borrar datos en pantalla
					Imprimir(Lista);
					cout<<""<<endl;
					cout<<"1---yes"<<endl;
					cout<<"Volver al menu: ";
					cin>>num;
				}
				break;
			}
			default:{
				break;
			}
		} 
	}while(menu!=7);
    system("cls"); //borrar datos en pantalla
    
    

    Imprimir(Lista);
	return 0;
}