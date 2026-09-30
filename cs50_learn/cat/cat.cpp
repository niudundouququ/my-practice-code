#include <iostream>
#include <string>

/*int main(void)
{
    for(int i =0; i<3; i++)
    {
        //printf("meow\n");
        std::cout<<"meow\n";
    }
    int i = 0;
    while (i<3=)
    {
        std::cout<<"meow\n"; 
        i++;
    }
    int n;
    while (true)
    {
        std::cout<<"how many times do you want?"<<std::endl;
                std::cin>>n;
        if (n<1)
        {
            continue;
        }
        else{
            break;
        }

    }
    do{
        std::cout<<"how many times do you want?";
        std::cin>> n;
    }
    while (n<0);
    for (int i = 0; i< n ; i++){
        std::cout<<"meow\n";
    }
        
}*/

//生成meow 函数
void meow(int times);
int get_int(void);

int main(){
    int n = get_int();
    /*std::cout<<"how many times do you want?"<<std::endl;
    std::cin>>n;*/
    meow(n);
}



int get_int(void){
    int n;
    do{
        std::cout<<"how many times do you want?";
        std::cin>>n;
    }
    while(n < 0 );
    return n;
}


void meow(int times){
    for (int i =0;i<times;i++){
        std::cout<<"meow\n";
    }
}