#include <iostream>
#include <iomanip>
using namespace std;

double sum = 0.0;

bool judge(int a)
{
    if (a % 2 == 1 && a % 3 == 0)
    {
        sum += a;
        return true;
    }
    return false;
}

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int count = 0;
    if (judge(a)) count++;
    if (judge(b)) count++;
    if (judge(c)) count++;
    if (judge(d)) count++;
    if (judge(e)) count++;
    if (judge(f)) count++;

    if (count != 0)
        cout << fixed << setprecision(4) << sum/count << endl;
    else
        cout << 0.0000 << endl; //这样cout自动给你变成0输出了，sbcout

    return 0;
}