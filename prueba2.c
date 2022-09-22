#include<stdio.h>  
#include<stdlib.h>  
     
int main()  
{  
     
    int i;  
     
    printf("10 Random Numbers =>\n");      
         
    for(i=0;i<10;i++)  
    {  
        printf("%d ",(rand() %100) + 1);  
    }  
     
    printf("\n");  
    return 0;
}