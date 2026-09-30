#include <stdio.h>
#include <iostream>
#include <string>

int main(){
    std::string name;
    std::cout<<"what's your name?";
    std::cin>>name;
    //printf("Hello, %s!\n", name.c_str());
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;  
}
