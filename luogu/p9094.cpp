#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int Y[n+1] = {0};//diff[i] = a[i] - a[i-1]
    int B[n+1] = {0};
    int R[n+1] = {0};
    //开三个数组表示分别加入了哪些颜色
    for(int i = 1; i <= m; i++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        if(k == 1)
        {
            Y[l]++;
            Y[r+1]--;
        }
        if(k == 2)
        {
            B[l] ++;
            B[r+1] --;
        }
        if(k == 3)
        {
            R[l] ++;
            R[r+1] --;
        }
    }

    //现在开始恢复数组
    int count = 0;
    for(int i = 1; i <= n;i++)
    {
        Y[i] += Y[i-1];
        B[i] += B[i-1];
        R[i] += R[i-1];
        if((Y[i] && B[i]) && !R[i]) count++;
    }
    cout << count;
    
    return 0;
}