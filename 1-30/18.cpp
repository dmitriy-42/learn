#include <iostream>
using namespace std;

int main()
{
  int a[20];
  int max = -100;
  int min = 100;
  
  srand(time(NULL));
  for (int i = 0;i<20;i++)
  {
    a[i] = rand() % 201 - 100;
    if (max < a[i]) max = a[i];
    if (min > a[i]) min = a[i];
    cout << a[i] << " ";
  }
  cout << "\n" << min << "\n" << max << "\n"; 
  return 0;
}
