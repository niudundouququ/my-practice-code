#include<iostream>
#include<vector>
using namespace std;

vector<int> H;

bool check(int height,int M)
{
    long long sum = 0; //最后用来和M比大小
    for(int i = 0; i < H.size(); i++)
    {
        if(H[i] > height) sum += H[i] - height;
    }
    return sum >= M;
}
//推荐写个check函数吧 返回bool

int main()
{
    int N, M;//N是数目的总数量，M表示需要木材的总长度
    cin >> N >> M;
    int maxh = 0;

    //把数组弄成全局变量
    for(int i = 1; i <= N; i++)
    {
        int a; cin >> a;
        H.push_back(a);
        if(a > maxh) maxh = a;//获取最高高度
    }
    //但这样得注意H只有n那么长

    int l = 0, r = maxh;
    int mid = l + (r-l)/2;
    while(l < r)
    {
        if(check(mid,M))
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    cout << mid;
    return 0;
}