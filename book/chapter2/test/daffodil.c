#include<stdio.h>
#include<math.h>

int main()
{
    for(int i = 100; i < 1000; i++)
    {
        int a, b, c = 0;
        a = i/100;
        b = (i/10) % 10;
        c = i % 10;
        if(i == pow(a,3) + pow(b,3) + pow(c,3))
            printf("%d\n",i);
    }
    return 0;
}