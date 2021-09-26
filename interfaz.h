#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string>
void gotoxy(int x,int y);
void printf(int x,int y,string texto);
void cuadro(int x1,int y1,int x2,int y2);
void interfaz();

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void draw_rectangle(int x1,int y1,int x2,int y2){
	for(int i=x1;i<x2;i++){
		gotoxy(i,y1);printf("*"); //linea horizontal superior
		gotoxy(i,y2);printf("*"); //linea horizontal inferior
	}
	
	for(int i=y1;i<y2;i++){
		gotoxy(x1,i);printf("*"); //linea vertical izquierda
		gotoxy(x2,i);printf("*"); //linea vertical derecha		
	}
	
	//esquinas del cuadrado
	gotoxy(x1,y1);printf("*"); 
	gotoxy(x1,y2);printf("*"); 
	gotoxy(x2,y1);printf("*"); 
	gotoxy(x2,y2);printf("*"); 	
}

void draw_text(int x,int y,string texto){
	gotoxy(x,y);cout<<texto;
}


void interfaz(){
	system("COLOR B0"); //color de fonod y color de letras
}