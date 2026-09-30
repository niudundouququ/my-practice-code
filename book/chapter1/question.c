#include<stdio.h>
#include<math.h>

int main()
{
    //int result = pow(2,32);数据溢出了，输出-2147483648
    //int result = pow(2,31);也溢出了，说明int是4byte平分的
    int result = pow(2,31) - 1;//输出2147483647，可能是因为从0开始的所以少1
    printf("%d\n",result);
    int result_1 = - pow(2,31);
    printf("%d\n",result_1);//输出-2147483648 = - 2^31
    printf("size of int:%dbytes\n",sizeof(int));


    printf("size of double:%dbytes\n",sizeof(double));
    printf("%.16f\n",0.1);//看起来最多只能.16 多于这个数的话会多出来其他乱乱的数字


    double x = 1.0;
    while (isfinite(x * 2.0)) x *= 2.0;//本质上double的最大值是2^1024然而当x = 2^1023时，x *2.0 已经让isfinite返回0了，x就停到了2的1023次方
    //再想乘2.0也只能变成inf

    //x = x * (2.0 - __DBL_EPSILON__); //这一步甚至用(x - 1) *2.0都会溢出

    //新的天才算法
    /*double step = x / 2.0;
    while (isfinite(x + step)) //这有可能导致死循环：step不断减半后会下溢为0.0，这种情况下x+step始终=x，此时不能明确isfinite(x + step)；是否能返回0
    {
        x += step;
        step /= 2.0; 
    }
    */
    //正确的天才算法
    double step = x;
    while (step > 0.0) //防止下溢进入死循环
    {
        step /= 2.0;//每次加上上次的1/2最后无限接近原来的一倍
        if (isfinite(x + step))
        {
            x += step;
        }
    }
    double min = 1.0;
    while (min / 2.0 > 0.0) min /= 2.0;
    printf("max:%.0f\nmin:%f\n",x,min);
    //此处应该使用科学计数法
    printf("max: %e\n",x);
    printf("min: %g\n",min);

    //逻辑的执行顺序是有先后级的：先 "!" 再 "&&" 最后 "||"
    if (0 > 1 && 2 > 1 || 2 > 1)
        printf("yes\n");
    else
        printf("no\n");

    if (0 > 1 && (2 > 1 || 2 > 1))
        printf("yes\n");
    else
        printf("no\n");
    return 0;

}