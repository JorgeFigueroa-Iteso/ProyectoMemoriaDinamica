#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void iniciarTabla (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], int row, int column);
void iniciarJuego(char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], 
					int row, int column, int dif
					);

// void print (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], int row, int column);

void printUser (char matrix[SIZE][SIZE], int row, int column);
void printBot(char matrixBot[SIZE][SIZE], int row, int column);

// void celda(char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE]);

void mostrarMenu(int, int, int);

int main (){

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

    char userMatrix[SIZE][SIZE];
    char botMatrix[SIZE][SIZE];
    char op;

    int row=15, col=15, x, y;
    int dif=1;

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
		    	iniciarJuego(userMatrix, botMatrix, row, col, dif);
		    	
				break;
		}
	}while(op!='d');

    return 0;
}

void iniciarTabla (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], int row, int column){
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
        	*(*(matrix+i)+j) == 0;
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
        	*(*(matrixBot+i)+j) == 0;
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
void printUser (char matrix[SIZE][SIZE], int row, int column){
	printf("--Matriz Usuario--\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            // printf("%d ", matrix[i][j]);
            printf("%d ", *(*(matrix+i)+j));
        }
        printf("\n");
    }
}

void printBot (char matrixBot[SIZE][SIZE], int row, int column){
	printf("--Matriz Maquina--\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            // printf("%d ", matrix[i][j]);
            printf("%d ", *(*(matrixBot+i)+j));
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

void iniciarJuego(char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], 
					int row, int col, int dif){
	switch (dif){
		case 1:
			printf("Dificultad 1\n");
			printUser (matrix, row, col);
			printBot (matrixBot, row, col);

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