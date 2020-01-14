#include <iostream>

size_t strlen( const char * string );
int strcmp( const char * string1, const char * string2 );
int strstr( char * string1, const char * string2 );
char* strcat( char * destptr, const char * srcptr );


int main()
{
  char s1[50];
  char s2[50];
  std::cin.getline(s1,50);
  std::cin.getline(s2,50);
  std::cout << strlen(s1) << " " << strlen(s2) << "\n";
  int t = strcmp(s1,s2);
  if (t == 0) std::cout << "Строки равны\n";
  else if (t == 1) std::cout << "Строка 1 больше строки 2\n";
  else std::cout << "Строка 2 больше строки 1\n";
  std::cout << strstr(s1,s2) << "\n";
  std::cout << strcat(s1,s2) << "\n";
  return 0;
}


char* strcat(char * destptr, const char * srcptr)
{
  int l1 = (int)strlen(destptr);
  int l2 = (int)strlen(srcptr);
  const int size = l1 + l2;
  for (int i = l1;i<size;i++) {destptr[i] = srcptr[i-l1];}
  return destptr;
}

int strstr( char * string1, const char * string2 )
{
  int l = (int)strlen(string2);
  int len = (int)strlen(string1)-l;
  int n = 0;
  while (n <= len)
  {
    bool istrue = true;
    for (int i=0;i<l;i++)
    {
      if (string1[n+i] != string2[i]) {istrue = false; break;}   
    }
    if (istrue) return n;
    n++;
  }
  return -1;
}

int strcmp(const char * string1, const char * string2)
{
  int n = 0;
  while (true)
  {
    if (string1[n] == string2[n]){if (string1[n] == '\0') return 0;}
    else if ((int)string1[n] > (int)string2[n]) return 1;
    else return -1;
    n++;
  }
}

size_t strlen( const char * string )
{
  size_t n = 0;
  while (string[n] != '\0') n++;
  return n;
}
