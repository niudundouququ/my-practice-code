#include<iostream>
#include<vector>
using namespace std;

int check(const vector<long long>& L,long long mid, int N, int M)
{
    int i = 0,j = 1;
    int counter = 0;
    while(j <= N)
    {
        //一定先回落入第一种情况
        if((L[j] - L[i]) < mid)
        {
            if(j < N)//通常情况
            {
                j++;//没有超过mid
            }
            else//(j >= N)边界情况
            {
                counter++;
                break;//或者我想写j++直接靠边界判定结束循环
            }
        } 
        else if((L[j] - L[i]) == mid)//这次超过mid了
        {
            i = j;
            j++;//i变成j+1，j变成j+2
            counter++;
        }
        else //((L[j] - L[i-1]) > mid)
        {
            counter++;
            i = j - 1;
        }
        //每次保证i停在上一个数组结束的地方
    }

    if(counter > M) return 1;
    if(counter <= M) return 0;
    return -1;
}


int main()
{
    int N, M, max = 0;
    cin >> N >> M;
    vector<long long> prefix(N+1,0);
    for(int i = 1; i <= N; i++) //如果用int x的话只是copy了一份，并没有更改原数组
    {
        int temp; cin >> temp;
        prefix[i] = prefix[i-1] + temp;
        if(temp > max) max = temp;
    }

    //应该是从元素的最大值为左边界开始分割
    long long l = max, r = prefix[N];
    while(l < r)
    {
        long long mid = l + (r-l)/2;
        if(check(prefix, mid, N, M) == 1)//mid 太小了,且mid不是答案
        {
            l = mid + 1;
        }
        else if(check(prefix, mid, N, M) == 0)
        {
            r = mid;
        }
    }
    cout << l << ' ' << r;

    return 0;
}