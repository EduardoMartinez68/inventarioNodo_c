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