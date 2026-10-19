#include<iostream>
#include<cmath>
#include<iomanip>

#define pi 3.141592653589793

using namespace std;

double S(double R,double r,double h)
{
    return  2*pi*h*(R + r);
}

double V(double R,double r,double h)
{
    return pi*h*(R*R-r*r);
}


int main()
{
    cout << fixed << setprecision(5) << S(5.0, 2.0, 10.0) << " " << V(5.0, 2.0, 10.0) << endl;
    cout << fixed << setprecision(5) << S(3.5, 2.5, 5.5) << " " << V(3.5, 2.5, 5.5) << endl;
    cout << fixed << setprecision(5) << S(0.1, 0.001, 11.1) << " " << V(0.1, 0.001, 11.1) << endl;
    return 0;
}