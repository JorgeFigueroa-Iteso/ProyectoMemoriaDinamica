#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

/*
#define P 5
#define B 4
#define S 3
#define C 2
#define L 1
*/

typedef struct{
	int estadoCelda;
	int idBarco;
	int impactoBarco;
}CELDA;

typedef struct{
	char tipoBarco;
	char orientacionBarco;
	int sunk;
}NAVE;

/*

Portaviones - 5
Buque - 4
Submarino - 3
Crucero - 2
Lancha - 1
Bungalo - 0 :)

*/

void iniciarTabla (CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE], 
					int row, int column);
void iniciarJuego (CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE], 
					int row, int column, int dif, int coordx, int coordy, int turno);
void hacerBarco (NAVE barcoUsuario, NAVE barcoBot, int x, int y);

// void print (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], int row, int column);

void printUser (CELDA matrix[SIZE][SIZE], int row, int column);
void printBot  (CELDA matrixBot[SIZE][SIZE], int row, int column);

void bombardeoAUsuario (CELDA matrix[SIZE][SIZE], int row, int column);
void bombardeoABot (CELDA matrixBot[SIZE][SIZE], int row, int column);

// void celda(char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE]);

void mostrarMenu(int, int, int);

int main (){

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

    CELDA userMatrix[SIZE][SIZE];
    CELDA botMatrix[SIZE][SIZE];
    char op;

    int row=10, col=10, x, y;
    int dif=1;
    int cambio = 0;
	
	int coordx, coordy;

    printf ("Input data: \n");

    do{
		system("cls");
		mostrarMenu(row, col, dif);
		// printf("Seleccione una opcion (a-e): \n");
		scanf("%c", &op);

		switch(op){
			case 'a':
			    printf("Input rows: ");
				scanf  ("%d", &row);
				printf("Input columns: ");
				scanf  ("%d", &col);
				iniciarTabla(userMatrix, botMatrix, row, col);

				break;
			case 'b':
				printf("Seleccion de dificultad:\n(1) - Por Default\n");
				printf("Dificultades disponibles:\n1.- Didactico\n2.- Facil\nnumero de la dificultad: ");
				scanf("%d", &dif);
				if (dif==1)
				{
					printf("Dificultad: Didactico\n");
				} else{
					printf("Dificultad: Facil\n");
				}
				system("timeout /t 3\n");

				break;
			case 'c':
		    	iniciarTabla(userMatrix, botMatrix, row, col);
		    	// bombardeoAUsuario(userMatrix, coordx, coordy);

		    	iniciarJuego(userMatrix, botMatrix, row, col, dif, coordx, coordy, cambio);

				break;

			case 'z':
				printf("Coordenadas a atacar:\nx:");
				scanf("%d", &coordx);
				printf("y:");
				scanf("%d", &coordy);
				

				system("timeout /t 3");
				break;
		}
	}while(op!='d');

    return 0;
}

void iniciarTabla (CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE], int row, int column){
    int i, j;

    CELDA *celda;

    for (i = 0; i < row; i++){
    	celda=*(matrix+i);
        for (j = 0; j < column; j++){
        	(celda+j) -> estadoCelda=0;
        	(celda+j) -> idBarco=0;
        	(celda+j) -> impactoBarco=0;
        	// *(*(matrix+i)+j) == 0;
        }
    }

    for (i = 0; i < row; i++){
    	celda=*(matrixBot);
        for (j = 0; j < column; j++){
        	(celda+j) -> estadoCelda=0;
        	(celda+j) -> idBarco=0;
        	(celda+j) -> impactoBarco=0;
        	// *(*(matrixBot+i)+j) == 0;
        }
    }
}

