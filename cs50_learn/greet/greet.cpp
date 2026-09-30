#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
    if (argc ==2 )
    {
        std::cout<<"hello, "<<argv[1]<<std::endl;
        //agrv[0] equals the file name which at here is "greet.cpp"
    }
    else
    {
        std::cout<<"hello,world"<<std::endl;
    }
    return 0;
}
