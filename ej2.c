#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

/*Declaración de tipos de datos personalizados*/
typedef char tString[20];

typedef struct{
	tString titulo;
	tString editorial;
	int isbn;
}tDatos;

typedef tDatos tArrayLibros[MAX];
typedef struct{
	tArrayLibros lista;
	int tope;
}tPila;

/*Declaración de variables globales*/
tPila pila;

/*Declaración de prototipo*/
void crearPilaVacia();
bool pilaVacia(tPila);
bool pilaLlena(tPila);
void apilarLibro(tString, tString, int);
void listarUltimosLibros(tPila);
void libroTope(tPila);
void desapilarLibro();
void menu();

/*Función principal*/
int main(){
	crearPilaVacia();
	menu();
	return 0;
}

/*Desarrollo de funciones*/
void crearPilaVacia(){
	pila.tope = -1; 
}

bool pilaVacia(tPila pPila){
	return (pPila.tope == -1);	
}

bool pilaLlena(tPila pPila){
	return (pPila.tope == (MAX-1));
}

void menu(){
	int menu;
	printf("\t\t*************************************************\n");
	printf("\t\t*\t\tMenu de opciones\t\t*\n");
	printf("\t\t*\t\t---------------\t\t\t*\n");
	printf("\t\t*\t1. Ingresar datos del libro\t\t*\n");
	printf("\t\t*\t2. Listar los ultimos 5 libros\t\t*\n");
	printf("\t\t*\t3. Eliminar libro\t\t\t*\n");
	printf("\t\t*\t4. Mostrar libro en tope\t\t*\n");
	printf("\t\t*\t0. Salir\t\t\t\t*\n");
	printf("\t\t*************************************************\n");
	
	printf("\nSeleccione una opcion del menu:");
	
	scanf("%d", &menu);
	system("cls");
	
	while (menu != 0){
		switch (menu){
			case 1: {
				int isbn;
				tString titulo;
				tString editorial;
				
				if(!pilaLlena(pila)){ 
					printf("ISBN (Identificador unico para libros): ");
					scanf("%d", &isbn);
					printf("Titulo del libro: ");
					fflush(stdin);
					gets(titulo);
					printf("Editorial del libro: ");
					fflush(stdin);
					gets(editorial);
			
					apilarLibro (titulo, editorial, isbn);
					
				}else{
					printf("Pila llena!\n");
				}
				
				break;
			}
			case 2: {
				listarUltimosLibros(pila);
				break;
			}
			case 3: {
				desapilarLibro();
				break;
			} 
			case 4:{
				libroTope(pila);
				break;
			}
			default : printf("La opcion ingresada es incorrecta. Ingrese otra opcion\n");
		}
	
	system("pause");
	system("cls");	
	printf("\t\t*************************************************\n");
	printf("\t\t*\t\tMenu de opciones\t\t*\n");
	printf("\t\t*\t\t---------------\t\t\t*\n");
	printf("\t\t*\t1. Ingresar datos del libro\t\t*\n");
	printf("\t\t*\t2. Listar los ultimos 5 libros\t\t*\n");
	printf("\t\t*\t3. Eliminar libro\t\t\t*\n");
	printf("\t\t*\t4. Mostrar libro en tope\t\t*\n");
	printf("\t\t*\t0. Salir\t\t\t\t*\n");
	printf("\t\t*************************************************\n");
	
	printf("\nSeleccione una opcion del menu:");
	
	scanf("%d", &menu);
	system("cls");
	}
}

void apilarLibro(tString pTitulo, tString pEditorial, int pIsbn){
	if(!pilaLlena(pila)){
		pila.tope++;
		strcpy(pila.lista[pila.tope].titulo, pTitulo);
		strcpy(pila.lista[pila.tope].editorial, pEditorial);
		pila.lista[pila.tope].isbn = pIsbn;

	}else{
		printf("Pila llena!\n");
	}
}

void desapilarLibro(){
	if(pilaVacia(pila)){
		printf("Pila vacia!\n");
	}else{

		pila.lista[pila.tope].isbn = 0;

		pila.tope--;
		printf("Libro eliminado!\n");
	}
}

void libroTope(tPila pPila){
	if(pilaVacia(pila)){
		printf("No hay libro en el tope porque la pila esta vacia!\n");
	}else{
		printf("El libro que se encuentra en el tope es: \n");
		
		printf(" \n| ISBN\t | Titulo\t |  Editorial\t  |");

		printf("\n  %d\t  '%s'\t   %s\t \n\n", pPila.lista[pPila.tope].isbn, pPila.lista[pPila.tope].titulo, pPila.lista[pPila.tope].editorial);
	}	
}

void listarUltimosLibros(tPila pPila){
	int i;
	int  ultimosLibros = pPila.tope-4;/**/	
	
	if (pilaVacia(pila)){
		printf("No hay libros apilados para mostrar\n");
	}else if(pPila.tope+1 >= 5){ /*Tope debe ser mayor o igual a 5*/
		printf("Listado de los ultimos 5 libros apilados: \n");
		for (i=pPila.tope; i>=ultimosLibros; i--){/*Va desde tope hasta los últimos 5 decrementando.*/
						
			printf("Libro nro %d: %d | %s | %s \n", i+1, pPila.lista[i].isbn, pPila.lista[i].titulo, pPila.lista[i].editorial);
		}
	}else{
		printf("Hay menos de 5 libros. Apile mas libros!\n");
	}			
}

