// Ramón
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comentarios*

// Debe mostrar un menu principal, el cual muestre lo siguiente:
// Dimension del tablero
// Seleccion de dificultad: - Didáctico - Fácil
// Iniciar juego
// Salir

// --------------------------------------------------------------- //

// Globales

int Filas=10,Columnas=10;

int matrizUsuario;

// --------------------------------------------------------------- //

#define usoCeldas 30
#define modoDeJuego 0

// --------------------------------------------------------------- //

// Declaracion de Tipos de Datos

void iniciarJuego(int *userX, int *userY, short *modo_de_juego);
void boardInit(char (*board)[], int *x, int *y);
void drawBoard(char (*board)[], int *x, int *y);

void mostrarMenu();
void dimensionTab();
void dimension(int, int);
void selecDificult();
void initJuego();
void mostrarTablero(int, int);
// void boatdet(int, int);


// --------------------------------------------------------------- //

// Declaracion de Estructuras

typedef struct celda{
	short estado_de_cenda;
	int id_barco;
	short golpe;
}celda;

typedef struct barco{
	char tipo_de_barco[3];
	char orientacion;
	short a_flote;
}barco;

// --------------------------------------------------------------- //

int main(void){

	// Declracion de variables
	char op;
	char user;
	

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
			case 'z':
				boardInit(user, 10, 10);
				drawBoard();
		}

	}while(op!='d');

	system("pause");
	return 0;
}

// --------------------------------------------------------------- //

// Espacio para utilizar las estructuras y tipos de datos

void iniciarJuego(int *userX, int *userY, short *modo_de_juego){
	if (userX && userY != 0){
		Filas = *userX;
		Columnas = *userY;
		char board[Filas][Columnas];
		boardInit(board, userX, userY);
		drawBoard(board, userX, userY);
	} else{
		char board[Filas][Columnas];
		boardInit(board, userX, userY);
		drawBoard(board, userX, userY);
	}
}

void boardInit(char (*board)[Columnas], int *x, int *y){
	for (int i = 0; i < (*y); ++i)
	{
		for (int j = 0; j < (*x); ++j)
		{
			*(*(board+i)+j) = ' ';
		}
	}
}

void drawBoard(char (*board)[Columnas], int *x, int *y){
	printf("\n | B-S");
	for (int k = 0; k < (*x); ++k)
	{
		printf("| %c ", ('A'+k));
	}
	printf("|\n");

	printf("------");
	for (int k = 0; k < (*x); ++k)
	{
		printf("----");
	}
	printf("\n");

	for (int i = 0; i < (*y); ++i)
	{
		printf("| %.3d\n", i+1);
		for (int j = 0; j < (*x); ++j)
		{
			printf("| %c\n", *(*(board+i)+j));
		}
		printf("|\n");

		printf("------");
		for (int k = 0; k < (*x); ++k)
		{
			printf("-----");
		}
		printf("\n");
	}
}





void mostrarMenu(){
	system("cls");
	printf("a. Dimension del tablero\n");
	printf("b. Seleccion de dificultad\n");
	printf("c. Iniciar Juego\n");
	printf("d. Salir\n");
}

void dimensionTab(){
	system("cls");
	int X, Y;

	printf("Dimensiones del tablero:\nx: ");
	scanf("%d", &X);
	printf("y: ");
	scanf("%d", &Y);
	// printf("Dimenciones asignadas: %d, %d\n", X,Y);
	dimension(X,Y);
	// mostrarTablero(X,Y);
	system("timeout /t 3\n");
}

void dimension(int Filas, int Columnas){
	printf("Dimecion Final: %d, %d\n", Filas,Columnas);

	int matrizUsuario[Filas][Columnas];
	int matrizPC[Filas][Columnas];
	int *pMatrizUsuario;

	for (int i = 0; i < Filas; ++i)
	{
		for (int j = 0; j < Columnas; ++j)
		{

			*(*(matrizUsuario+i)+j) = 0;
			*(*(matrizPC+i)+j) = 0;
			printf("%d  ", *(*(matrizUsuario+i)+j));

		}
		printf("\n");
	}

}

void selecDificult(){
	system("cls");

	int opDificultad;

	// Didáctico - Ve el tablero de la pc
	// Fácil - Solo se vé el tablero del jugador
	printf("1.- Didactico\n2.- Facil\nDificultad: ");

	scanf("%d", &opDificultad);
	printf("Opcion seleccionada: %d\n", opDificultad);
	system("timeout /t 3\n");
}

void initJuego(){
	system("cls");
	printf("Comienza el juego\n");
	// Imprimir la configuracion asignada para el juego

	system("pause");
}

// void mostrarTablero(int x1, int Columnas1){
// 	printf("%d, %d\n", x1,y1);
// 	int matrizUsuario[][];

// 	for (int i = 0; i < x1; ++i)
// 	{
// 		for (int j = 0; j < y1; ++j)
// 		{
// 			printf("%d  ", *(*(matrizUsuario+i)+j));
// 		}
// 		printf("\n");
// 	}
// }

// void boatdet(int **x, int **y){

// 	dimension(x,y);
// 	int *aux_1, *aux_2;
// 	aux_1 = x;
// 	aux_2 = y;
	


// }

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