#include <iostream>
#include <vector>

enum Order{ASC /*по возрастанию*/, DESC /*по убыванию*/};

void BozoSort(int a[],const int size, Order rev=Order::ASC);
void BozoSort(std::vector <int> &a, Order rev=Order::ASC);
void BozoSort(int* a, int* b, int* c, Order rev=Order::ASC);
bool IsSort(int a[], const int size, Order rev=Order::ASC);
bool IsSort(std::vector <int> a, Order rev=Order::ASC);
bool IsSort(int a, int b, int c, Order rev=Order::ASC);
void swap(int*, int*);
void print(int a[],const int size);
void print(std::vector <int> a);
void print(int a,int b,int c);

int main()
{
  int n;
  std::cin >> n;
  const int size = n;
  int ia[n];
  std::vector <int> va(n);
  int a,b,c;
  for (int i = 0;i < size;i++)
  {
    std::cin >> n;
    ia[i] = n;
    va[i] = n;
  }
  a = ia[0];
  b = ia[1];
  c = ia[2];
  std::cout << "\n";
  BozoSort(ia, size);
  print(ia, size);
  BozoSort(ia, size, Order::DESC);
  print(ia, size);

  BozoSort(va);
  print(va);
  BozoSort(va, Order::DESC);
  print(va);

  BozoSort(&a,&b,&c);
  print(a,b,c);
  BozoSort(&a,&b,&c, Order::DESC);
  print(a,b,c);
}

void print(int a[], int size)
{for (int i = 0;i < size;i++){std::cout << a[i] << " ";}    
 std::cout << "\n";}  
void print(std::vector <int> a)
{for (int i = 0;i < a.size();i++){std::cout << a[i] << " ";}
 std::cout << "\n";}
void print(int a,int b,int c)
{std::cout << a << " " << b << " " << c << "\n";}

void swap(int* a, int* b)
{
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

bool IsSort(int a[], const int size, Order rev)
{
  for (int i = 0;i < size-1;i++)
  {
    if (rev == Order::ASC){if (a[i]>a[i+1]) return false;}
    else if (a[i]<a[i+1]) return false;
  }
  return true;
}
bool IsSort(std::vector <int> a, Order rev)
{
  int size = a.size();
  size--;
  for (int i = 0;i < size;i++)
  {
    if (rev == Order::ASC){if (a[i]>a[i+1]) return false;}
    else if (a[i]<a[i+1]) return false;
  }
  return true;
}
bool IsSort(int a, int b, int c, Order rev)
{
  if (rev == Order::ASC){if (a <= b and b <= c) return true;}
  else if (a >= b and b >= c) return true;
  return false;
}

void BozoSort(int a[], const int size, Order rev)
{
  srand(time(NULL));
  int b, i1, i2;
  while(not IsSort(a,size,rev))
  {
    i1 = rand()%size;
    i2 = rand()%size;
    b = a[i1];
    a[i1] = a[i2];
    a[i2] = b;
  }
}

void BozoSort(std::vector <int> &a, Order rev)
{
  int size = a.size();
  srand(time(NULL));
  int b, i1, i2;          
  while(not IsSort(a, rev))
  {      
    i1 = rand()%size;
    i2 = rand()%size;
    b = a[i1];
    a[i1] = a[i2];
    a[i2] = b;
  }
}

void BozoSort(int* a, int* b, int* c, Order rev)
{
  srand(time(NULL));
  int i;
  while(not IsSort(*a, *b, *c,rev))
  {
    i = rand()%3;
    switch (i)
    {
      case 0: swap(c,b); break;
      case 1: swap(b,c); break;
      case 2: swap(a,b); break;
    }
  }
}
