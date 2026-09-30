#include <iostream>
#include <string>

int main(){
    char input;
    std::cout << "do you agree? (y/n): ";
    std::cin >> input;
    if (input == 'y'|| input =='Y')
    //相当于or
    {
        std::cout << "you agreed!"<<std::endl;
    }
    else
    {
        std::cout <<"you disagreed!"<<std::endl;
    }
}