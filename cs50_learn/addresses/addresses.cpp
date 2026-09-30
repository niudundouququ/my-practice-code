#include <iostream>

int main()
{
    int n = 114;
    int *p = &n; //*p means the p stores the address of n,not a number 
    //printf("%p\n",&n); print the address of n in the memory
    printf("%p\n",p);

    std::string a = "Peter";
    std::string *pp = &a;
    printf("%p\n",pp);

    printf("%i\n",*p);
    //the *p here means go to the address in p
    //go to the address in p and print out what you find there
    std::cout<<*pp<<std::endl;
    //or maybe
    printf("%s\n",pp->c_str());
    //as for the problem that using pp instead of *pp ,wait for a few months when I manage cpp better

    printf("%p\n",a);
    //the string a is actually a pointer?yes
    printf("%s\n",a); //string is a Cpp style code which is hard for Printf to understand
    printf("%s\n",a.c_str());//the c_str() actually turns the string into a pointer so to let printf go to the address in a and print it out
    
    printf("%p\n",&a);//&a 是 string 对象本身的地址，而 &a[0] 是其内部存储字符数据的堆内存地址，两者位置不同。
    printf("%p\n",&a[0]);
    printf("%p\n",&a[1]);
    printf("%p\n",&a[2]);
}
