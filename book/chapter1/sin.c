#include<stdio.h>
#include<math.h>

int main()
{
    double n ;
    scanf("%lf",&n);//要想输入double就必须要用%lf，输出用%f
    printf("%f\n",sin(n*M_PI/180.0));//sin函数接收的是double类型的参量
    return 0;
}