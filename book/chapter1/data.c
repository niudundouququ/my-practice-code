#include<stdio.h>
#include<math.h>

int main()
{
    //printf("%d\n",111111*111111);这里数据溢出了，可使用更大范围的long long
    printf("%f\n",111111.0*111111.0);
    printf("%f\n",111111111.0*111111111.0);//换成float竟然没有溢出，他的容量相当大
    printf("%f\n",sqrt(-10));//windows的terminal返回了nan--not a number 这里返回还不一样，在wsl里面编译的时候直接报错
    printf("%f\n",1.0/0.0);//返回了inf--infinity 正无穷大
    printf("%f\n",0.0/0.0);//返回了nan
    //printf("%d\n",1/0); 前面的浮点类型除以0在编译的时候不会被warn，但整数类型的在编译的时候会被warn
    printf("%%d\n");
    return 0;
}