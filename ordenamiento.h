#include "guardar_archivo.h"
bool repeticion_nodo(Node *Lista,int nuevo_id){
    bool nuevo=true;
	//preguntar si es la primera de la lista 
	if(Lista!=NULL){
	    //recorrer la lista;
	    Node *tmp;
	    tmp=Lista;
	    
	    //si es el primer arreglo de la lista 
	    if(tmp->IDE==nuevo_id){
	    	nuevo=false;
		}
		else{
			//avanzar por la lista 
			while(tmp->sig !=NULL){
				//preguntar si se repite 
				if(tmp->IDE==nuevo_id){
					nuevo=false;
					break;
				}
				tmp=tmp->sig; //avanzar 
			}
			
			//preguntar si se repite el ultimo ID se repite  
			if(tmp->IDE==nuevo_id){
				nuevo=false;
			}
		}
	}
	
	return nuevo;
}

int nueva_ID(Node *Lista){
    int ID;
	ID=validaEntero("Dame el nuevo ID: ",3,3);
	//ver si se repite 
	 while((repeticion_nodo(Lista,ID))==false){
	 	ID=validaEntero("ID repetido: ",3,3);
	 }
	 
	 return ID;
}
