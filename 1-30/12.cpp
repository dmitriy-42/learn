#include <iostream>

using namespace std;

int main()
{
  int n;
  bool k = false;
  cout << "ввидите число: ";
  cin >> n;
  
  for (int i = 2; i<n ;i++) if (n % i == 0)
  {
    cout << "составное\n";
    return 0;
  }
  cout << "простое\n";
  
  return 0;
}