/*
void print (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], int row, int column){
    int i;
    int j;
    printf("--Matriz 1--\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            // printf("%d ", matrix[i][j]);
            printf("%d ", *(*(matrix+i)+j));
        }
        printf("\n");
    }
    printf("--Matriz 2--\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            // printf("%d ", matrix[i][j]);
            printf("%d ", *(*(matrixBot+i)+j));
        }
        printf("\n");
    }

    system("timeout /t 3\n");
}
*/
void printUser (CELDA matrix[SIZE][SIZE], int row, int column){
	printf("--Matriz Usuario--\n");
	CELDA *celda;
    for(int i=0; i<row; i++){
    	celda=*(matrix+i);
        for(int j=0; j<column; j++){

            // printf("%d ", matrix[i][j]);
            // printf("%d ", ((celda+j) -> estadoCelda));
            printf("%d ", ((celda+j) -> impactoBarco));
        }
        printf("\n");
    }
}

void printBot (CELDA matrixBot[SIZE][SIZE], int row, int column){
	printf("--Matriz Maquina--\n");
	CELDA *celda;
    for(int i=0; i<row; i++){
    	celda=*(matrixBot+i);
        for(int j=0; j<column; j++){

            // printf("%d ", matrix[i][j]);
            // printf("%d ", ((celda+j) -> estadoCelda));
            printf("%d ", ((celda+j) -> impactoBarco));
        }
        printf("\n");
    }
}

/*
void celda (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE]){
	int x, y, nc;
	printf("Coordenadas de la celda a modificar - Matriz 1: \nx: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	printf("Numero a asignar: ");
	scanf("%d", &nc);

	*(*(matrix+x-1)+y-1) = nc;

	printf("Coordenadas de la celda a modificar - Matriz 2: \nx: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	printf("Numero a asignar: ");
	scanf("%d", &nc);

	*(*(matrixBot+x-1)+y-1) = nc;

	system("timeout /t 3\n");
}
*/

void mostrarMenu(int x, int y, int dif){
	system("cls");
	printf("a. Dimension del tablero - %dx%d\n", x,y);
	printf("b. Seleccion de dificultad - %d\n", dif);
	printf("c. Iniciar Juego\n");
	printf("d. Salir\n");
}


/*-----------------------------------------------------------------*/

// Juego

void bombardeoAUsuario (CELDA matrix[SIZE][SIZE], int row, int column){

	srand(time(NULL));
    int x, y;
    x = rand() % 9;
    y = rand() % 9;
    printf("%d\n%d\n", x+1,y+1);

	CELDA *celda;

	celda=*(matrix+y);

	if (((celda+x) -> impactoBarco) == 0)
	{
		printf("Se registro un golpe por parte del bot.\n");
		(celda+x) -> impactoBarco=1;
	}

	// printf("%d\n", ((celda+x) -> impactoBarco));

	system("timeout /t 5");
}

void bombardeoABot (CELDA matrixBot[SIZE][SIZE], int x, int y){
	CELDA *celda;

	celda=*(matrixBot+x);

	(celda+y) -> impactoBarco=1;

	printf("%d\n", ((celda+y) -> impactoBarco));

	system("timeout /t 3");
}

void iniciarJuego(CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE], 
					int row, int col, int dif, int coordx, int coordy, int turno){
	switch (dif){

		case 1:
			printf("Dificultad 1\n");

			do{
				printUser (matrix, row, col);
				printBot (matrixBot, row, col);

				printf("\n\n---Coordenadas a atacar---\nx: ");
				scanf("%d", &coordx);
				printf("y: ");
				scanf("%d", &coordy);

				bombardeoABot(matrixBot, coordx-1, coordy-1);
				printf("Turnos: %d\n", turno);
				turno++;

			} while (turno!=3);

			bombardeoAUsuario(matrix, row, col);

			printUser (matrix, row, col);
			printBot (matrixBot, row, col);

			
			// printBot (matrixBot, row, col);

			break;

		case 2:
			printf("Dificultad 2\n");
			printUser (matrix, row, col);			

			break;

		default:
			printf("La dificultad no coincide, pruebe de nuevo.\n");
			break;
	}

	system("timeout /t 3\n");
}



/*-----------------------------------------------------------------*/