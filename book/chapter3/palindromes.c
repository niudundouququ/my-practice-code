#include<stdio.h>
#include<string.h>
#include<ctype.h>

char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char *ans[2][2] = {{"not a palindrome nor a mirrored string","a palindrome but not a mirrored string"},{"not a palindrome but a mirrored string","a palindrome and a mirrored string"}};

//转换成镜像的函数
char r(char ch)
{
    if(isalpha(ch)) return rev[ch - 'A'];
    return rev[25 + ch - '0']; 
    //'0'的值是48!!!
}

char s[100];
int main()
{
    //先获取初始字符串
    while(scanf("%s",s) == 1 && s[0] != 0)
    {
        int len = strlen(s);
        int p = 1, m = 1;
        //printf("the value of \'0\': %d",'0');
        for(int i = 0; i < (len + 1)/2; i++)//只用判断到中间
        {
            if(r(s[i]) == 0 || r(s[i]) != s[len - 1 - i])//短路特性，先得判断是不是0
            {
                //printf("not a mirrored string\n");
                m = 0;
                break;
            }
        }


        for(int i = 0; i < (len + 1)/2; i++)//只用判断到中间
        {
            if(s[i] != s[len - 1 - i])//短路特性，先得判断是不是0
            {
                //printf("not a palindrome\n");
                p = 0;
                break;
            }
        }
        //if(p == 1) printf("is a mirrored string\n");
        
        /*
        for(int i = 0; i < len/2; i++)
        {
            if(r(s[i]) != s[len - 1 - i])
            {
                printf("not a mirrored string\n");
                break;
            }
        }
        */
        //printf("%d %d\n", m, p);
        printf("%s -- is %s\n", s, ans[m][p]);
    }
    


    return 0;
}