#include "librerias.h"
Node *Imprimir2(Node *tmp){
	//imprimir archivos en pantalla 
	cout<<"ID: "<<tmp->IDE<<endl;
	cout<<"Empleado: "<<tmp->empleado<<endl;
	cout<<"Dia: "<<tmp->dia<<endl;
	cout<<"jugos: "<<tmp->jugos<<endl;
	cout<<"papas: "<<tmp->papas<<endl;
	cout<<"Helados: "<<tmp->helados<<endl;
	cout<<"........................................"<<endl;
}
Node *Imprimir(Node *Lista){
	if(Lista!=NULL){
	    Node *tmp;
	    tmp=Lista;   
		//avanzar por la lista 
		while(tmp->sig !=NULL){
			//preguntar si se repite 
			Imprimir2(tmp);
			tmp=tmp->sig; //avanzar 
		}
		Imprimir2(tmp);
    }
}

//fundciones de guardar en archivo 
Node *Escribir_archivos2(Node *tmp){
	ofstream archivo;
	archivo.open("menu.txt",ios::app); // in abrir el archivo para agregarle 
	
	if(archivo.fail()){
		cout<<"No se puede abrir el archivo :c";
		exit(1);
	}
	
	//llenar el archivo de texto 
	archivo<<"ID: "<<tmp->IDE<<endl;
	archivo<<"Empleado: "<<tmp->empleado<<endl;
	archivo<<"Dia: "<<tmp->dia<<endl;
	archivo<<"jugos: "<<tmp->jugos<<endl;
	archivo<<"papas: "<<tmp->papas<<endl;
	archivo<<"Helados: "<<tmp->helados<<endl;
	archivo<<"........................................"<<endl;
	//cerrar el archivo de texto 
	archivo.close();
}

Node *Escribir_archivos(Node *Lista){
	if(Lista!=NULL){
	    Node *tmp;
	    tmp=Lista;   
		//avanzar por la lista 
		while(tmp->sig !=NULL){
			//preguntar si se repite 
			Escribir_archivos2(tmp);
			tmp=tmp->sig; //avanzar 
		}
		Escribir_archivos2(tmp);
    }
}

void borrar_archivo(){
	ofstream archivo;
	archivo.open("menu.txt",ios::out); // in abrir el archivo para agregarle 
	
	if(archivo.fail()){
		cout<<"No se puede abrir el archivo :c";
		exit(1);
	}
	//cerrar el archivo de texto 
	archivo.close();	
}


///eliminar registros
Node *Iniciar(Node *Lista){
	Lista=NULL;
	return Lista;
};
 
Node *eliminar_inicio_final(Node *Lista,int num){
	//comprobar que la lista no esta basia 
	if(Lista!=NULL){
		Node *tmp;
		tmp=Lista;
		
		if(num==1){
		    //borrar primer elemento
		    Lista=Lista->sig;
		    free(tmp); //borrar direcion de memoria 
		}
		else{
		    //borrar ultimo 
		    if(tmp->sig!=NULL){
		        while(tmp->sig->sig!=NULL){
			        tmp=tmp->sig;
		        }
		        free(tmp->sig); //borrar direcion de memoria 
		        tmp->sig=NULL;			
		    }
		    else{
			    Lista=Iniciar(Lista);
		    }
		}
	}
	else{
		draw_text(4,2,"Lista vasia");
	}
	
	return Lista;
}

Node *eliminar(Node *Lista,int num){
    if(Lista!=NULL){
		Node *tmp;
		tmp=Lista;
		
		int index=1;
		//comprobar si es la primera posicion 
		if(num==index){
			Lista=Lista->sig; //quitar de la lista
			free(tmp); //borrar direcion de memoria
		}
		else{
			//avanzar por todo el arreglo
			while(index!=num-1){
				tmp=tmp->sig;
				index++;
			}
			
			Node *tmp2=tmp->sig;
			tmp->sig=tmp->sig->sig;
			free(tmp2);
		}
		
    }
    else{
    	draw_text(4,2,"Lista vasia");
	}
	
	return Lista;
}

Node *eliminar_id(Node *Lista,int id){
    if(Lista!=NULL){
		Node *tmp;
		tmp=Lista;
		
		//comprobar si es la primera posicion 
		if(Lista->IDE==id){
			Lista=Lista->sig; //quitar de la lista
			free(tmp); //borrar direcion de memoria
		}
		else{
			//avanzar por todo el arreglo
			while(tmp->sig->IDE!=id){
				tmp=tmp->sig; //avanzar 
			}
			
			//preguntar si son iguales los id 
			if(tmp->sig->IDE==id){
			    Node *tmp2=tmp->sig;
			    tmp->sig=tmp->sig->sig;
			    free(tmp2);	
			}
		}
		
    }
    else{
    	draw_text(4,2,"Lista vasia");
	}
	
	return Lista;
}
