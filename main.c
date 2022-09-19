#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comentarios*
// Debe mostrar un menu principal, el cual muestre lo siguiente:
// Dimensión del tablero
// Selección de dificultad: - Didáctico - Fácil
// Iniciar juego
// Salir


// --------------------------------------------------------------- //

// Declaración de Tipos de Datos



// --------------------------------------------------------------- //

// Declaración de Estructuras

void mostrarMenu();
void dimensionTab();

// --------------------------------------------------------------- //

int main(void){

	// Declración de variables
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
				break;
			case 'c':
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
	printf("a. Dimensión del tablero\n");
	printf("b. Selección de dificultad\n");
	printf("c. Iniciar Juego\n");
	printf("d. Salir\n");
}

void dimensionTab(){
	printf("Dimensiones:\n");
}

// --------------------------------------------------------------- //





// Publicar cambios a GitHub:

// Pasos para actualizar el proyecto de Git desde Sublime Text:
// Es importante descargar antes la librería de Git, presionando ctrl + shift + p, después escribir Install Package, y posteriórmente buscar a la librería "Git"
// Para acceder al menú donde se puede modificar, actualizar y publicar el repositorio, se accede a través de: ctrl + shift + p, y escribir lo siguiente
// Primero: Add All, después: Commit y por último el Push.


// Actualizar los cambios de Git a pc:

// Pasos para actualizar el proyecto de pc desde Sublime Text:
// Solo es necesario escribir "Pull"

// Ejecución de perminal en SublimeText:

// Para sacar la consola, presione alt + t
// Para que la consola esté en la carpeta de trabajo, presione alt + c