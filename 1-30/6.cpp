#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  double a,b,c;
  cout << "Ввидите a: ";
  cin >> a;
  cout << "Ввидите b: ";
  cin >> b;
  cout << "Ввидите c: ";
  cin >> c;

  if (a == 0)
  {
    if (b == 0)
    {
      if (c == 0) {cout << "x может быть любым числом";}
      else cout << "решения нет";
    }
    else cout << "x = " << -c/b;
  }

  else
    {
      if (b == 0)
      {
        if ((c > 0 and a > 0) or (c < 0 and a < 0))) cout << "нет решения в действительной области";
        else 
        {
          c = sqrt(abs(c))/a;
          cout << "x1 = " << -c << "\nx2 = " << c;
        }
      }
      else
      {
      a *= 2;                   //что бы не умнажать дваждый
      c = b*b - 2*a*c;         //Дискрименат (перезаписываю для экономии памяти)
      if (c > 0)
      {
        double x1,x2;
        c = sqrt(c);
        x1 = (-b + c)/a;
        x2 = (-b - c)/a;
        if (x1 == x2) cout << "x = " << x1;
        else
        {
          cout << "x1 = " << x1;
          cout << "\nx2 = " << x2;
        }
      }
      else cout << "нет решения в действительной области";
    }
  }

  cout << "\n";

  return 0;
}
