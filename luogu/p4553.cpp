#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    a[n+1] = {0};
    diff[n+1] = {0};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        diff[i] = a[i] - a[i-1];
    }

    //要让所有数字相等，就是让对于任意i>=2 有diff[i] == 0

}