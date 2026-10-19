#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float x1(int a,int b,int c)
{
    return (-b + sqrt(b*b-4*a*c))/(2*a);
}

float x2(int a,int b,int c)
{
    return (-b - sqrt(b*b-4*a*c))/(2*a);
}


int main()
{
    cout << fixed << setprecision(3) << min(x1(1, -3, 2), x2(1,-3,2)) << " " << max(x1(1, -3, 2), x2(1,-3,2)) << endl;
    cout << fixed << setprecision(3) << min(x1(2, -5, 2), x2(2, -5, 2)) << " " << max(x1(2, -5, 2), x2(2, -5, 2)) << endl;
    cout << fixed << setprecision(3) << min(x1(-3, 10, 2), x2(-3, 10, 2)) << " " << max(x1(-3, 10, 2), x2(-3, 10, 2)) << endl;
    return 0;
}