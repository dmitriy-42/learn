#include <iostream>
#include <cmath>

const double e = 0.00005;
double z(double x, double a=0.0, double b=1.0, bool start=false);
double abs(double a);

int main()
{
    double x,dx,a,b,xe;
    std::cout << "Введите dx, a и b, x нач, x кон: ";
    std::cin >> dx >> a >> b >> x >> xe;
    double mi,ma,q;

    mi = z(x,a,b,true);
    ma = mi;
    
    for (;x - xe < e;x+=dx)
    {
        q = z(x);
        if (mi > q) mi = q;
        if (ma < q) ma = q;
        std::cout << "x = " << x << " z(x) = " << q << "\n";
    }
    std::cout << "max = " << ma << " min = " << mi << "\n";
    return 0;
}

double z(double x, double a, double b, bool start)
{
    static double af,bf;
    if (start)
    {
       af = a;
       bf = b;
    }

    if (x - af < e)
    {
        return abs(x);
    }
    else if (bf - x < e)
    {
        return tan(x);
    }
    return abs(x)+cos(x);
}

double abs(double a)
{
    if (a > 0)
    return a;
    return a*-1;
}