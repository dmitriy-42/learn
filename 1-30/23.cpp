#include <iostream>
using namespace std;

bool palindrom(char s[]);

int main()
{
  char s[40];
  cin.getline(s,40);
  if (palindrom(s)) cout << "Палиндром\n";
  else cout << "Не палиндром\n";
}


bool palindrom(char s[])
{
  char pol[40];
  int p = 0;
  char t[] = "qwertyuiopasdfghjklzxcvbnm1234567890";
  int size = 36;
  int n = 0;
  int i = 0;
  while (s[i] != '\0')
  {
    for (int j = 0; j < size; j++)
    {
      if (s[i] == t[j]){pol[p] = s[i]; p++;}
    }
    i++;
  }

  int p2 = p/2;
  p--;
  for (int i = 0;i<p2;i++)
  {
    if (pol[i] != pol[p-i]) return false;
  }
  return true;
}
