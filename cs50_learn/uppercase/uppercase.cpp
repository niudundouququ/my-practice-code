#include <iostream>
#include <string>

int main()
{
    std::string text;
    std::cout<<"before:  "<<std::endl;
    std::cin>>text;

    for (std::size_t i = 0, n = text.length(); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = text[i] - 32; // convert to uppercase
        }
    }
    std::cout<<text<<std::endl;
}