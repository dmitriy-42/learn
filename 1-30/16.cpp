#include <iostream>
#include <cmath>
using namespace std;

void factorization(int n);

int main()
{
  int t;
  cin >> t;

  factorization(t);

  return 0;
}


void factorization(int n)
{
  bool one = false;
  for (int i = 2;i <= n;i++)
  {
    int k = 0;
    while (n % i == 0)
    {
      k++;
      n /= i;
    }
    if (k)
    {
      if (one) cout << "*";
      else one = true;
      cout << i;
      if (k != 1) cout << "^" << k;
    }
  }
  cout << "\n";
}
