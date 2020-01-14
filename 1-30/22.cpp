#include <iostream>


int input(char n);

void swap(int* a, int* b); //using add
int msort(int* a, int* b, int* c); //using swap
void info(const int* a); //using print
int* add(int* a, const int* b);

void print();
void print(const int* a); //using print
void print(const int a, bool end);
void print(const int *a,bool end);
void printm(int* a, int* b, int* c, bool end); //using msort


int main()
{
  int a,b,c;
  a = input('a');
  b = input('b');
  c = input('c');
  
  print();
  info(&a);
  info(&b);
  info(&c);

  printm(&a,&b,&c, true);
  info(add(&a,add(&b,&c)));
  
  return 0;
}


void swap(int* a, int* b)
{
  add(a, b);
  *b = *a - *b;
  *a = *a - *b;
}

int msort(int* a, int* b, int* c)
{
  if (*b > *c) swap(b, c);
  if (*a > *b) swap(a, b);
  
  return *c;
}

void info(const int* a){print(a);}

int* add(int*a, const int* b)
{
  *a = *a + *b;
  return a;
}

int input(char n)
{
  std::cout << "введите число " << n << ": ";
  int a;
  std::cin >> a;
  return a;
}


void print(){std::cout << "\n";}
void print(const int* a)
{
  print(*a,false);
  print(a,true);
}

void printm(int* a,int* b,int* c,bool end)
{
  std::cout << "Максимум: " << msort(a,b,c);
  if (end) std::cout << "\n";
}
void print(const int* a,bool end)
{
  std::cout << "Адрес:" << a << "; ";
  if (end) std::cout << "\n";
}
void print(const int a,bool end)
{
  std::cout << "Значение: " << a << "; ";
  if (end) std::cout << "\n";
}
