#include <iostream>
#include <string.h>
#include <string>

typedef struct
{
    const char * name;
    const char * number;
}person;

int main(void)
{
    person people[3];
    people[0].name = "Kelly";
    people[0].number ="+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";
    
    people[2].name = "Peter";
    people[2].number ="+86-178-0682-0979";

    std::cout<<"Name: ";
    std::string name;
    std::cin >> name;
    for (int i = 0;i<3;i++)
    {
        if (strcmp(people[i].name, name.c_str()) ==0 )
        // When working with std::string in C++, you can convert it to a C-style const char* by calling the c_str() method, 
        // especially if you want use functions that belongs to C
        {
            std::cout << people[i].number;
            return 0;
        }
    }
    std::cout<<"not found ";
}

/*
int main()
{
    int numbers[] = {20, 300,500,10,5,100,1,50,114,51,4,1919,810};
    int n;
    std::cout<<"what number do you want to find";
    std::cin>>n;
    int length = std::size(numbers);
    for (int i =0;i<length ;i++)
    {
        if (numbers[i] == n)
        {
            std::cout<<"found ";
            return 0;
            //直接跳出main函数，不会执行最后一行的not found
        }
    }
    std::cout<<"not found";
}
*/

//creat a data structure which relate a name with its phone number by using cpp key word


