#include <iostream>
#include <stdio.h>

void draw(int n);

int main()
{
    std::cout<< " what's the height of the pyramid you want?";
    int height;
    std::cin >> height;
    draw(height);
}



void draw(int n)
{
    if (n<=0)
    //using <= is a more safer condition
    {
        return;
        //when working with a function which returns nothing(viod) and you want to break the loop, just use "return;"
    }
    // without this condition line, the program will never end

    draw(n-1);
    
    //just print out one row
    for (int i =0; i<n;i++)
    {
        printf("#");
    }
    printf("\n");

}