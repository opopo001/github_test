#include <iostream>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;

/* Laguerre Polynomial L_n(z) == exp(z)*(d/dz)^n (z^n*exp(-z)) / n! */
ex LaguerrePoly(int n, const symbol & z)
{
    const ex LKer = exp(-z);
    return normal(diff(pow(z, n)*LKer, z, n) / LKer) / factorial(n);
}

/* Associated Laguerre Polynomial L_{n,m}(x) == (d/dx)^m L_n(x). */
ex LaguerrePoly(int n, int m, const symbol & z)
{
    return LaguerrePoly(n, z).diff(z, m);
}

int main()
{
    symbol x("x");
    
    for (int i=0; i<7; ++i) {
        cout << "    L_" << i << "(" << x << ") == "
             << LaguerrePoly(i, x) << endl;
        for (int j=1; j<=i; ++j) {
            cout << "L_{" << i << ',' << j << "}(" << x << ") == "
                 << LaguerrePoly(i, j, x) << endl;
        }
        cout << endl;
    }
    
    return 0;
}
