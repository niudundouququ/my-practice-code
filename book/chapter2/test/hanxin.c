#include<stdio.h>

int main()
{
    int a, b , c, n = 0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    for(int i = 10; i <= 100; i++)
    {
        if(i % 3 == a && i % 5 == b && i % 7 == c)
        {
            printf("%d\n",i);
            n++;
            break;
        }
    }
    if(!n) printf("no answer\n");
    return 0;
}