#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()

{
	srand(time(NULL));
    int x, y;
    x = rand() % 10;
    y = rand() % 10;
    printf("%d\n%d\n", x,y);
    return 0;
}