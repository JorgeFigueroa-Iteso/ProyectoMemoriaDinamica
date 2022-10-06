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

int turno=0, limiteUser=0, limiteBot=0, auxUsr=0, auxBot=0;

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

void printUser (CELDA matrix[SIZE][SIZE], NAVE barcosDeUsuario[SIZE][SIZE], int row, int column);
void printBot  (CELDA matrixBot[SIZE][SIZE], NAVE barcosDeBot[SIZE][SIZE], int row, int column);

void bombardeoAUsuario (NAVE barcosDeUsuario[SIZE][SIZE], CELDA matrix[SIZE][SIZE], int row, int column, int turno);
void bombardeoABot (NAVE barcoBot[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE], int row, int column, int turno);

// void celda(char matrix[SIZE][SIZE], char matrixBot[SIZE][SIZE]);


int main (){
	turno=0, limiteUser=0, limiteBot=0, auxUsr=0, auxBot=0;
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    CELDA userMatrix[SIZE][SIZE];
    CELDA botMatrix[SIZE][SIZE];

    NAVE barcosDeBot[SIZE][SIZE];
    NAVE barcosDeUsuario[SIZE][SIZE];

    char op;

    int row=8, col=8, x, y;
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
            (celda+j) -> estadoCelda=' ';
            (celda+j) -> idBarco=0;
            (celda+j) -> impactoBarco=0;

            (nave+j) -> tipoBarco=0;
            (nave+j) -> orientacionBarco='D';
            (nave+j) -> sunk=0;
        }
    }

    for (i = 0; i < row; i++){
        celda=*(matrixBot+i);
        nave=*(barcosDeBot+i);
        for (j = 0; j < column; j++){
            (celda+j) -> estadoCelda=' ';
            (celda+j) -> idBarco=0;
            (celda+j) -> impactoBarco=0;

            (nave+j) -> tipoBarco=0;
            (nave+j) -> orientacionBarco='D';
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
        printf("%-3d ", i);
    }   printf("\n    ");
    for (int i = 0; i < column; ++i)
    {
        printf("----");
    } printf("\n");

    for(int i=0; i<row; i++){
        celda=*(matrix+i);
        nave=*(barcosDeUsuario+i);
        printf("%2d |", i);
        for(int j=0; j<column; j++){

            
            if ((celda+j) -> impactoBarco != 0) {
                printf(" x  ");
            } else if (((celda+j) -> idBarco) != 0) {
                // printf(" %-2d ", ((celda+j) -> idBarco));
                printf(" %-2d ", (nave+j)->tipoBarco);
            } else{
                printf(" %2c ", ((celda+j) -> estadoCelda));
            }
            
        }
        printf("|\n");
    }   printf("    ");
    for (int i = 0; i < column; ++i)
    {
        printf("----");
    } printf("\n");
}

void printBot (CELDA matrixBot[SIZE][SIZE], NAVE barcosDeBot[SIZE][SIZE], int row, int column){
    printf("   <--Matriz Maquina-->\n");

    CELDA *celda;
    NAVE *nave;

    printf("     ");
    for (int i = 0; i < column; ++i)
    {
        printf("%-3d ", i);
    }   printf("\n    ");
    for (int i = 0; i < column; ++i)
    {
        printf("----");
    } printf("\n");

    for(int i=0; i<row; i++){
        celda=*(matrixBot+i);
        nave=*(barcosDeBot+i);
        printf("%2d |", i);
        for(int j=0; j<column; j++){

            
            if ((celda+j) -> impactoBarco != 0) {
                printf(" x  ");
            } else if (((celda+j) -> idBarco) != 0) {
                // printf(" %-2d ", ((celda+j) -> idBarco));
                printf(" %-2d ", (nave+j)->tipoBarco);
            } else{
                printf(" %-2c ", ((celda+j) -> estadoCelda));
            }
            
        }
        printf("|\n");
    }   printf("    ");
    for (int i = 0; i < column; ++i)
    {
        printf("----");
    } printf("\n");
}

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
            printf("                                             .                              \n");
            printf("                           .                 |                              \n");
            printf("                           +                 |                              \n");
            printf("                  .        |                *+W+-*                          \n");
            printf("     .           +y        +W+              . H                 .           \n");
            printf("  .  +y            |I.   y  |               ! H= .           .  ^           \n");
            printf("  !   \\     .     |H '. /   |  ___.        .! H  !   +--.--y !  V          \n");
            printf("  !    \\     \\  +=|H|=='.=+ | |====\\   _  '_H_H__H_. H_/=  J !  !        \n");
            printf(". !     \'    VVV_HHH_/__'._H |  E  \\_|=|_|========|_|==|____H. ! _______. \n");
            printf("I-H_I=I=HH_==_|I_IIIII_I_I_=HH|======.I-I-I-=======-I=I=I=I_=H|=H'===I=I/   \n");
            printf("\\                                                                      ,   \n");
            printf(" |                                                                    /     \n");
            printf(" .___________________________________________________________________'      \n\n\n\n");
            break;
        case 1:
            printf("                       $o                                                   \n");
            printf("                       $                     .........                      \n");
            printf("                      $$$      .oo..     'oooo'oooo'ooooooooo....           \n");
            printf("                       $       $$$$$$$                                      \n");
            printf("                   .ooooooo.   $$!!!!!                                      \n");
            printf("                 .'.........'. $$!!!!!      o$$oo.   ...oo,oooo,oooo'ooo''  \n");
            printf("    $          .o'  oooooo   '.$$!!!!!      $$!!!!!       'oo''oooo''       \n");
            printf(" ..o$ooo...    $                '!!''!.     $$!!!!!                         \n");
            printf(" $    ..  '''oo$$$$$$$$$$$$$.    '    'oo.  $$!!!!!                         \n");
            printf(" !.......      '''..$$ $$ $$$   ..        '.$$!!''!                         \n");
            printf(" !!$$$!!!!!!!!oooo......   '''  $$ $$ :o           'oo.                     \n");
            printf(" !!$$$!!!$$!$$!!!!!!!!!!oo.....     ' ''  o$$o .      ''oo..                \n");
            printf(" !!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!ooooo..      'o  oo..    $                \n");
            printf("  '!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooooo..  ''   ,$                \n");
            printf("   '!!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooo..$$                \n");
            printf("    !!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!$'                \n");
            printf("    '$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$!!!!!!!!!!!!!!!!!!,                \n");
            printf(".....$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.....           \n\n\n\n");
    }


}


