#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comentarios
// Debe mostrar un menu principal, el cual muestre lo siguiente:
// Dimension del tablero
// Seleccion de dificultad: - Didáctico - Fácil
// Iniciar juego
// Salir


// --------------------------------------------------------------- //

// Declaracion de Tipos de Datos

void mostrarMenu();
void dimensionTab();
void selecDificult();
void initJuego();


// --------------------------------------------------------------- //

// Declaracion de Estructuras


// --------------------------------------------------------------- //

int main(void){

	// Declracion de variables
	int a = 0;
	char op;

	// Codigo para el juego
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	do{
		mostrarMenu();
		printf("Seleccione una opcion (a-d): \n");
		scanf("%c", &op);
		switch(op){
			case 'a':
				printf("Selecciono la opcion a.\n");
				dimensionTab();
				break;
			case 'b':
				printf("Selecciono la opcion b.\n");
				selecDificult();
				break;
			case 'c':
				initJuego();
				printf("Selecciono la opcion c.\n");
				break;
		}

	}while(op!='d');

	system("pause");
	return 0;
}

// --------------------------------------------------------------- //

// Espacio para utilizar las estructuras y tipos de datos

void mostrarMenu(){
	system("cls");
	printf("a. Dimension del tablero\n");
	printf("b. Seleccion de dificultad\n");
	printf("c. Iniciar Juego\n");
	printf("d. Salir\n");
}

void dimensionTab(){
	system("cls");
	printf("Dimensiones:\n");
	system("pause");
}

void selecDificult(){
	system("cls");
	// Didáctico - Ve el tablero de la pc
	// Fácil - Solo se vé el tablero del jugador
	printf("Dificultades:\n1.- Didactico\n2.- Facil\n");
	system("pause");
}

void initJuego(){
	system("cls");
	printf("Comienza el juego\n");
	// Imprimir la configuracion asignada para el juego
	system("pause");
}

// --------------------------------------------------------------- //





// Publicar cambios a GitHub:

// Pasos para actualizar el proyecto de Git desde Sublime Text:
// Es importante descargar antes la librería de Git, presionando ctrl + shift + p, después escribir Install Package, y posteriormente buscar a la librería "Git"
// Para acceder al menú donde se puede modificar, actualizar y publicar el repositorio, se accede a través de: ctrl + shift + p, y escribir lo siguiente
// Primero: Add All, después: Commit y por último el Push.


// Actualizar los cambios de Git a pc:

// Pasos para actualizar el proyecto de pc desde Sublime Text:
// Solo es necesario escribir "Pull"

// Ejecucion de perminal en SublimeText:

// Para sacar la consola, presione alt + t
// Para que la consola esté en la carpeta de trabajo, presione alt + c