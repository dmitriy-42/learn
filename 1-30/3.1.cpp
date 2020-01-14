#include <iostream>
using namespace std;

int main()
{
  int x;
  int y;

  cout << "Введите x\nx = ";
  cin >> x;
  
  cout << "Введите y\ny = ";
  cin >> y;


  cout << "\nx + y = " << x + y << "\nx - y = " << x - y << "\nx * y = " << x * y << "\n";
  if (y != 0) cout << "x / y = " << x/y << "\n";
  
  return 0;
}
