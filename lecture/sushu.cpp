#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> sushu = {2,3};
    int n, sum = 0;
    cin >> n;//获取要查询的素数总数
    for(int i = 5; ; i++)
    {
        int check = 0;
        for(int j = 0; j < sushu.size() ; j++)
        {
            if(i % sushu[j] == 0) 
            {
                check = 1;
                break;
            }
        }
        if(check == 0) sushu.push_back(i);

        if(sushu.size() < n) continue;
        else break;
    }

    for(int i = 0; i < sushu.size();i++) sum += sushu[i];
    
    cout << sum;

    return 0;
}