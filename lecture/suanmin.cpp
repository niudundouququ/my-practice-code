#include<iostream>
using namespace std;

int main()
{
    for(int m = 0; m < 7;m++)
    {
        cout << "CARD" << m << endl;
        for(int i = 1; i <=100; i++)
            if(i & (1 << m)) cout << i << ' '; 
            // & 是按位与 就是把两个数字转换成二进制比较两个数字相同位的0和1，只有同时都是1的时候返回1，否则都是0
            //(1 << m)的意思就是把0001中的1向左移m位
            //这样就能挑出来所有m位是1的数字
        cout << endl << endl;
    }
    return 0;
}