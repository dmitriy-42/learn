#include <iostream>
#include "libbmp.h"

int main()
{
  BmpImg img;
  img.read("pic4.bmp");
  const int w = img.get_width() - 1, h = img.get_height() - 1;
  int s = 0;
  unsigned char endbit = 0x01;
  unsigned char out = 0x00;
  for (int x = w; x >= 0; x--)
  {
    for (int y = h; y >= 0; y--)
    {
      for (int i = 0; i < 3;i ++)
      {
        if (s >= 8)
        {
          out >>= 1;
          std::cout << out;
          if (out == '\0')
          { 
            std::cout << '\n';
            return 0;
          }
          out = 0x00;
          s = 0;
        }
        bool b;
        switch(i)
        {
          case 0:
            b = endbit & img.red_at(x, y);
            break;
          case 1:
            b = endbit & img.green_at(x, y);
            break;
          case 2:
            b = endbit & img.blue_at(x, y);
        }
        if (b) out |= endbit;
        out <<= 1;
        s++;
      }
    }
  }
  return 0;
}
