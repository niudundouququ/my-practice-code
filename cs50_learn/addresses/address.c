#include <stdio.h>

int main()
{
    int n = 114;
    int *p = &n; //*p means the p stores the address of n,not a number 
    
    char *s = "Peter Lee";
    printf("Not using *p %i\n",n);
    printf("Using *p %i\n",*p);
    printf("print out the pointer p  %p\n",p);
    printf("print out the number p %i\n",p);

    printf("%s\n",s);
    printf("%s\n",s+1);
    printf("%s\n",s+2);
    
    printf("This is %s\n",s);//*s 是对指针 s 的解引用，表示“取 s 指向的内存地址里的值”——也就是字符串的第一个字符 'P'（类型为 char）
    //*s 的类型是 char（只是一个字符，比如 'P'），而非「字符指针」。此时把 char 类型的值强行传给 %s，会导致类型不匹配，引发未定义行为（程序可能崩溃、输出乱码，甚至看似“正常”但逻辑错误）。
    //printf("%s\n",*s); this code went wrong
    printf("%c\n",*s);
    printf("%c\n",*(s + 1));
    printf("%c\n",*(s + 2));

    //printf("%s\n",)
    printf("%p\n",s);
    printf("%p\n",&s[0]);
    printf("%p\n",&s[1]);
   
}
