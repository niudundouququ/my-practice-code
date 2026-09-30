#include <iostream>
#include <string>

int main(){
    int x;
    std::cout <<"enter your first number:";
    std::cin>>x;
    int y;
    std::cout <<"enter your second number:";
    std::cin>>y;
    if (x>y){
        std::cout << "the first number is greater than the second number" << std::endl;
    }
    else if (x<y){
        std::cout << "the second number is greater than the first number" << std::endl;
    }
    else{
        std::cout << "the two numbers are equal" << std::endl;
    }
}