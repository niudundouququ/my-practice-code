#include<iostream>

using namespace std;
int main()
{
    int n, m;//n represents the length of array, m represents the times of check up
    cin >> n;
    int a[n]; //an array
    int p[n+1];//prefix sum array

    //type in the numbers
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // calculate the prefix sum
    p[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i-1] + a[i-1];
    }

    //check
    cin >> m;
    int l, r;
    for(int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << p[r] - p[l-1] << endl;
    }


    return 0;
}