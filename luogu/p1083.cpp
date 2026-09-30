#include<iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    //cout << n << m << endl ;
    int r[n];//每一天可用于出租的教室数量

    for(int i = 0; i < n; i++)
    {
        cin >> r[i];//输入了每一天能出租的房间数
    }

    /*
    for(int i = 0; i < n; i++)
    {
        cout << r[i] << endl;
    }
    */
    
    for(int j = 1; j < m; j++)
    {
        int d, s ,t, kase = 1;
        cin >> d >> s>> t;//s 是开始时间,t是截至时间 d是租借的数量
        for(int k = s; k <= t ; k++)
        {
            r[k] -= d;
            kase++;
            if(r[k] < 0) 
            {
                cout << -1 << endl;
                cout << kase <<endl;
                break;
            }
        }
    }

    return 0;
}