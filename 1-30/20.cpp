#include <iostream>
using namespace std;

void swap(int* a, int* b);
void mysort(int a[],int n);
void mysorttrue(int a[],int n);


int main()
{
  int s;
  cin >> s;
  const int n = s;
  int a[n];
  for (int i = 0;i<n;i++){cin >> a[i];}
  mysort(a, n);
  for (int i = 0;i<n;i++){cout << a[i] << " ";}
  cout << "\n";
  return 0;
}

void mysort(int a[],int n)
{
  bool isend;
  for (int i = 0; i < n;i++)
  { 
    isend = true;
    for (int j = i; j < n;j++)
    {
      int t = j;
      while (t > 0 and a[t] < a[t-1])
      {
        if (isend) isend = false;
        swap(a[t],a[t-1]);
        t--;
      }
      if (not isend) break;
    }
  }
}

void mysorttrue(int a[],int n)
{
  for (int j = 0; j < n;j++)
  {
    int t = j;
    while (t > 0 and a[t] < a[t-1])
    {
      swap(a[t],a[t-1]);
      t--;
    }
  }
}



void swap(int* a, int* b)
{
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}
