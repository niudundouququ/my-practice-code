#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("phonebook.csv","a");
    //"a" means "append"
    char *name = malloc(100);
    //caution: when using malloc, you need include the library "stdlib.h"
    printf(" type in name: \n");
    scanf("%s",name);

    char *number = malloc(100);
    printf("type in number: \n");
    scanf("%s",number);

    fprintf(file,"%s,%s\n",name, number);
    fclose(file);

}