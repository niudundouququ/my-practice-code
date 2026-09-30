#include<stdio.h>
#include<string.h>

#define maxn 100

char s[maxn];

int main()
{
    memset(s, 0, sizeof(s));
    scanf("%s", s);
    int count  = 0, score = 0;
    for(int i = 0; s[i] != '\0';i++)
    {
        if(s[i] == 'O')
        {
            count++;
            score += count;
        }
        else count = 0;
    }
    printf("%d", score);
    return 0;
}