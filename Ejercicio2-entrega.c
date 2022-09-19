#include <stdio.h>
#include <string.h>

void sortnames (char **s, char **t);
int main(){
    char *nombres[10] = {"Juan","Jose","Gaby","Maria","Karla","Luis","Antonio","Cecilia","Francisco","Roberto"};

    printf("Nombres a ordenar:\n\n");
    for(int i = 0; i < 10; i++){
        printf("%s\n",*(nombres+i));
    }

    printf("\nNombres ordenados:\n\n");
    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j < 10; j++){
            if(strcmp(*(nombres+i),*(nombres+j))>0){
                sortnames(nombres+i, nombres+j);
            }
        }
    }

    for(int i = 0; i < 10; i++){
        printf("%s\n",*(nombres+i));
    }
}
void sortnames (char **s, char **t){
    char *temp;
    temp = *s;
    *s = *t;
    *t = temp;
}