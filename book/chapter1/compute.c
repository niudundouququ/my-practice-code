#include<stdio.h>
#include<math.h>

int main()
{
    /*printf("%.1f\n",8/5);
    %f代表的是浮点数，而8和5都是整数，8和5之间的运算结果因此也是整数，故而不能输出到浮点数那里
    */
    printf("%.0f\n",8.0/5.0);//这样才能输出1.6 将.1改为.2 后将输出1.60
    //如果改成.0的话会输出2


    printf("%.8f\n",1+2*sqrt(3)/(5 - 0.1));
    //5-0.1本身是整数先变成浮点数，然后浮点数-浮点数
    printf("%f\n",sqrt(9));

    int a,b;
    scanf("%d%d", &a, &b);
    printf("a + b = %d\n",a+b);
    

    //神奇的变量交换,但不建议使用，不如多设置一个变量作临时容器的方法
    a = a + b;
    b = a - b;
    a = a - b;
    printf("%d\n%d\n",a,b);

    return 0;
}