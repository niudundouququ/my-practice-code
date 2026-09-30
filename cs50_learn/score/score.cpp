#include <iostream>
#include <vector>

int main(){
    int n = 0;
    int sum;
    std::cout<<"how many problems sets are there?"<<std::endl;
    std::cin>>n;
    std::vector<int> score(n);
    
    for (int i = 0; i<n;i++)
    {
        std::cout<<"what's your score of problem set"<<i+1<<std::endl;
        std::cin>>score[i];
        sum = sum + score[i];
    }    

    double average =static_cast<double> (sum)/n;
    std::cout<<"your average score is "<<average<<std::endl;
} 