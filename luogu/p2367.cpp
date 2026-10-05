#include<iostream>

using namespace std;

int main()
{
    int n, p; //n 学生数，p增加分数的次数
    cin >> n >> p;
    int score[n+1] = {0};
    int diff_score[n+1] = {0};

    for(int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }
    
    //diff
    for(int i = 1; i <=n ;i++)
    {
        diff_score[i] = score[i] - score[i-1];
    }

    int x, y, z;
    int min = 1000000000;
    int a[n+1] = {0};
    for(int i = 0; i < p; i++)
    {
        cin >> x >> y >> z;
        diff_score[x] += z;
        if(y + 1 <= n) diff_score[y+1] -= z;
    }
    
    for(int i = 1; i <= n;i++)
    {
        a[i] = diff_score[i] + a[i-1];
        if(a[i] < min) min = a[i];
    }

    cout << min << endl;
    return 0;
}