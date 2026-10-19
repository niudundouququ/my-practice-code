#include<iostream>
#include<vector>

using namespace std;

vector<int> L;

int check(int mid, int length,int k)
{
    long long sum = 0;
    for(int i = 0; i < length;i++)
    { 
        sum += L[i] / mid;
    }
    if(sum >= k) return 1;
    else return 0;
}


int main()
{
    int n, k;//n 代表原木的数量，k代表需要的小段数量
    cin >> n >> k;
    int max = 0;
    for(int i = 1; i <= n;i++)
    {
        int temp;
        cin >> temp;
        L.push_back(temp);
        if(temp > max) max = temp;
    }
    int length = L.size();


    if(!check(1,length,k))
    {
        cout << 0;
        return 0;
    }

    int l = 1, r = max;
    while(l < r)
    {
        int mid = l + (r-l+1)/2;//加1是为了防止l和r接近的时候算出来的mid恰好是正确答案从而导致死循环
        if(check(mid,length,k) == 1)//检查是否真的能切成k段，这里是能
        {
            l = mid;//因为可能此时l已经是答案了，不能mid+1排除此答案，以防万一的写法
        }
        else//如果切不出来，说明mid太长了，不可能是答案，所以 r = mid -1
        {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}