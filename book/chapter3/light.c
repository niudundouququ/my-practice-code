#include<stdio.h>
#include<string.h>
#define maxn 1010

int a[maxn] = {0};

int main()
{
    /*这是我的算法
    int n, k;//n盏灯，k个人
    scanf("%d%d", &n, &k);

    //改变开关灯状态
    for(int i = 1; i <= k; i++)
    {
        int temp = i - 1;
        while(temp <= n)
        {
            a[temp]++;
            temp += i;
        }
    }

    //输出结果

    for(int i = 0; i < n; i++)
    {
        if((a[i]%2) == 1) printf("%d ",i + 1);
    }
    */

    int n, k, first = 1;
    memset(a, 0, sizeof(a));//把数组a全部设置为0
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= n; j++)
            if(j % i == 0) a[j] = !a[j];//！对于0返回1 ，！对于非零数返回 1

    for(int i = 1; i <= n; i++)
        if(a[i]) {if(first) first = 0; else printf(" "); printf("%d", i);}
    printf("\n");

    //test
    int count = 0;
    printf("%d %d %d\n", count++, count++, count++);//这段代码输出的竟然是2 1 0

    return 0;
}

