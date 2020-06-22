#include <cln/integer.h>
#include <cln/real.h>
#include <iostream>
using namespace cln;

const cl_I fibonacci (int n)
{
    // Need a precision of ((1+sqrt(5))/2)^-n.
    float_format_t prec = float_format((int)(0.208987641*n+5));
    cl_R sqrt5 = sqrt(cl_float(5,prec));
    cl_R phi = (1+sqrt5)/2;
    return round1( expt(phi,n)/sqrt5 );
};

int main()
{
std::cout << fibonacci(1) << std::endl;;
return 0;
};
