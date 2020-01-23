#include <iostream>

using namespace std;

int main()
{
  long long unsigned n,d;
  short unsigned x = 0;
  d = 1;
  cout << "ввидите число: ";
  cin >> n;

  while (d <= n)
  {
    x += 1;
    d *= 2;
  }
  cout << x << "\n";

  return 0;
}
