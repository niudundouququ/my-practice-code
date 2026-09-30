#include<stdio.h>

int main()
{
    int n;
    int ans[20];
    while(scanf("%d", &n) == 1 )
    {
        //答案数组
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &ans[i]);
        }
        

        //获取输入
        while(1)
        {
            int a = 0, b = 0; //a是位置正确 b是数字对但位置不对
            //输入用于验证的数组
            //输入的时候就能检查是否在正确的位置上
            int inp[n];
            for(int i = 0; i < n; i++)
            {
                scanf("%d", &inp[i]);
            }

            if(inp[0] == 0) break;
            //检查
            for(int i = 0; i < n; i++)
            {
                //干脆每一轮结束后加
                int temp = 0;
                for(int j = 0; j < n; j++)
                {
                    
                    if(j == i) //如果数字正确，位置正确
                    {
                        if(ans[j] == inp[i]) a++;
                    }
                    else//当位置不对的时候
                    {
                        if(ans[j] == inp[i]) temp = 1;
                    }
                }
                b += temp;
                
            }
            //b = b - a;
            printf("(%d,%d)\n", a, b);
        }
    }
    return 0;
}