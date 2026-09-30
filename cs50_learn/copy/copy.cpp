#include <iostream>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    std::string s;
    std::cout << "s: \n";
    std::cin >> s;
    const char* a = s.c_str();

    char *t = reinterpret_cast<char*>(malloc(strlen(a) + 1));//我tm不知道这个函数是干啥的
    //prepare a memory for t to copy s

    //copy 
    for (int i = 0, n = strlen(a); i <= n; i++)
    {
        t[i] = s[i];
    }

    //then capitalize t[0] to find if the t direct to another memory which different from s
    t[0] =  toupper(t[0]);

    std::cout<< t;

    free(t);
}