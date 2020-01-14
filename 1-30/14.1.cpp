#include <iostream>

using namespace std;

int main()
{
  long long s,l1,r1,l2,r2;
  cin >> s >> l1 >> r1 >> l2 >> r2;

  long long x1,x2;
  x2 = s - l1;
  if (l2 <= x2 and x2 <= r2) cout << l1 << " " << x2;
  else
  {
    x1 = s - r2;
    if (l1 <= x1 and x1 <= r1) cout << x1 << " " << r2;
    else cout << -1;
  }
  cout << "\n";
  return 0;
}
/*
s = x1 + x2
x2 = s - x1
*/
