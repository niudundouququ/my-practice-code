#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m, c;//n行m列，c是首都的边长
    cin >> n >> m >> c;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    //构建前缀和
    vector<vector<int>> p(n + 1,vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            p[i][j] = p[i][j-1] + p[i-1][j] -p[i-1][j-1] +a[i][j];
        }

    //查询
    //这就是简单的计算，确实是正确的
    //我现在应该找到最适合建造首都的地方
    //这个时候只需要找到首都左上角的坐标(row,col)
    int r, co, sum, s = -100000;
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