#pragma once

/**
2
* Выполняет следующие действия:
3
*  1. Очищает игровое поле заполняя его пробелами
4
*  2. Случайным образом определяет чей ход
5
*  3. Устанавливает симвод для Игрока (Задаётся параметром userChar)
6
*  4. Устанавливает символ для бота 
7
*  5. Возвращает заполненную структуру
8
*/

enum Status {
   PLAY,            // Игра продолжается
   USER_WIN,        // Игрок победил
   BOT_WIN,         // Бот победил
   NOT_WIN          // Ничья. Победителя нет, но и на поле нет свободной ячейки
};

struct Game{
   char bord[3][3];  // Игровое поле
   bool isUserTurn;  // Чей ход. Если пользователя, то isUserTurn = true
   char userChar;    // Символ которым играет пользователь
   char botChar;     // Символ которым играет бот
   Status status;
};


enum colar
{
  def = 0,    // стандартный
  black = 30, // чёрный
  red,        // красный
  green,      // зенёный
  yellow,     // жёлтый
  blue,       // синий
  magenta,    // фиолетовый
  cyan,       // голубой
  white,      // Белый
  bblack = 90,
  bred,
  bgreen,
  byellow,
  bblue,
  bmagenta,
  bcyan,
  bwhite,
};


struct d2text
{
  int x;
  int y;
  char text[50][50];
};

struct concof
{
  d2text text[20][20];
  int x, y, lx[20], ly[20];
  bool bat[20][20];
  colar col[2][2];
};


Game initGame(char userChar);

/**
12
* Выполняет следующие действия:
13
*  1. Очищает экран
14
*  2. Отображает содержимое игрового поля. Например так (можно по своему):
15
*         a   b   c
16
*       -------------
17
*     1 | O | O | X |
18
*       -------------
19
*     2 |   |   |   |
20
*       -------------
21
*     3 |   |   | X |
22
*       -------------
23
*/
void updateDisplay(const Game game);

/**
27
* Выполняет ход бота. В выбранную ячейку устанавливается символ которым играет бот.
28
* Бот должен определять строку, столбец или диагональ в которой у игрока больше всего иксиков/ноликов и ставить туда свой символ. Если на поле ещё нет меток, бот должен ставить свой знак в центр. В остальных случаях бот ходит рандомно.
29
*/
void botTurn(Game* game);

/**
33
* Функция отвечает за ход игрока. Если игрок вводит не допустимые
34
* значения, ругнуться и попросить ввести заново
35
*/
void userTurn(Game* game);

/**
39
* Функция определяет как изменилось состояние игры после последнего хода.
40
* Функция сохраняет новое состояние игры в структуре game и передаёт ход другому
41
* игроку.
42
* Функция возвращает true, если есть победитель или ничья, иначе false.
43
*/
bool updateGame(Game* game);

void scol(concof &con, colar f1=def, colar b1=def, colar f2=def, colar b2=def, bool set=false);

void setcol(colar f,colar b);
void endcol();
d2text* dontext(char, d2text*);
void cp(int x, d2text* tex, const char* b);

void xd2(bool start=false, d2text tex1[20]={},int lx1[20]={},int ly1=0,int x=0,colar f1=def, colar b1=def);

void x(const char namebat[3][3]);
void x(const int x, const int y, int lx, int ly, d2text namebat[20][20], bool bat[20][20], bool end=true);
void x(concof, const bool end=true);

