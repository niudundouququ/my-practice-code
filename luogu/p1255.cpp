#include<iostream>
#define maxn 5050
using namespace std;

long long ans[maxn] = {0};
//注意：这道题当n到5000左右的时候连long long也装不下了
//需要用高精度加法



int main()
{
    ans[1] = 1;
    ans[2] = 2;
    int n;
    cin >> n;
    
    for(int i = 3 ; i <= n;i++)
    {
        ans[i] = ans[i-1] + ans[i-2];
    }
    
    cout << ans[n] << endl;
    
} 