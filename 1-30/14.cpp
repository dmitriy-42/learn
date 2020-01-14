#include <iostream>

using namespace std;

int main()
{
  long long s,l1,r1,l2,r2;
  cin >> s >> l1 >> r1 >> l2 >> r2;

  long long max,min;
  
  max = r1 + r2;
  min = l1 + l2;

  if (min == s) cout << l1 << " " << l2;
  else if (max == s) cout << r1 << " " << r2;
  else if (min < s and s < max)
  {
    long long smax_xmin = l1+r2;
    if (s == smax_xmin) cout << l1 << " " << r2;
    else if (s < smax_xmin) cout << l1 << " " << s - l1;
    else cout << s - r2 << " " << r2;
  }
  else cout << -1;
  cout << "\n";
  return 0;
}
