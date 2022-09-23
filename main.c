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
	char estadoCelda;
	int idBarco;
	int impactoBarco;
}CELDA;

typedef struct{
	int tipoBarco;
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
void mostrarMenu(int, int, int);
void mostrarBarco();

void iniciarTabla (CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
				NAVE barcosDeUsuario[SIZE][SIZE], NAVE barcosDeBot[SIZE][SIZE],
					 int row, int column);
void iniciarJuego (CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
					NAVE barcosDeBot[SIZE][SIZE], NAVE barcosDeUsuario[SIZE][SIZE], 
					int row, int column, int dif, int coordx, int coordy, int turno);

void hacerBarco (NAVE barcosDeUsuario[SIZE][SIZE], NAVE barcoBot[SIZE][SIZE],
				CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
				int xt, int yt);

void print (NAVE barcosDeBot[SIZE][SIZE]);

void printUser (CELDA matrix[SIZE][SIZE], NAVE barcosDeUsuario[SIZE][SIZE], int row, int column);
void printBot  (CELDA matrixBot[SIZE][SIZE], int row, int column);

void bombardeoAUsuario (CELDA matrix[SIZE][SIZE], int row, int column);
void bombardeoABot (CELDA matrixBot[SIZE][SIZE], int row, int column);

// void celda(char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE]);


int main (){

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

    CELDA userMatrix[SIZE][SIZE];
    CELDA botMatrix[SIZE][SIZE];

    NAVE barcosDeBot[SIZE][SIZE];
    NAVE barcosDeUsuario[SIZE][SIZE];

    char op;

    int row=10, col=10, x, y;
    int dif=1;
    int cambio = 0;
	
	int coordx, coordy;

    printf ("Input data: \n");

    do{
		system("cls");
		printf("%c\n", barcosDeBot);
		mostrarBarco();
		mostrarMenu(row, col, dif);
		// print(barcosDeBot);
		// printf("Seleccione una opcion (a-e): \n");
		scanf("%c", &op);

		switch(op){
			case 'a':
			    printf("Input rows: ");
				scanf  ("%d", &row);
				printf("Input columns: ");
				scanf  ("%d", &col);
				// iniciarTabla(userMatrix, botMatrix, row, col);

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
		    	iniciarTabla(userMatrix, botMatrix, barcosDeUsuario, barcosDeBot,row, col);

		    	// bombardeoAUsuario(userMatrix, coordx, coordy);

		    	iniciarJuego(userMatrix, botMatrix, barcosDeBot, barcosDeUsuario,row, col, dif, coordx, coordy, cambio);

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

void iniciarTabla (CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
				NAVE barcosDeUsuario[SIZE][SIZE], NAVE barcosDeBot[SIZE][SIZE],
					int row, int column){
    int i, j;

    CELDA *celda;
    NAVE *nave;

    for (i = 0; i < row; i++){
    	celda=*(matrix+i);
    	nave=*(barcosDeUsuario+i);
        for (j = 0; j < column; j++){
        	(celda+j) -> estadoCelda='0';
        	(celda+j) -> idBarco=0;
        	(celda+j) -> impactoBarco=0;
        	// (celda+j) -> tipoDeBarco=0;
        	// *(*(matrix+i)+j) == 0;
        	(nave+j) -> tipoBarco=0;
        	(nave+j) -> orientacionBarco='V';
        	(nave+j) -> sunk=0;
        }
    }

    for (i = 0; i < row; i++){
    	celda=*(matrixBot+i);
    	nave=*(barcosDeBot+i);
        for (j = 0; j < column; j++){
        	(celda+j) -> estadoCelda='0';
        	(celda+j) -> idBarco=0;
        	(celda+j) -> impactoBarco=0;
        	// (celda+j) -> tipoDeBarco=0;
        	// *(*(matrixBot+i)+j) == 0;
        	(nave+j) -> tipoBarco=0;
        	(nave+j) -> orientacionBarco='V';
        	(nave+j) -> sunk=0;
        }
    }
}

void printUser (CELDA matrix[SIZE][SIZE], NAVE barcosDeUsuario[SIZE][SIZE], int row, int column){
	printf("   <--Matriz Usuario-->\n");
	CELDA *celda;
	NAVE *nave;
	printf("     ");
	for (int i = 0; i < column; ++i)
	{
		printf("%-3d ", i+1);
	}	printf("\n    ");
	for (int i = 0; i < column; ++i)
	{
		printf("----");
	} printf("\n");

    for(int i=0; i<row; i++){
    	celda=*(matrix+i);
    	nave=*(barcosDeUsuario+i);
    	printf("%2d |", i+1);
        for(int j=0; j<column; j++){

            // printf(" %2c ", ((celda+j) -> estadoCelda));
            // printf("%d ", ((celda+j) -> impactoBarco));

        	/*
            if (((celda+j) -> idBarco) != 0)
            {
            	printf(" %-2d ", ((celda+j) -> idBarco));
            } else{
            	printf("    ");
            }
            */

            // printf(" %2d ", ((celda+j) -> idBarco));
            // printf("%d", ((celda+j) -> tipoDeBarco));
            printf("%d", ((nave+j) -> tipoBarco));
        }
        printf("|\n");
    }	printf("    ");
	for (int i = 0; i < column; ++i)
	{
		printf("----");
	} printf("\n");
}

void printBot (CELDA matrixBot[SIZE][SIZE], int row, int column){
	printf("\n\n   <--Matriz Maquina-->\n");
	CELDA *celda;
	
	printf("     ");
	for (int i = 0; i < column; ++i)
	{
		printf("%-3d ", i+1);
	}	printf("\n    ");
	for (int i = 0; i < column; ++i)
	{
		printf("----");
	} printf("\n");

    for(int i=0; i<row; i++){
    	celda=*(matrixBot+i);
    	printf("%2d |", i+1);
        for(int j=0; j<column; j++){
            // printf("%d ", matrix[i][j]);
            // printf(" %2c ", ((celda+j) -> estadoCelda));
            // printf("%d ", ((celda+j) -> impactoBarco));

/*
            if (((celda+j) -> idBarco) != 0)
            {
            	printf(" %-2d ", ((celda+j) -> idBarco));
            } else{
            	printf("    ");
            }
            if (((celda+j-1) -> estadoCelda) == 'd')
            {
            	printf("  x  ");
            } else if (((celda+j-1) -> estadoCelda) == 'v')
            {
            	printf(" +  ");
            }
*/


            printf(" %2d ", ((celda+j) -> idBarco));
            // printf("%d ", ((celda+j) -> tipoDeBarco));
        }
        printf("|\n");
    }	printf("    ");
	for (int i = 0; i < column; ++i)
	{
		printf("----");
	} printf("\n");
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
	printf("a. Dimension del tablero - %dx%d\n", x,y);
	printf("b. Seleccion de dificultad - %d\n", dif);
	printf("c. Iniciar Juego\n");
	printf("d. Salir\n");
}

void mostrarBarco(){
	srand(time(NULL));
    int x;
    x = rand() % 2;
    // printf("%d\n", x);
    switch(x){
    	case 0:
			printf("                                             .								\n");
			printf("                           .                 |								\n");
			printf("                           +                 |								\n");
			printf("                  .        |                *+W+-*							\n");
			printf("     .           +y        +W+              . H                 .			\n");
			printf("  .  +y            |I.   y  |               ! H= .           .  ^			\n");
			printf("  !   \\     .     |H '. /   |  ___.        .! H  !   +--.--y !  V 			\n");
			printf("  !    \\     \\  +=|H|=='.=+ | |====\\   _  '_H_H__H_. H_/=  J !  !		\n");
			printf(". !     \'    VVV_HHH_/__'._H |  E  \\_|=|_|========|_|==|____H. ! _______.	\n");
			printf("I-H_I=I=HH_==_|I_IIIII_I_I_=HH|======.I-I-I-=======-I=I=I=I_=H|=H'===I=I/	\n");
			printf("\\                                                                      ,	\n");
			printf(" |                                                                    /		\n");
			printf(" .___________________________________________________________________'		\n\n\n\n");
			break;
		case 1:
			printf("                       $o 													\n");
			printf("                       $                     .........						\n");
			printf("                      $$$      .oo..     'oooo'oooo'ooooooooo....			\n");
			printf("                       $       $$$$$$$										\n");
			printf("                   .ooooooo.   $$!!!!!										\n");
			printf("                 .'.........'. $$!!!!!      o$$oo.   ...oo,oooo,oooo'ooo''	\n");
			printf("    $          .o'  oooooo   '.$$!!!!!      $$!!!!!       'oo''oooo''		\n");
			printf(" ..o$ooo...    $                '!!''!.     $$!!!!!							\n");
			printf(" $    ..  '''oo$$$$$$$$$$$$$.    '    'oo.  $$!!!!!							\n");
			printf(" !.......      '''..$$ $$ $$$   ..        '.$$!!''!							\n");
			printf(" !!$$$!!!!!!!!oooo......   '''  $$ $$ :o           'oo.						\n");
			printf(" !!$$$!!!$$!$$!!!!!!!!!!oo.....     ' ''  o$$o .      ''oo..				\n");
			printf(" !!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!ooooo..      'o  oo..    $				\n");
			printf("  '!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooooo..  ''   ,$				\n");
			printf("   '!!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooo..$$				\n");
			printf("    !!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!$'				\n");
			printf("    '$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$!!!!!!!!!!!!!!!!!!,				\n");
			printf(".....$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.....			\n\n\n\n");
    }


}


/*-----------------------------------------------------------------*/

// Juego

void hacerBarco (NAVE barcosDeUsuario[SIZE][SIZE], NAVE barcoBot[SIZE][SIZE],
				CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
				int row, int col){

	srand(time(NULL));
    int x, cordx, cordy, tamanio_tabla, limite, i, j=0;
    
    CELDA *celda;
    NAVE *nave;

    limite=0;
    i = 1;
    tamanio_tabla = (row*col)*0.3;
    do{
    	// Se asigna el tipo de barco
        x = (rand() % (5 - 1 + 1))+1;

        // Coordenadas aleatorias
        cordx = (rand() % ((row-1) - 0 + 1))+0;
        cordy = (rand() % ((row-1) - 0 + 1))+0;

        // Apuntador a la coordenada "x"
        celda=*(matrix+cordy);
    	nave =*(barcosDeUsuario+cordy);

        // Comprueba si la celda ya está en uso
        if (((celda+cordx) -> idBarco) != 0)
        {
        	printf("Recalculando... %d\nCoordenadas: %d, %d", ((celda+cordx) -> idBarco), cordx, cordy);
        	cordx = (rand() % ((row-1) - 0 + 1))+0;
        	cordy = (rand() % ((row-1) - 0 + 1))+0;
        }

        // Asigna el id y tipo de barco a la celda
    	(nave+cordx) -> tipoBarco = x;
        (celda+cordx) -> idBarco=i;
        (celda+cordx) -> estadoCelda=(char)(i+'0');
        // Asignación de tipo de barco, orientacion, y estado en estructura tipo NAVE

        switch((nave+cordx) -> tipoBarco){
        	case 'H':
        		for (int k = 0; k < x-1; ++k)
        		{
        			if ((nave+cordx)->tipoBarco==0)
        			{
        				(nave+cordx)->tipoBarco=x;
        			} else{
        				(nave+cordx)->tipoBarco=0;
        				break;
        			}
        		}
        		break;
        	default:

        		break;
        }

        // printf("%d\n", x);
        j++;
        i+=1;
        limite += x;
        printf("%d\nCoordenadas: %d, %d", ((celda+cordx) -> idBarco), cordx, cordy);
        // system("timeout /t 1");
    } while (limite<tamanio_tabla);

    limite=0;
    do{
        // Se asigna el tipo de barco
        x = (rand() % (5 - 1 + 1))+1;

        // Coordenadas aleatorias
        cordx = (rand() % ((row-1) - 0 + 1))+0;
        cordy = (rand() % ((row-1) - 0 + 1))+0;
        // cordx = rand() % row-1;
        // cordy = rand() % col-1;
        // Apuntador a la coordenada "x"
        celda=*(matrixBot+cordy);
        // Comprueba si la celda ya está en uso
        if (((celda+cordx) -> idBarco) != 0)
        {
        	printf("Recalculando... %d\nCoordenadas: %d, %d", ((celda+cordx) -> idBarco), cordx, cordy);
        	cordx = (rand() % ((row-1) - 0 + 1))+0;
        	cordy = (rand() % ((row-1) - 0 + 1))+0;
        }

        // Asigna el id y tipo de barco a la celda
        // (celda+cordx) -> tipoDeBarco=x;
        (celda+cordx) -> idBarco=i;
        (celda+cordx) -> estadoCelda=(char)(i+'0');

        // printf("%d\n", x);
        i+=1;
        limite += x;
        printf("%d\nCoordenadas: %d, %d", ((celda+cordx) -> idBarco), cordx, cordy);
        // system("timeout /t 1");
    } while (limite<tamanio_tabla);
}

void bombardeoAUsuario (CELDA matrix[SIZE][SIZE], int row, int column){

	srand(time(NULL));
    int x, y;
    x = rand() % 9;
    y = rand() % 9;
    printf("%d\n%d\n", x+1,y+1);

	CELDA *celda;

	celda=*(matrix+y);

	if (((celda+x) -> idBarco) != 0)
	{
		printf("Se registro un golpe por parte del bot.\n");
		(celda+x) -> idBarco=7;
	}

	// printf("%d\n", ((celda+x) -> impactoBarco));

	system("timeout /t 1");
}

void bombardeoABot (CELDA matrixBot[SIZE][SIZE], int x, int y){
	CELDA *celda;

	celda=*(matrixBot+x);
	if ((celda+y)-> idBarco != 0)
	{
		(celda+y) -> idBarco = 7;
		printf("Le dio a un barco!\n");
		(celda+y) -> estadoCelda = 'd';
	} else{
		(celda+y) -> estadoCelda = 'v';
	}

	printf("%d\n", ((celda+y) -> idBarco));

	system("timeout /t 3");
}

void iniciarJuego(CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
				NAVE barcosDeBot[SIZE][SIZE], NAVE barcosDeUsuario[SIZE][SIZE], 
					int row, int col, int dif, int coordx, int coordy, int turno){
	switch (dif){

		case 1:
			printf("Dificultad 1\n");
			hacerBarco(barcosDeUsuario, barcosDeBot, matrix, matrixBot, row, col);

			do{
				system("cls");
				printUser (matrix, barcosDeUsuario, row, col);
				printBot (matrixBot, row, col);

				printf("\n\n---Coordenadas a atacar---\nx: ");
				scanf("%d", &coordx);
				printf("y: ");
				scanf("%d", &coordy);

				bombardeoABot(matrixBot, coordx, coordy);

				printf("Turnos: %d\n", turno);
				turno++;

			} while (turno!=10);
			turno=0;
			do
			{
				bombardeoAUsuario(matrix, row, col);
			} while (turno!=10);

			system("timeout /t 10");

			printUser (matrix, barcosDeUsuario,row, col);
			printBot (matrixBot, row, col);

			
			// printBot (matrixBot, row, col);

			break;

		case 2:
			printf("Dificultad 2\n");
			printUser (matrix, barcosDeUsuario,row, col);			

			break;

		default:
			printf("La dificultad no coincide, pruebe de nuevo.\n");
			break;
	}

	system("timeout /t 3\n");
}



/*-----------------------------------------------------------------*/