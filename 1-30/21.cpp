#include <iostream>
using namespace std;


int main()
{
  srand(time(NULL));
  char a[10][8];
  for (int i=0;i<10;i++)
  {
    for (int j=0;j<8;j++){a[i][j] = 0;}
  }
  a[rand()%11][rand()%9]=-1;
  for (int i = 0;i<5;i++)
  {
    int vi,vj;
    cin >> vi >> vj;
    vi--;
    vj--;
    if (vi < 0 or vi > 9 or vj < 0 or vj > 7){i--;cout << "Выход за границу массива\n";}
    else switch(a[vi][vj])
    {
      case 0:
        cout << "Нет\n";
        a[vi][vj] = 1;
        break;
      case 1:
        i--;
        cout << "Эту уже проверяли\n";
        break;
      case -1:
        cout << "Вы угадал\n";
        return 0;
        break;
    }
  }
  cout << "GAME OVER\n";
  return 0;
}