/*-----------------------------------------------------------------*/

// Juego

void hacerBarco (NAVE barcosDeUsuario[SIZE][SIZE], NAVE barcoBot[SIZE][SIZE],
                CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
                int row, int col){

    srand(time(NULL));
    int x, cordx, cordy, tamanio_tabla, i, j=0, ld, k=0;
    NAVE *nave;
    CELDA *celda, *auxB;

    int limite=0;
    i = 1;
    tamanio_tabla = (row*col)*0.3;
    do{
        ld=0, k=0;
        
        // Se asigna el tipo de barco
        x = (rand() % (5 - 1 + 1))+1;

        while(x>(row-x) && x>(col-x)){
            if (x<row && x<col)
            {
                break;
            }
            x = (rand() % (5 - 1 + 1))+1;
        }

        // Coordenadas aleatorias
        cordx = (rand() % ((col-1) - 0 + 1))+0;
        cordy = (rand() % ((row-1) - 0 + 1))+0;

        // Apuntador a la coordenada "x"
        nave =*(barcosDeUsuario+cordy);
        celda=*(matrix+cordy);
        auxB=*(matrix+cordy);

        while((cordy%row)<1 || (cordx%col)<1){
            if ((cordy%row)<1) {
                cordy = (rand() % ((row-1) - 0 + 1))+0;
            } else if ((cordx%col)<1) {
                cordx = (rand() % ((col-1) - 0 + 1))+0;
            }

            celda=*(matrix+cordy);
            nave =*(barcosDeUsuario+cordy);
        }


        // Comprueba si la celda ya está en uso

        do{
            cordx = (rand() % ((col-1) - 0 + 1))+0;
            cordy = (rand() % ((row-1) - 0 + 1))+0;
            celda=*(matrix+cordy);
            nave =*(barcosDeUsuario+cordy);
            // Comprueba los bordes de la tabla
            do{
                if ((row-cordy) < x){
                    cordy = (rand() % ((row-1) - 0 + 1))+0;
                } else if ((col-cordx) < x){
                    cordx = (rand() % ((col-1) - 0 + 1))+0;
                }
            } while ((row-cordy) < x || (col-cordx) < x);


        }while((celda+cordx) -> idBarco != 0);

        // Asigna el id y tipo de barco a la celda
        (nave+cordx) -> tipoBarco = x;
        (celda+cordx) -> idBarco=i;

        // Comprueba la orientación de la nave
        while(k<x){
            k++;
            for (int k = 1; k < x; ++k){

                auxB=*(matrix+(cordy+k));

                if ((celda+(cordx+k)) -> idBarco == 0){
                    (nave+cordx) -> orientacionBarco = 'D';
                    break;
                } 
                else if ((auxB+cordx) -> idBarco == 0)
                {
                    (nave+cordx) -> orientacionBarco = 'B';
                    break;
                }
                else if ((auxB+cordx) -> idBarco != 0)
                {
                    (nave+cordx) -> orientacionBarco = 'x';
                    break;
                }
            } 
        }

        switch((nave+cordx) -> orientacionBarco){
            case 'B':
                printf("Horientacion para colocar al barco es: B\n");
                for (int k = 0; k < x; ++k)
                {
                    celda=*(matrix+(cordy+k));
                    nave=*(barcosDeUsuario+(cordy+k));
                    (celda+cordx) -> idBarco = i;
                    (nave+cordx) -> tipoBarco = x;
                }
                break;
            case 'D':
                printf("Horientacion para colocar al barco es: D\n");
                for (int k = 0; k < x; ++k)
                {
                    (celda+(cordx+k)) -> idBarco = i;
                    (nave+(cordx+k)) -> tipoBarco = x;
                }                
                break;
            case 'x':
                (nave+cordx) -> tipoBarco = 0;
                (celda+cordx) -> idBarco = 0;
                break;
        }

        j++;
        i+=1;
        limite += x;
    } while (limite<tamanio_tabla);
    limiteUser=limite;

    limite=0, x;
    do{
        ld=0, k=0;
        
        // Se asigna el tipo de barco
        x = (rand() % (5 - 1 + 1))+1;

        while(x>(row-x) && x>(col-x)){
            if (x<row && x<col)
            {
                break;
            }
            x = (rand() % (5 - 1 + 1))+1;
        }

        // Coordenadas aleatorias
        cordx = (rand() % ((col-1) - 0 + 1))+0;
        cordy = (rand() % ((row-1) - 0 + 1))+0;

        // Apuntador a la coordenada "x"
        nave =*(barcoBot+cordy);
        celda=*(matrixBot+cordy);
        auxB=*(matrixBot+cordy);

        while((cordy%row)<1 || (cordx%col)<1){
            if ((cordy%row)<1) {
                cordy = (rand() % ((row-1) - 0 + 1))+0;
            } else if ((cordx%col)<1) {
                cordx = (rand() % ((col-1) - 0 + 1))+0;
            }

            celda=*(matrixBot+cordy);
            nave =*(barcoBot+cordy);
        }


        // Comprueba si la celda ya está en uso

        do{
            cordx = (rand() % ((col-1) - 0 + 1))+0;
            cordy = (rand() % ((row-1) - 0 + 1))+0;
            celda=*(matrixBot+cordy);
            nave =*(barcoBot+cordy);
            // Comprueba los bordes de la tabla
            do{
                if ((row-cordy) < x){
                    cordy = (rand() % ((row-1) - 0 + 1))+0;
                } else if ((col-cordx) < x){
                    cordx = (rand() % ((col-1) - 0 + 1))+0;
                }
            } while ((row-cordy) < x || (col-cordx) < x);


        }while((celda+cordx) -> idBarco != 0);

        // Asigna el id y tipo de barco a la celda
        (nave+cordx) -> tipoBarco = x;
        (celda+cordx) -> idBarco=i;

        // Comprueba la orientación de la nave
        while(k<x){
            k++;
            for (int k = 1; k < x; ++k){

                auxB=*(matrixBot+(cordy+k));

                if ((celda+(cordx+k)) -> idBarco == 0){
                    (nave+cordx) -> orientacionBarco = 'D';
                    break;
                } 
                else if ((auxB+cordx) -> idBarco == 0)
                {
                    (nave+cordx) -> orientacionBarco = 'B';
                    break;
                }
                else if ((auxB+cordx) -> idBarco != 0)
                {
                    (nave+cordx) -> orientacionBarco = 'x';
                    break;
                }
            } 
        }

        switch((nave+cordx) -> orientacionBarco){
            case 'B':
                // printf("Horientacion para colocar al barco es: B\n");
                for (int k = 0; k < x; ++k)
                {
                    celda=*(matrixBot+(cordy+k));
                    nave=*(barcoBot+(cordy+k));
                    (celda+cordx) -> idBarco = i;
                    (nave+cordx) -> tipoBarco = x;
                }
                break;
            case 'D':
                // printf("Horientacion para colocar al barco es: D\n");
                for (int k = 0; k < x; ++k)
                {
                    (celda+(cordx+k)) -> idBarco = i;
                    (nave+(cordx+k)) -> tipoBarco = x;
                }                
                break;
            case 'x':
                (nave+cordx) -> tipoBarco = 0;
                (celda+cordx) -> idBarco = 0;
                break;
        }

        j++;
        i+=1;
        limite += x;
    } while (limite<tamanio_tabla);
    limiteBot=limite;
}

