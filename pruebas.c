#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void ins (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], int row, int column);
void print (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], int row, int column);
void celda(char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE]);

void mostrarMenu();

int main (){

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

    char userMatrix[SIZE][SIZE];
    char botMatrix[SIZE][SIZE];
    char op;

    int row=15, col=15, x, y;
    int dif=1;

    printf ("Input data: \n");
    ins(userMatrix, botMatrix, row, col);

    do{
		system("cls");
		mostrarMenu();
		// printf("Seleccione una opcion (a-e): \n");
		scanf("%c", &op);
		switch(op){
			case 'a':
			    printf("Input rows: ");
				scanf  ("%d", &row);
				printf("Input columns: ");
				scanf  ("%d", &col);
				ins(userMatrix, botMatrix, row, col);
			case 'b':
				printf("Imprimir matriz a.\n");
				print(userMatrix, botMatrix, row, col);
				break;
			case 'c':
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
		}
	}while(op!='e');

/*    printf ("You entered: \n");
    print(userMatrix, botMatrix, row, col);

    // printf("Celda a modificar: ");
	celda(userMatrix);
    printf("Celda modificada:\n");
    print(userMatrix, botMatrix, row, col);
*/
    return 0;
}

void ins (char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE], int row, int column){
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

void mostrarMenu(){
	system("cls");
	printf("a. Dimension del tablero\n");
	printf("b. Ver tablero\n");
	printf("c. Seleccion de dificultad\n");
	printf("d. Iniciar Juego\n");
	printf("e. Salir\n");
}