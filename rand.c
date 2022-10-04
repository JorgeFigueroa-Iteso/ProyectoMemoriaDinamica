#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand(time(NULL));
	int x;

	x = (rand() % (5 - 1 + 1))+1;

	for (int i = 0; i < 10; ++i)
	{
		/* code */
		printf("%d\n", x);
		// system("timeout /t 0");
	}

	// system("pause");
	return 0;
}