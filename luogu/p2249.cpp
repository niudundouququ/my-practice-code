#include<iostream>

using namespace std;

int main()
{
    int n, m;//n个数字，查询m次
    cin >> n >> m;
    int num[n] ,src[m];
    //存储数字
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> src[i];
    }

    
    //开始查询
    for(int i = 0; i < m; i++)
    {
        
        int ans = -1;
        int left = 0, right = n - 1;

        while(left <= right)
        {
            int mid = (left + right)/2 ;
            if(num[mid] == src[i])
            {
                right = mid -1;
                ans = mid;
            }
            if(num[mid] < src[i])
            {
                left = mid + 1;
            }
            else
            {
                right = mid -1;
            }
        }
        
        if (ans != -1) 
        {
            cout << ans + 1 << " ";
        } else
        {
            cout << -1 << " ";
        }
    }


    return 0;
}