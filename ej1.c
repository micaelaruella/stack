#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20

/*Declaración de tipos de datos personalizados*/
typedef char tString[15];
typedef struct{
	tString marcaTv;
	float pulgadasTv;
}tDatosTv;

typedef tDatosTv tArrayTeles [MAX];
typedef struct{
	tArrayTeles lista;
	int tope;
}tPila;

/*Declaración de variables globales.*/
tPila pila;

/*Declaración de prototipo*/
void crearPilaVacia();
bool pilaVacia(tPila);
bool pilaLlena(tPila);
void apilarTv(tString, float);
void visualizarTelevisoresApilados(tPila);
void desapilarTv();
tDatosTv cima (tPila);
bool sePuedeAgregar(float);
void televisionTope(tPila);
int  consultarPulgadasX(tPila);
void menu();

/*Funcion principal*/
int main (){
	crearPilaVacia();
	menu();
	return 0;
}

/*Desarrollo de funciones*/

void crearPilaVacia(){
	/*Inicializamos la pila en -1 ya que en el arreglo comienza desde 0*/
	pila.tope = -1; 
}

bool pilaVacia(tPila pPila){
	/*Si la pila está vacía retorna -1*/
	return (pPila.tope == -1 );
}

bool pilaLlena(tPila pPila){
	/*Si la pila está llena retorna 20(MAX)-1 = 19*/
	return (pPila.tope == (MAX - 1));	
}

void menu(){
	int menu;
	printf("### Menu de opciones ###\n");
	printf("0. Salir\n");
	printf("1. Apilar televisor\n");
	printf("2. Mostrar listado de televisores apilados\n");
	printf("3. Eliminar televisor\n");
	printf("4. Generar consulta sobre la cantidad de televisores con mayor pulgadas a uno ingresado\n");			
	printf("\nSeleccionar una opcion del menu: ");
	scanf("%d", &menu);
	system("cls");
	
	while (menu != 0){
		switch (menu){
			case 1: {
				tString marca;
				float pulgadas;
			
				if (!pilaLlena(pila)){
					printf("Ingresar marca del televisor: ");
					fflush(stdin);
					gets(marca);
					printf("Ingresar pulgadas del televisor: ");
					scanf("%f", &pulgadas);	
						
					if(sePuedeAgregar (pulgadas)){
						apilarTv(marca, pulgadas);
					}else{
						printf("No se puede apilar un televisor mas grande encima de una mas peque%ca!\n", 164);
					}
				}else{
					printf("Pila llena!\n");
				}
				break;
			}
			case 2: {
				visualizarTelevisoresApilados(pila);
				break;
			}
			case 3:{
				desapilarTv();
				break;
			}
			case 4:{
				printf("La cantidad de televisores apilados con mayor pulgadas al numero de pulgadas X que ingreso es: %d\n ", consultarPulgadasX(pila));
				break;
			}
		}
	system("pause");/*Genera una pausa en pantalla*/
	system("cls");
	printf("### Menu de opciones ###\n");
	printf("0. Salir\n");
	printf("1. Apilar televisor\n");
	printf("2. Mostrar listado de televisores apilados\n");
	printf("3. Eliminar televisor\n");
	printf("4. Generar consulta sobre la cantidad de televisores con mayor pulgadas a uno ingresado\n");			
	printf("\nSeleccionar una opcion del menu: ");
	scanf("%d", &menu);
	system("cls");	
	}
}

void apilarTv (tString pMarca, float pPulgadas){
	/*Verificar que haya espacio libre*/
	if (pilaLlena(pila) != true){
		pila.tope = pila.tope + 1; /*Actualiza tope*/
		strcpy(pila.lista[pila.tope].marcaTv, pMarca); 
		pila.lista[pila.tope].pulgadasTv = pPulgadas;
		printf("Televisor apilado!\n");
	}else{
		printf("Pila llena!");
	}
}

void desapilarTv (){
	/*Verificar que haya espacio ocupado*/
	if(pilaVacia(pila) == true){
		printf("Pila vacia! \n");
	}else{
		pila.lista[pila.tope].pulgadasTv = 0;
		pila.tope = pila.tope - 1;
		printf("Televisor eliminado!\n");
		televisionTope(pila); 
	}
}

void televisionTope(tPila pPila){
	printf("El televisor que se encuentra en el tope es: %s | %.2f'' \n", pPila.lista[pPila.tope].marcaTv, pPila.lista[pPila.tope].pulgadasTv);
	
}

tDatosTv cima (tPila pPila){
	return (pPila.lista[pPila.tope]);
}


bool sePuedeAgregar(float pPulgadas){
	if(pilaVacia(pila)){
		return true;
	}else if ( pPulgadas < cima (pila).pulgadasTv ){ 
		return true;
	}else{
		return false;
	}
}


void visualizarTelevisoresApilados(tPila pPila){
	int i;
	/*Verificar que haya elementos para mostrar*/
	if(pilaVacia(pila)){
		printf("No hay televisores apilados para mostrar! \n");
	}else{
		printf("Lista de elementos: \n");
		for (i=0; i<=pPila.tope; i++){
			printf("Televisor n %d : \n\t\tMarca:  %s | Pulgadas:  %.2f'' \n", i+1,  pPila.lista[i].marcaTv, pPila.lista[i].pulgadasTv);	
			printf("");		
		}
	}
}


int consultarPulgadasX(tPila pPila){
	int i, cantidad = 0;
	float pulgadasX;
	printf("Ingrese X pulgadas de un televisor: ");
	scanf("%f", &pulgadasX);
	for (i=0; i<=pPila.tope; i++){
		if (pPila.lista[i].pulgadasTv >= pulgadasX){
			cantidad++;
		}
	}
	return cantidad;	
}


