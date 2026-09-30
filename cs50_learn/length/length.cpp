#include <iostream>

int main()
{
    std::cout<<"what's your name ?"<<std::endl;
    std::string name;
    std::cin>>name;
    int i = 0;
    while (name[i] != '\0')
    //此行中因为字符串数组的最后一位通常定义为0 也就是nul ，所以这里判断处可以直接写0 也可以写'\0' 在ascll码中就是00000000
    {
        i++;
    }
    std::cout<<i;

}