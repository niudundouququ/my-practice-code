//第一次做，错误的
#include<stdio.h>
#include<string.h>

#define maxn 110


char s[maxn];

int main()
{
    //获取输入
    scanf("%s",s);
    //printf("%d", strlen(s));
    int len = strlen(s);
    //int a = s[0]; //a用来寄读到的字符
    int b[len]; //c语言变量长度数组不允许用初始化列表{0} 初始化
    

    //我觉的可以从求1位的和，2位的和，3位的和。。。找到某几位的和唯一最小就好了
    //这里主要有个循环的问题，我觉得可以用取余解决
    for(int i = 1; i <= len; i++) //从1位算起
    {
        memset(b, 0, sizeof(b));//先初始化为0，等待记录求和

        for(int j = 0; j < len; j++)//从0开始
        {
            for(int k = 0;k < i; k++) 
            {
                b[j] += s[(j + k) % len];
            }
        }

        //比较
        //先找到最小的，记为min
        int min = 1000000;

        for(int j = 0; j < len; j++)
        {
            if(b[j] <= min) min = b[j];
        }

        int count = 0;//用于记录最小的个数，当个数等于1的时候才算找到最小的
        int temp = 0;//temp用来记录第几位开始
        for(int j = 0; j < len; j++)
        {
            if(b[j] == min)
            {
                count++;
                temp = j;
            }
        }

        if(count == 1)
        {
            printf("from NO.%d i:%d\n", temp + 1, i);
            break;
        }
    }


    //现在从所有A的位置开始检查对比

    return 0;
}