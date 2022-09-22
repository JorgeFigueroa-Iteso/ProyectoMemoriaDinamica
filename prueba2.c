#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

srand(time(NULL));
int x, y, tamanio_tabla;    

tamanio_tabla = (xt*yt)*0.3;
for (int i = 0; i < tamanio_tabla; ++i)
{
    x = (rand() % (5-1+1))+1;
}


*/

int main()

{
	srand(time(NULL));
    int x, y, tamanio_tabla, limite;
    limite=0;
    tamanio_tabla = (10*10)*0.3;
    
/*
    for (int i = 0; i < tamanio_tabla; ++i)
    {
        x = (rand() % (5 - 1 + 1))+1;
        printf("%d - %d\n", x, i);
    }
*/
    do{
        x = (rand() % (5 - 1 + 1))+1;
        printf("%d\n", x);

        limite += x;

    } while (limite<tamanio_tabla);

    // y = rand() % 10;
    // printf("%d\n%d\n", x);
    return 0;
}