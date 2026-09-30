#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar1 key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        //将字符串转换成整数，用到的是stdlib.h的atoi函数
        printf("%i\n",key);
        char plaintext[256];
        printf("plaintext: ");
        scanf("%c",plaintext);
    }
}