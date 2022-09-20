#include <stdio.h>
#include <stdlib.h>

typedef struct Color{
	int r,b,g;
}Color;

int printImage(Color img[32][32],int, int);

int main(void){



	// system("pause");
	return 0;
}

int printImage(Color img[32][32],int x, int y){

	for (int i = 0; i < 32; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
			*(*(img+i)+j) = 0;
		}
	}
}