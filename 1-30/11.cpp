#include <iostream>
using namespace std;

int main()
{
  int n,x;
  
  cout << "введите число: ";
  cin >> n;

  x = 1;
  for (int i = 2;i<=n;i++) x *= i;
  cout << n << "! = " << x << "\n";

  return 0;
}
