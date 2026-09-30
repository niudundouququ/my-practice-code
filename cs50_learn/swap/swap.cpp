#include <iostream>

void swap(int *x, int *y);

int main()
{
    int x = 1;
    int y = 2;
    printf("x = %i , y = %i\n",x,y);
    swap(&x,&y);
    printf("x = %i , y = %i\n",x,y);
}

//the x and y here is different from the x and y in the main function
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}