#include<stdio.h>
#include<string.h>
#define maxn 100005//从这个例子就可以看出来定义这个的方便

int dg[maxn]; //大一点有余量

int main()
{
    memset(dg, 0, sizeof(dg));
    for(int i = 1; i <= maxn; i++)
    {
        int temp = i; //temp是用来计算的，最后是i添加到数组里面
        while( temp > 0)
        {
            dg[i - 1] += (temp % 10);
            temp = (temp / 10);
        }
        dg[i - 1] += i;
    }

    //现在该搜索了
    printf("number :");
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        int temp = 0;//用于判定是否找到
        for(int i = 0; i < maxn; i++)
        {
            if(dg[i] == n)  
            {
                printf("%d\n", i + 1);
                temp = 1;
                break;
            }
        }
        if(temp == 0) printf("0\n");
        
        printf("number :");
    }

    return 0;
}