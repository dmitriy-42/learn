#include <stack>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <cmath>

struct name
{
  std::vector<double> data;
  std::vector<bool> isInt;
};

void fix(name &str);
void intoopn(name &str);
double calopn(name &str);

int main(int argc, char const *argv[])
{
  name sai;
  std::stack<char> buf;

  int inp_fd = 0;

  size_t count = 0;
  bool p = false;
  int t = 0;
  while(true)
  {
    char buffer;
    read(inp_fd, &buffer, 1);
    p = buffer == ' ' or buffer == '\n';
    if (p)
    {
      if (buf.size() != 0)
      {
        char s = buf.top();
        if (s < 58 and 47 < s)
        {
          sai.isInt.push_back(true);
          double b = 0;
          double k;
          if (t) k = pow(10, 1-t);
          else k = 1;
          while(buf.size())
          {
            b += (buf.top()-48)*k;
            buf.pop();
            k *= 10;
          }
          sai.data.push_back(b);
        }
        else
        {
          sai.isInt.push_back(false);
          sai.data.push_back(s);
          while(buf.size()){buf.pop();}
        }
      }
      t = 0;
    }
    else if (buffer != '.')
    {
      buf.push(buffer);
      if (t) t++;
    }
    else t = 1;
    if (buffer == '\n') break;
  }

  fix(sai);

  intoopn(sai);

  for (int i = 0; i < sai.data.size(); i++)
  {
    if (sai.isInt[i]) std::cout << sai.data[i] << ' ';
    else std::cout << (char)sai.data[i] << ' ';
  }
  std::cout << '\n' << calopn(sai);

  std::cout << '\n';
  return 0;
}


void intoopn(name &str)
{
  std::stack<char> s;
  char pri[3][2] = {{'+','-'},{'*','/'},{'^','^'}};

  name buf;
  for (int i = 0; i < str.data.size(); i++)
  {
    buf.data.push_back(str.data[i]);
    buf.isInt.push_back(str.isInt[i]);
  }
  str.data.clear();
  str.isInt.clear();

  for (int i = 0; i < buf.data.size();i++)
  {
    if (buf.isInt[i])
    {
      str.data.push_back(buf.data[i]);
      str.isInt.push_back(true);
    }
    else
    {
      if (buf.data[i] == '(') s.push(buf.data[i]);
      else if (buf.data[i] == ')')
      {
        while(s.top() != '(')
        {
          str.data.push_back((double)s.top());
          str.isInt.push_back(false);
          s.pop();
        }
        s.pop();
        s.pop();
      }
      else if (s.size())
      {
        char t = s.top();
        int a,b;
        for (int x = 0;x < 3; x++)
        {
          for (int y = 0;y < 2; y++)
          {
            if (t == pri[x][y]) a = x;
            if ((char)buf.data[i] == pri [x][y]) b = x;
          }
        }
        if (a >= b and s.top() != '(')
        {
          str.data.push_back((double)t);
          str.isInt.push_back(false);
          s.pop();
        }
      }
      if (buf.data[i] != ')')
      {
        s.push((char)buf.data[i]);
      }
    }
  }
  while(s.size())
  {
    str.data.push_back((double)s.top());
    str.isInt.push_back(false);
    s.pop();
  }
}


double calopn(name &str)
{
  std::stack<double> buf;
  for (int i = 0; i < str.data.size(); i++)
  {
    if (str.isInt[i])
    {
      buf.push(str.data[i]);
    }
    else
    {
      double a, b;
      b = buf.top();
      buf.pop();
      a = buf.top();
      buf.pop();
      switch((char)str.data[i])
      {
        case '+':
          a += b;
          break;
        case '-':
          a -= b;
          break;
        case '*':
          a *= b;
          break;
        case '/':
          a /= b;
          break;
        case '^':
          //a = pow(a,b);
          //
          //fix
          a = pow(b,a);
          break;
      }
      buf.push(a);
    }
  }
  return buf.top();
}


void fix(name &str)
{
  std::stack <name*> data;
  data.push(new name);
  for (int i = 0; i < str.data.size(); i++)
  {
    if ((not str.isInt[i]) and str.data[i] == '^')
      data.push(new name);
    else
    {
      data.top()->data.push_back(str.data[i]);
      data.top()->isInt.push_back(str.isInt[i]);
    }
  }
  if (data.size() == 1)
  {
    delete data.top();
    return;
  }
  str.data.clear();
  str.isInt.clear();
  while (data.size())
  {
    for (int i = 0; i < data.top()->data.size();i++)
    {
      str.data.push_back(data.top()->data[i]);
      str.isInt.push_back(data.top()->isInt[i]);
    }
    if (data.size() > 1)
    {
      str.data.push_back((double)'^');
      str.isInt.push_back(false);
    }
    data.pop();
  }
}


