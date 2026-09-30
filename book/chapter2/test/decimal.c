#include<stdio.h>
#include<math.h>

int main()
{

    //ds提示我说模仿整式除法

    int a, b, c, kase = 0;
    int number[c + 2] ;//第0位存整数，再来一位存用于四舍五入的小数

    while(scanf("%d %d %d", &a, &b, &c) == 3 && a != 0 && b != 0 && c != 0)
    {

        //整数部分好弄，直接除就可以
        number[0] = a/b;

        //然后要输出小数部分，这一部分就要用到竖式除法了吧
        int temp = a % b; //定义temp为a除以b的余数
        
        for(int i = 1; i <= c + 1; i++)//最后再来一位用来四舍五入
        {
            temp *= 10;
            number[i] = temp/b;
            temp %= b; //变成余数
        }


        //用来判断四舍五入
        if(number[c+1] >= 5)
        {
            for(int i = 0; i <= c; i++)
            {
                if(number[c - i] == 9 && i != c)
                {
                    number[c - i] = 0;
                }
                else if( i == c)
                {
                    number[0]++;
                }
                else
                {
                    number[c - i] ++;
                    break;
                }
            }
        }

        //输出最后结果
        printf("Case%d:  %d." , ++kase, number[0]);
        for(int i = 1; i <= c; i++)
        {
            printf("%d", number[i]);
        }
        printf("\n");

    }

    
    return 0;
}