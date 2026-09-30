#include<stdio.h>
#include<string.h>
#define maxn 105

int less(const char *s, int p, int q)
{
    int n = strlen(s);
    for(int i = 0; i < n; i++)
        if(s[(p+i)%n] != s[(q+i)%n])
            return s[(p+i)%n] < s[(q+i)%n];
    return 0;//大于等于的返回值都是0
}

int main()
{
    char s[maxn];
    while(scanf("%s", s) == 1 && s[0] != '\0')
    {
        int ans = 0;
        int n = strlen(s);
        for(int i = 1; i < n; i++)
            if(less(s, i, ans)) ans = i;
        for(int i = 0; i < n; i++)
            putchar(s[(i+ans)%n]);
        putchar('\n');
        
    }
    return 0;
}