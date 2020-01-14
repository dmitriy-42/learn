#include <iostream>
using namespace std;

int main()
{
  double x,v,t; //даёт большу точность чем int
  const float g = -9.8;
  cout << "Введите x0: ";
  cin >> x;
  cout << "Введите v0: ";
  cin >>  v;
  cout << "Введите t: ";
  cin >> t;

  cout << x+v*t+g*t*t/2 << "\n";
  cout << x+v*t+1.0/2*g*t*t << "\n";
  return 0;
}
