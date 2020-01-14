#include <iostream>

using namespace std;


int main()
{
  int n;
  long double x;

  cout << "ввидите число: ";
  cin >> x;
  cout << "ввидите степень: ";
  cin >> n;
  if (n < 0) x = 1/x;
  n = abs(n);
  if (x == 0.0){cout << "Недопустимое значение\n"; return 0;}
  double x0 = x;
  for (int i = 1;i<n;i++) x *= x0;
  cout << x << "\n";





  return 0;
}
