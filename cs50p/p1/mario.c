#include <stdio.h>

int main()
{
    int height;
    do
    {
        printf("Height: ");
        scanf("%i",&height);
    } while (height < 0);
    
    for (int i = 1; i <= height; i++)
    {
        int hash = height - i;
        for (int j = 0;j < hash; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf(" ");
        for (int j = 0; j < i; j++)
        {
            printf("#\a");//“\a” 是输出警报铃声（虽然不是那么警报）
        }
        printf("\n");
    }
}