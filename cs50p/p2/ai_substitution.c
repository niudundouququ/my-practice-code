#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // 1. 检查命令行参数数量
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // 2. 检查密钥长度是否恰好为 26
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    char key[27]; // 多留一个位置给 '\0'，虽然这里不一定需要，但好习惯
    
    // 3. 验证密钥字符并检查重复
    bool seen[26] = {false}; // 用于记录字母是否已经出现过
    for (int i = 0; i < 26; i++)
    {
        char c = argv[1][i];
        
        // 检查是否为字母
        if (!isalpha((unsigned char)c))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        // 统一转为大写存入 key 数组
        char upper_c = toupper((unsigned char)c);
        key[i] = upper_c;

        // 检查是否重复
        int index = upper_c - 'A';
        if (seen[index])
        {
            printf("Key must not contain duplicate characters.\n");
            return 1;
        }
        seen[index] = true;
    }

    // 4. 获取明文输入
    char plaintext[1024];
    printf("plaintext: ");
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL)
    {
        return 1;
    }

    // 去除 fgets 读入的换行符
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n')
    {
        plaintext[len - 1] = '\0';
        len--; // 更新长度
    }

    // 5. 加密并输出
    printf("ciphertext: ");
    for (size_t i = 0; i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha((unsigned char)c))
        {
            int index = toupper((unsigned char)c) - 'A';
            char encrypted_char = key[index];

            // 保持原文的大小写格式
            if (islower((unsigned char)c))
            {
                encrypted_char = tolower((unsigned char)encrypted_char);
            }
            printf("%c", encrypted_char);
        }
        else
        {
            // 非字母字符原样输出
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}