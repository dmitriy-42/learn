#include <iostream>

using namespace std;

int main()
{
  int a,c;
  char b;

  cout << "ввидите выражение: ";
  cin >> a >> b >> c;
  switch (b)
  {
    case '*': cout << a * c; break;
    case '+': cout << a + c; break;
    case '-': cout << a - c; break;
    case '/':
      if (c == 0) cout << "∞";
      else cout << a / c;
      break;
    default: cout << "символ-знак опирации не рапознан";
  }
  cout << "\n";

  return 0;
}
