#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m, c;//n行m列，c是首都的边长
    cin >> n >> m >> c;

    //原数组用int就够了(单点值不超过32767)
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    //构建前缀和
    //前缀和数组必须用long long，不然会溢出
    vector<vector<long long>> p(n + 1,vector<long long>(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            p[i][j] = p[i][j-1] + p[i-1][j] -p[i-1][j-1] +a[i][j];
        }

    //这个时候只需要找到首都左上角的坐标(row,col)
    int r, co;
    long long sum, s = -1e18;
    //计算的区域应该是(row,col) (row+c-1,col+c-1)
    for(int row = 1; row <= n-c+1; row++)
        for(int col = 1; col <= m-c+1; col++)
        {
            sum = p[row+c-1][col+c-1] - p[row-1][col+c-1] -p[row+c-1][col-1] +p[row-1][col -1];
            if(sum > s)
            {
                s = sum;
                r = row;
                co = col;
            }
        }
    cout << r << " " << co << endl;
    return 0;
}