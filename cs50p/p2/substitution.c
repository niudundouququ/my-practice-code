#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        char key[27]; // 多留一个位置给 '\0'，虽然这里不一定需要，但好习惯
        //还要判断key是否符合标准
        for (int i = 0 ;i < 26;i++)
        {
            if ( ('A' <= argv[1][i] && argv[1][i] <= 'Z') ||  ('a' <= argv[1][i] && argv[1][i] <= 'z'))
            {
                if (!isupper(argv[1][i]))//如果是小写的话
                {
                    key[i] = argv[1][i] - 32;
                    printf("%c",key[i]);
                }
                else
                {
                    key[i] = argv[1][i];
                    printf("%c",key[i]);
                }
                
            }
            else
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
        printf("\n");

        //先获取用户输入
        char plaintext[1024];
        printf("plaintext: ");
        fgets(plaintext,sizeof(plaintext),stdin);

        //除去明文的换行，避免输出密文后出现多余的换行
        size_t len = strlen(plaintext);
        if (len>0 && plaintext[len-1] == '\n')
        {
            plaintext[len-1] = '\0';
        }

        //下一步是加密
        for (int i = 0; i < len ; i++)
        {
            char c = plaintext[i];
            if (isalpha(c))
            {
                if(isupper(c))//如果是大写的话，那么输出也要大写
                {
                    int temp = c - 'A';
                    printf("%c",key[temp]);
                }
                else
                {
                    int temp = c - 'a';
                    printf("%c",(key[temp]+32));
                }
            }
            else
            {
                printf("%c",c);
            }
        }
        printf("\n");
    }
}