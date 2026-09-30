#include <iostream>

int main(){
    int rows;
    int columns;
    std::cout<<"how many rows do you want?"<<std::endl;
    std::cin>> rows;
    std::cout<<"how many columns do you want?"<<std::endl;
    std::cin>> columns;
    for (int i = 0; i<rows; i++){
        for (int j =0; j<columns; j++){
            std::cout<<"#";
        }
        std::cout<<"\n";
    }
}