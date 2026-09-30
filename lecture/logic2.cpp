#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f;
    int c1, c2, c3, c4, c5, c6;
    for( a = 0; a <= 1; a++)
        for(b = 0; b <= 1;b++)
            for(c = 0;c <= 1;c++)
                for(d = 0;d <= 1;d++)
                    for(e = 0; e <= 1; e++)
                        for(f = 0;f <= 1;f++)
                        {
                            c1 = a || b;
                            c2 = (a && e) || (a&&f) ||(e&&f);
                            c3 = !(a && d);
                            c4 = (b && c) || !(b || c);
                            c5 = (c && !d) || (!c && d);
                            c6 = d || (!d && !e);
                            if((c1+c2+c3+c4+c5+c6) == 6)
                            {
                                cout << a << b << c << d << e << f << endl;
                            }
                        }
    
    return 0;
}