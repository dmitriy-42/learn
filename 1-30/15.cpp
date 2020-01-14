#include <iostream>
using namespace std;


int main()
{
  int k;
  cin >> k;

  int p;
  int m0,m1,m2,m3,m4,l,r;

  l = 0;
  for (int i = 0;i < k;i++)
  {
    cin >> p;
    
    switch(l){
      case 5:
        if (p < m4)
        {
          if (p < m2)
          {
            m4 = m3;
            m3 = m2;
            if (p < m0)
            {
              m2 = m1;
              m1 = m0;
              m0 = p;
            }
            else if (p < m1)
            {
              m2 = m1;
              m1 = p;
            }
            else m2 = p;
          }
          else if (p < m3)
          {
            m4 = m3;
            m3 = p;
          }
          else m4 = p;
        }
        
        cout << m4 << " " << m3 << " " << m2 << " " << m1 << " " << m0;
        break;
      case 4:
        l++;
        if (p < m3)
        {
          m4 = m3;
          if (p < m1)
          {
            m3 = m2;
            m2 = m1;
            if (p < m0)
            {
              m1 = m0;
              m0 = p;
            }
            else m1 = p;
          }
          else
          {
            if (p < m2)
            {
              m3 = m2;
              m2 = p;
            }
            else m3 = p;
          }
        }
        else m4 = p;

        cout << m4 << " " << m3 << " " << m2 << " " << m1 << " " << m0;
        break;
      case 3:
        l++;
        if (p < m2)
        {
          m3 = m2;
          if (m1 < p)
          {
            m2 = m1;
            if (m0 < p)
            {
              m1 = m0;
              m0 = p;
            }
            else m1 = p;
          }
          else m2 = p;
        }
        else m3 = p;

        cout << m3 << " " << m2 << " " << m1 << " " << m0;
        break;
      case 2:
        l++;
        if (p < m1)
        {
          m2 = m1;
          if (p < m0)
          {
            m1 = m0;
            m0 = p;
          }
          else m1 = p;
        }
        else m2 = p;

        cout << m2 << " " << m1 << " " << m0;
        break;
      case 1:
        l++;
        if (p < m0)
        {
          m1 = m0;
          m0 = p;
        }
        else m1 = p;

        cout << m1 << " " << m0;
        break;
      case 0:
        l++;
        m0 = p;
        cout << m0;
        break;
    }
    cout << "\n";
  }

  return 0;
}
