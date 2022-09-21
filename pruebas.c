#include <stdio.h>
#define SIZE 100

void ins (char matrix[SIZE][SIZE], int row, int column);
void print (char matrix[SIZE][SIZE], int row, int column);
void celda(char matrix[SIZE][SIZE]);

int main (){

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

    char userMatrix[SIZE][SIZE];
    char botMAtrix[SIZE][SIZE];
    int row, col, x, y;

    printf("Input rows: ");
    scanf  ("%d", &row);
    printf("Input columns: ");
    scanf  ("%d", &col);

    printf ("Input data: \n");
    ins(userMatrix, row, col);

    printf ("You entered: ");
    print(userMatrix, row, col);

    // printf("Celda a modificar: ");
	celda(userMatrix);
    printf("Celda modificada:\n");
    print(userMatrix, row, col);

    return 0;
}

void ins (char matrix[SIZE][SIZE], int row, int column){
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
        	*(*(matrix+i)+j) == 0;
        }
    }
}

void print (char matrix[SIZE][SIZE], int row, int column){
    int i;
    int j;

    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            // printf("%d ", matrix[i][j]);
            printf("%d ", *(*(matrix+i)+j));
        }
        printf("\n");
    }
}

void celda (char matrix[SIZE][SIZE]){
	int x, y, nc;
	printf("Coordenadas de la celda a modificar: \nx: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	printf("Numero a asignar: ");
	scanf("%d", &nc);
	*(*(matrix+x)+y) = nc;
}