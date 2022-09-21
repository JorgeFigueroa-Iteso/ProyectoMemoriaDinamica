#include <stdio.h>
#define SIZE 100

void ins (char matrix1[SIZE][SIZE], char matrix2[SIZE][SIZE], int row, int column);
void print (char matrix1[SIZE][SIZE], char matrix2[SIZE][SIZE], int row, int column);
void celda(char matrix1[SIZE][SIZE]);

int main (){

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

    char userMatrix[SIZE][SIZE];
    char botMatrix[SIZE][SIZE];
    int row, col, x, y;

    printf("Input rows: ");
    scanf  ("%d", &row);
    printf("Input columns: ");
    scanf  ("%d", &col);

    printf ("Input data: \n");
    ins(userMatrix, botMatrix, row, col);

    printf ("\nMatrices--\nMatriz 1:\n");
    print(userMatrix, botMatrix, row, col);

    // printf("Celda a modificar: ");
	celda(userMatrix);
    printf("Celda modificada:\n");
    print(userMatrix, botMatrix, row, col);

    return 0;
}

void ins (char matrix1[SIZE][SIZE], char matrix2[SIZE][SIZE], int row, int column){
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
        	*(*(matrix1+i)+j) == 0;
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
        	*(*(matrix2+i)+j) == 0;
        }
    }
}

void print (char matrix1[SIZE][SIZE], char matrix2[SIZE][SIZE], int row, int column){
    int i;
    int j;

    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            // printf("%d ", matrix[i][j]);
            printf("%d ", *(*(matrix1+i)+j));
        }
        printf("\n");
    }

    printf("Matriz 2:\n");

    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            // printf("%d ", matrix[i][j]);
            printf("%d ", *(*(matrix2+i)+j));
        }
        printf("\n");
    }
}

void celda (char matrix1[SIZE][SIZE]){
	int x, y, nc;
	printf("Coordenadas de la celda a modificar: \nx: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	printf("Numero a asignar: ");
	scanf("%d", &nc);
	*(*(matrix1+x)+y) = nc-1;
}