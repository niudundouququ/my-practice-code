#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 需要引入以使用 atoi
#include <ctype.h>  // 需要引入以使用 isalpha, isupper 等

int main(int argc, char *argv[]) // 1. 修正 argv 类型
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]); // 2. 将字符串转换为整数
    //atoi的函数原型是 int atoi(const char *str)

    char plaintext[1024]; // 3. 分配合法的内存空间
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin); // 4. 安全地读取包含空格的整行
    //fgets本身要求第一个参量是char *str 的指针类型，但是plaintext作为数组名称，有如下特殊性
    //数组名在大多数表达式中，会隐式地转换为指向其第一个元素的指针


    // 去掉 fgets 读入的换行符
    size_t len = strlen(plaintext);//size_t本质上是c/cpp标准库定义的一种无符号整数类型，strlen、sizeof、malloc的返回类型都是size_t
    //其实这里用int也不会出错，但是ai告诉我int可能会出错
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        // 5. 只对字母进行加密，保留大小写并处理回绕
        if (isalpha(c))
        //isalpha函数检测该单个字符是否是字母，除了字母意外的都返回0，如果是字母，返回值不一定为1
        //因而在这里建议不写(isalpha(c) == 1) 而是直接写 (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            /*
            char base;
            if (isupper(c)) {
                base = 'A';
            } else {
                base = 'a';
            }
            */
           //这是等价表达
            c = base + (c - base + key) % 26;//取余26，保证末尾的字母不会超出字母表，达成一个循环的效果
        }
        printf("%c", c);
    }
    printf("\n");

    return 0;
}
