#include<iostream>

using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if((a/10)%10 == b) cout << "YES";
    else cout << "NO";
}