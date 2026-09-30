#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01
#define maxn 65

char s[maxn];
//我就不信了，读出来一个字母就先加上
//如果读出来数字就数字-1再加上
//9.26凌晨终于成功了T_T

int main()
{
    scanf("%s", s);
    float mol = 0, ele = 0;
    int num = 0, i = 0;
    int n = strlen(s);
    while(i < n)
    {
        num = 0;
        if(isalpha(s[i]))
        {
            if(s[i] == 'C') ele = C;
            if(s[i] == 'H') ele = H;
            if(s[i] == 'O') ele = O;
            if(s[i] == 'N') ele = N;
            i++;
        }
        else
        {
            while((isdigit(s[i])))
            {
                num = 10*num + s[i] - 48;
                i++;
            }
            printf("num: %d\n", num);
        }//这样数字是读出来了
        //然后就加上

        if(num == 0)
        {
            mol += ele;
        }
        else
        {
            mol += (num-1) * ele;
        }

    }
    printf("%.3f\n",mol);
    return 0;
}