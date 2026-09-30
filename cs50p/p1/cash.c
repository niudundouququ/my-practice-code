#include <stdio.h>

int main()
{
    int coins = 0;
    int cash;
    do
    {
     printf("Cash: ");
     scanf("%i",&cash);
    }while( cash < 0);
   

    while (cash > 0)
    {
        if(cash >= 25)
        {
            cash = cash -25;
            coins++;
        }
        else if(cash >= 10)
        {
            cash = cash - 10;
            coins++;
        }
        else if ( cash >= 5)
        {
            cash = cash -5;
            coins++;
        }
        else
        {
            cash = cash - 1;
            coins++;
        }
    }
    printf("coins: %i",coins);
}