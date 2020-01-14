#include <iostream>
using namespace std;

int main()
{
  int s;
  cin >> s;
  const int n = s;
  int a[n][2];
  for (int i = 0; i < n;i++)
  {
    for (int j = 0; j < 2;j++){a[n][j] = 0;}
  }
  s = 0;
  bool r;
  int v;
  for (int i = 0;i < n; i++)
  {
    cin >> v;
    r = false;
    for (int i = 0;i < s;i++)
    {
      if (a[i][0] == v)
      {
        a[i][1]++;
        r = true;
        break;
      }
    }
    if (not r)
    { 
      a[s][0] = v;
      a[s][1] = 1;
      s++;
    }   
  }
  for (int i = 0; i < s; i++){cout << a[i][0] << ": " << a[i][1] << "\n";}
  return 0;
}
