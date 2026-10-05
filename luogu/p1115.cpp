#include<iostream>
using namespace std;
//这道题好像不用前缀和,前缀和也没什么用
int main()
{
    int n, a;
    int max = -100000000;
    cin >> n;
    int b[n+1] = {0};
    for(int i = 1; i <= n ; i++)
    {
        cin >> a;
        b[i] = a;
        if(b[i-1] <= 0) 
            b[i] = a;
        else
            b[i] = b[i-1] + a;
        max = (b[i] > max)? b[i]:max;
    }
    cout << max << endl;
}