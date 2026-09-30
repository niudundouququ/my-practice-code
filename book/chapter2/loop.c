#include<stdio.h>
#include<time.h>

int main()
{
    /*
    double n = 1.0;
    double sum = 0.0;
    for(int i = 0; ; i++)
    {
        double term = 1.0 / (2.0 * i + 1);
        if(i % 2 == 0) sum += term;
        else sum -= term;
        if(term < 1e-6) break;
    }
    printf("%.6f\n",(4.0 * sum));
    return 0;
    */
    const int MOD = 1000000;
    int n,S = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        int temp = 1;
        for(int j = 1; j <= i; j++)
        {
            temp = (temp * j) % MOD;
        }
        S = (S + temp) %MOD;

    }//聪明人可以发现25!末六位都是0，说明大于25的n都不会对结果产生任何影响
    //所以当n > 25的时候，直接输出940313即可
    
    printf("%d\n",S);
    printf("Time used = %.2f\n",(double)clock() / CLOCKS_PER_SEC);
    return 0;
}