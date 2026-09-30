#include<stdio.h>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; //至于说中间为什么是两个\\ 看看他的颜色呢
int main()
{
    int i, c;
    while((c = getchar()) != EOF)
    {
        for (i = 1; s[i] && s[i] != c; i++); //当s[i] == c 的时候i刚好停下来
        if (s[i]) putchar(s[i-1]);
        else putchar(c);
    }
    return 0;
}
