#include <iostream>
using namespace std;

int main()
{
  cout << "Это первая строка приветственого сообщения\nэто вторая строка которая сообщает о том что программа загадывает число\nчисло от 0 до 100\nУ вас 5 попыток...\n\nИгра началась\n";

  bool win = false;
  int random, retry;
  do
  {
    srand(time(NULL));
    random = rand() % 101;
    for (int i = 0;i < 5;i++)
    {
      cin >> retry;
      if (retry == random)
      {
        cout << "Поздравляю! Вы угадали\n";
        win = true;
        break;
      }
      else if (retry < random){cout << "Загаданное число больше";}
      else {cout << "Загаданное число меньше";}
      cout << "\n";
    }
    if (win){win = false;}
    else {cout << "Вы проиграли. Было загадано: " << random << "\n";}
    
    cout << "Хотите начать сначала? (1 - ДА )\n";

    cin >> retry;
  }
  while (retry == 1);


  if (retry == 451){cout << "Если хотите очень часто побеждать, используйте метод двоичного поиска.\n";}


  return 0;
}
