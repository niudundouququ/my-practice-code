#include<iostream>
using namespace std;

int main()
{
    int N, M;//要到M个城市,可重复
    cin >> N >> M;
    int P[M+1], price[N][3];//有N-1段铁路
    for(int i = 1; i <= M ; i++)
    {
        cin >> P[i];
    }


    //录入价格 0是纸质票价 1是ic卡价格 2是ic卡成本（只用买一次）
    for(int i = 1; i <= N-1;i++)
    {
        cin >> price[i][0] >> price[i][1] >> price[i][2];
    }
    
    //我应该从P[i] 中计算出来第i段铁路一共坐了多少次 
    //一共有N - 1 条铁路
    int times[N] = {0},diff[N] = {0};//这里看起来可以用差分，因为是对一段数字同时加一
    for(int i = 1; i <= M-1;i++)
    {
        if(P[i] < P[i+1])
        {
            diff[P[i]] += 1;
            if(P[i+1] < N) diff[P[i+1]] -= 1;
        }
        else//就是实现个比较大小
        {
            diff[P[i+1]] += 1;
            if(P[i] < N) diff[P[i]] -= 1;
        }
    }


    for(int i = 1; i <= N-1 ;i++)
    {
        times[i] = diff[i] + times[i-1];
        //计算出来的次数完全正确
    }
    
    //现在开始计费了,price是从1开始到N-1的， times也是从1开始到N-1的
    long long sum = 0;
    for(int i = 1; i <= N-1; i++)
    {
        long long cost, paper, ic;
        paper = 1LL*price[i][0]*times[i];
        ic = 1LL*price[i][1]*times[i] + price[i][2];
        cost = (paper < ic)? paper: ic;
        sum += cost;
    }

    cout << sum << endl;

    return 0;
}