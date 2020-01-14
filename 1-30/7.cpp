#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double a,b,c,p;

  cout << "выберете способ вычисления\n1 через длины\n2 через координаты\n";
  cin >> a;
  if (a == 1.0)
  {
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
  }
  else
  {
    int x1,y1,x2,y2,x3,y3;

    cout << "введите первые координаты : ";
    cin >> x1 >> y1;
    cout << "введите вторые координаты : ";
    cin >> x2 >> y2;
    cout << "введите третьи координаты : ";
    cin >> x3 >> y3;

    if (x1 == x2) a = abs(y1 - y2);
    else if (y1 == y2) a = abs(x1 - x2);
    else {
      int x12 = x1 - x2;
      int y12 = y1 - y2;

      a = sqrt(x12*x12+y12*y12);
    }
      

    if (x3 == x2) b = abs(y3 - y2);
    else if (y3 == y2) b = abs(x3 - x2);
    else {
      int x32 = x2 - x3;
      int y32 = y2 - y3;

      b = sqrt(x32*x32+y32*y32);
    }
      
      
    if (x1 == x3) c = abs(y1 - y3);
    else if (y1 == y3) c = abs(x1 - x3);
    else {
      int x13 = x1 - x3;
      int y13 = y1 - y3;

      c = sqrt(x13*x13+y13*y13);
    }
  }


  if (a + b <= c or a + c <= b or b + c <= a){cout << "такой триугольник не может существовать\n"; return 0;}

  p = (a+b+c)/2.0;
  cout << "S = " << sqrt(p*(p - a)*(p - b)*(p - c)) << "\n";

  return 0;
}