void bombardeoAUsuario (NAVE barcosDeUsuario[SIZE][SIZE], CELDA matrix[SIZE][SIZE], 
                        int row, int column, int turno){

    srand(time(NULL));
    int x, y;
    x = rand() % row;
    y = rand() % column;

    CELDA *celda;
    NAVE *nave;

    celda=*(matrix+x);
    nave =*(barcosDeUsuario+x);

    if ((celda+y) -> estadoCelda != ' ')
    {
        do
        {
            x = rand() % row;
            y = rand() % column;
            celda=*(matrix+x);
            nave =*(barcosDeUsuario+x);
        } while ((celda+y) -> estadoCelda != ' ');
    }

    printf("x: %d\ny: %d\n", x,y);

    if ((celda+y)-> idBarco != 0)
    {
        (celda+y) -> impactoBarco = 1;

        printf("El bot registro un golpe!\n");
        auxUsr++;
        (celda+y) -> estadoCelda = 'X';
        // printf("%d\n", ((nave+y) -> tipoBarco));
    } else{
        (celda+y) -> estadoCelda = '+';
    }


    system("timeout /t 3");
}

void bombardeoABot (NAVE barcoBot[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
                    int x, int y, int turno){
    CELDA *celda;
    NAVE *nave;

    celda=*(matrixBot+x);
    nave =*(barcoBot+x);

    if ((celda+y)->estadoCelda!=' ')
    {
        do {
            printf("Ya se disparo en esas coordenadas.\nx: ");
            scanf("%d", &x);
            printf("y: ");
            scanf("%d", &y);
            celda=*(matrixBot+x);
            nave =*(barcoBot+x);
        } while ((celda+y)->estadoCelda!=' ');
    }

    if ((celda+y)-> idBarco != 0) {
        (celda+y) -> impactoBarco = 1;
        printf("Le dio a un barco!\n");
        auxBot++;
        (celda+y) -> estadoCelda = 'X';

        // printf("%d\n", ((nave+y) -> tipoBarco));
    } else{
        (celda+y) -> estadoCelda = '+';
    }


    system("timeout /t 3");
}

void iniciarJuego(CELDA matrix[SIZE][SIZE], CELDA matrixBot[SIZE][SIZE],
                NAVE barcosDeBot[SIZE][SIZE], NAVE barcosDeUsuario[SIZE][SIZE], 
                    int row, int col, int dif, int coordx, int coordy, int turno){
    int cambio, limite = 0;
    // limiteUser=0, limiteBot=0, turno=0;
    switch (dif){
        case 1:
            printf("Dificultad 1\n");
            hacerBarco(barcosDeUsuario, barcosDeBot, matrix, matrixBot, row, col);
            do{
                system("cls");
                printUser (matrix, barcosDeUsuario, row, col);
                printBot (matrixBot, barcosDeBot,row, col);

                cambio = (rand() % (1 - 0 + 1))+0;

                if (cambio==1)
                {
                    printf("\n---Turno del Usuario---\nCoordenadas a atacar\nx: ");
                    scanf("%d", &coordx);
                    printf("y: ");
                    scanf("%d", &coordy);

                    bombardeoABot(barcosDeBot, matrixBot, coordx, coordy, turno);
                } else{
                    printf("\n\n---Es el turno de la computadora---\n");
                    bombardeoAUsuario(barcosDeUsuario, matrix, row, col, turno);
                }
                // turno++;
                if (auxBot == limiteBot)
                {
                    break;
                } if (auxUsr == limiteUser)
                {
                    break;
                }

            } while (turno!=1);
            system("cls");
            printf("Se termino el juego!\n");
            printUser (matrix, barcosDeUsuario,row, col);
            printBot (matrixBot, barcosDeBot, row, col);
            system("timeout /t 10");

            break;

        case 2:
            printf("Dificultad 2\n");
            hacerBarco(barcosDeUsuario, barcosDeBot, matrix, matrixBot, row, col);
            do{
                system("cls");
                printUser (matrix, barcosDeUsuario, row, col);

                cambio = (rand() % (1 - 0 + 1))+0;

                if (cambio==1)
                {
                    printf("\n---Turno del Usuario---\nCoordenadas a atacar\nx: ");
                    scanf("%d", &coordx);
                    printf("y: ");
                    scanf("%d", &coordy);

                    bombardeoABot(barcosDeBot, matrixBot, coordx, coordy, turno);
                } else{
                    printf("\n\n---Es el turno de la computadora---\n");
                    bombardeoAUsuario(barcosDeUsuario, matrix, row, col, turno);
                }
                // turno++;
                if (auxBot == limiteBot)
                {
                    break;
                } if (auxUsr == limiteUser)
                {
                    break;
                }

            } while (turno!=1);
            system("cls");
            printf("Se termino el juego!\n");
            printUser (matrix, barcosDeUsuario,row, col);
            printBot (matrixBot, barcosDeBot, row, col);
            system("timeout /t 10");

            break;

        default:
            printf("La dificultad no coincide, pruebe de nuevo.\n");
            break;
    }

    // system("timeout /t 3\n");
}



/*-----------------------------------------------------------------*/