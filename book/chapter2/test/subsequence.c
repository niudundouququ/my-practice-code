#include<stdio.h>

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 && n != 0 && m != 0)
    {

        double sum = 0.0;
        for(double i = (double)n; i <= (double)m; i++)//这里如果使用int i就会溢出
        {
            sum += 1.0/(i*i);
        }
        printf("%.5f\n",sum);
    }
    return 0;
}