#include <iostream>
using namespace std;

int main()
{
  int a, b;

  cout << "Введите a:\n";
  cin >> a;
  cout << "Введите b:\n";
  cin >> b;

  int c = a;
  a = b;
  b = c;

  cout << "\na = " << a << "\nb = " << b;

  b = a + b;
  a = b - a;
  b = b - a;

  cout << "\na = " << a << "\nb = " << b << "\n";
  return 0;
}
