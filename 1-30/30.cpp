#include <iostream>

char * strtok(char * string, const char * delim );

int main()
{
  char str[500];
  char delim[20];
  std::cin.getline(str, 500);
  std::cin.getline(delim, 10);
  char * o = strtok(str, delim);
  int i = 0;
  while (str[0] != '\0')
  {
    std::cout << str << "\n";
    o = strtok(str, delim);
    i++;
  }
  std::cout << "Words: " << i << "\n";
  return 0;
}


char * strtok(char * string, const char * delim)
{
  static int k = 0; 
  static const int maxlen = 500;
  static bool start = true;
  static char str[maxlen];
  int i = 0;

  if (start)
  {
    start = false;
    for (;i < maxlen;i++)
    {
      str[i] = string[i];
      if (str[i] == '\0') break;
    }
    if (i == maxlen) str[i-1] = '\0';
    i = 0;
    k = 0;
  }

  while (str[k] != '\0')
  {
    int n = 0;
    bool flag = false;
    while (delim[n] != '\0')
    {
      if (str[k] == delim[n]){flag = true; break;};
      n++;
    }
    
    if (not flag)
    {
      string[i] = str[k];
      i++;
    }
    else if (i != 0) break;
    k++;
  }
  if (str[k] == '\n' and i == 0) start = true;
  string[i] = '\0';

  return string;
}
