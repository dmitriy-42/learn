#include <iostream>

size_t strlen( const char * string );
void wasd();
void XO();
void p2048();
void cp(int, int, char a[20][20][20], const char*);
void x(int x, int y,bool bat[20][20], char namebat[20][20][20]
    , int len, bool end=true);
void x(int x, int y,bool bat[20][20], char namebat[20][20][20]
    , int len[20], bool end=true);

bool StrStr(const char*, const char*);
void Help();
void ArgNotNameError();
void NotNameError();
void ArgError(char* arg,bool isfull = true);

int main(int argc, char** argv)
{
  bool hi = true;
  bool wyn = false;
  bool notname = false;
  bool fargerror = false;
  bool fullargerror;
  char cargerror[20];
  char username[20];
  username[0] = '\0';
  for (int i = 1;i < argc;i++)
  {
    if (StrStr(argv[i],"-help")) Help();
    else if (argv[i][0] == '-' and argv[i][1] != '-')
    {
      bool n = false;
      int k = 1;
      int g = 0;
      while (argv[i][k] != '\0')
      {
        switch (argv[i][k])
        {
          //case 'h':
          //  Help();
          case 'n':
            if (not n)
            {
              if (i == argc-1 and not wyn) ArgNotNameError();
              else if (argv[i+1][0] != '-')
              { 
                g = 0;
                do
                {username[g] = argv[i+1][g]; g++;}
                while (argv[i+1][g-1] != '\0');
                if (not n) n = true;
              }
              else if ((not wyn) and (not notname))
                notname = true;
            }
            break;
          case 'w':
            if (not wyn) wyn = true;
            break;
          case 'b':
            if (hi) hi = false;
            break;
          default:
            if (not fargerror)
            {
              fargerror = true;
              fullargerror = false;
              cargerror[0] = argv[i][k];
              cargerror[1] = '\0';
            };
        }
        k++;
      }
      if (n) i++;
    }
    else
    {
      /*if (StrStr(argv[i], "--help")) Help();
      else*/ if (StrStr(argv[i], "--xo")) XO();
      else if (StrStr(argv[i], "--2048")) p2048();
      else if (not fargerror)
      {
        fargerror = true;
        fullargerror = true;
        int k = 0;
        while (argv[i][k-1] != '\0')
        {
          cargerror[k] = argv[i][k];
        }
      }
    }
  }
  if (fargerror) ArgError(cargerror, fullargerror);
  if (notname and not wyn) ArgNotNameError();
  if (wyn)
  {
    std::cout << "Введите имя: ";
    std::cin.getline(username, 20);
  };

  if (username[0] == '\0') NotNameError();

  std::cout << argv[0] << "\n";
  if (hi) std::cout << "Привет, ";
  else std::cout << "Пока, ";
  std::cout << username << "\n";
  
  return 0;
}

void NotNameError()
{
  std::cout << "Нет имени\n";
  exit(3);
}

void ArgError(char * arg, bool isfull)
{
  if (not isfull) std::cout << "-";
  std::cout << arg << " не допустимый параметр\n";
  exit(2);
}

void ArgNotNameError()
{
  std::cout << "Отсутствует <имя> после аргумента -n\n";
  exit(1);
}

void Help()
{
  std::cout << "-h  --help  Отображает информацию о поддерживаемых аргументах командной строки. Если задан данный ключ, остальные игнорируются\n"
    << "-n <имя>  Выводит на экран сообщение: \"Привет, <имя>\". Если задан ключ -n, то слежующий за ним агрумент КС воспринимается как <имя>. Если <имя> не задано, вывести сообщение об ошибке"
    << "-b  Если задан данный ключ, то в предыдущем сообщении вместо \"Привет\", должно выводится \"Пока\"\n"
    << "-w  Если задан данный ключ, то программа должна спросить у пользователя как его зовут и если задан -n, то в сообщении \"Привет, <имя>\" вместо <имя> вывести то имя которое введено пользователем, при этом параметр <имя> после ключа -n вводить не обязательно\n";
  exit(0);
}

size_t strlen( const char * string )
{
  size_t n = 0;
  while (string[n] != '\0') n++;
  return n;
}

bool StrStr(const char* str1, const char* str2)
{
  int i = 0;
  while(true)
  {
    if (str1[i] != str2[i]) return false;
    if (str1[i] == '\0') return true;
    i++;
  }
}

void cp(int x, int y, char a[20][20][20], const char* b)
{
  int k = 0;
  do
  {a[x][y][k] = b[k]; k++;}
  while (b[k-1]!='\0');
}

void x(int x, int y,bool bat[20][20],
    char namebat[20][20][20],int len,bool end)
{
  //v 0.3
  int l[20];
  for (int i = 0;i<x;i++){l[i] = len;}
  ::x(x,y,bat,namebat,l,end);
}

void x(int x, int y,bool bat[20][20],
    char namebat[20][20][20],int len[20],bool end)
{
  //v 0.3
  if (end) system("clear");
  for (int iy = 0;iy < y;iy++)
  {
    for (int i = 0;i<3;i++)
    {
      for (int ix = 0;ix < x;ix++)
      {
        if (i != 1)
        {
          if (bat[ix][iy])
          {
            std::cout << "+";
            for (int k = 0;k<len[ix];k++){std::cout << "-";};
            std::cout << "+";
          }
          else for (int k = 0;k<len[ix]+2;k++)
          {std::cout << " ";};
        }
        else
        {
          bool strend = false;
          if (bat[ix][iy]) std::cout << "|";
          else std::cout << " ";
          for (int k = 0;k<len[ix];k++)
          {
            if ((not strend) and namebat[ix][iy][k] == '\0')
              strend = true;
            if (strend) std::cout << " ";
            else std::cout << namebat[ix][iy][k];
          }
          if (bat[ix][iy]) std::cout << "|";
          else std::cout << " ";
        }
      }
      std::cout << "\n";
    }
  }
}

void gameover(bool win)
{
  int inp;
  system("clear");
  if (win) std::cout << "Победа\n";
  else std::cout << "Game Over\n";
  std::cout << "Введите что нибуть для завершения\n";
  std::cin >> inp;
  system("clear");
}

void wasd()
{
  int inp = 0;
  while (inp != 5)
  {
    bool n[20][20];
    char b[20][20][20];
    for (int i = 0;i<3;i++){for (int j = 0;j<3;j++)n[i][j]=1;}
    n[0][0] = 0; n[0][2] = 0;
    n[2][0] = 0; n[2][2] = 0;
    for (int i = 0;i<3;i++)
    {
      for (int j = 0;j<3;j++)
      {
        b[i][2-j][0] = (char)(j*3+i+49);
      }
    }
    x(3,3,n,b,1);
    std::cout << 
      "4 - влево\n6 - вправо\n8 - вверх\n2 - вниз\n5 - ok\n";
    std::cout << "потвердите (5)\n";
    std::cin >> inp;
  }
}

void XO()
{
  wasd();
  srand(time(NULL));

  int inp = 0;
  bool playflag = true;
  bool play = true;
  while (inp != 5)
  {
    bool menu[20][20];
    char name[20][20][20];
    menu[0][0] = play;
    menu[1][0] = not play;
    name[0][0][0] = 'x';
    name[1][0][0] = 'o';
    x(2,1,menu,name,1);
    std::cin >> inp;
    switch (inp)
    {
      case 4:
        play = true;
        break;
      case 6:
        play = false;
        break;
    }
  }

  char pl[] = "ox";
  char map[20][20][20];
  for(int i=0;i<3;i++){for(int j=0;j<3;j++){cp(i,j,map," ");}}
  bool bat[20][20];
  for(int i=0;i<3;i++){for(int j=0;j<3;j++){bat[i][j]=false;}}
  bool end = false;
  bool win = false;
  int gps[2];
  int igps[2];
  bool iok = false;
  int ix, iy;
  gps[0] = 1; gps[1] = 1;
  igps[0] = 1; igps[1] = 1;
 
  while (not end)
  {
    {
      int a,b;
      if (playflag == play){a = gps[0];b = gps[1];}
      else {a = igps[0];b = igps[1];}
      bat[a][b] = true;
      x(3,3,bat,map,1);
      bat[a][b] = false;
    }
    if (playflag == play)
    {
      std::cin >> inp;
      switch (inp)
      {
        case 4: if (gps[0]>0) gps[0]--; break;
        case 6: if (gps[0]<2) gps[0]++; break;
        case 8: if (gps[1]>0) gps[1]--; break;
        case 2: if (gps[1]<2) gps[1]++; break;
        case 5:
          if (map[gps[0]][gps[1]][0] == ' ')
          {
            map[gps[0]][gps[1]][0] = pl[playflag];
            playflag = not playflag;
          }
          break;
      }
    }
    else
    {
      if (iok)
      {
        if (igps[0] == ix and igps[1] == iy)
        {
          map[ix][iy][0] = pl[playflag];
          iok = false;
          playflag = not playflag;
        }
        else if (igps[0] < ix) igps[0]++;
        else if (igps[0] > ix) igps[0]--;
        else if (igps[1] < iy) igps[1]++;
        else igps[1]--;
      }
      else
      {
        int ii[3][3];
        int ipl[3][3];
        for(int i=0;i<3;i++)
        {
          for(int j=0;j<3;j++)
          {
            ii[i][j] = 0;
            ipl[i][j] = 0;
          }
        }
        for (int i = 0;i < 3;i++)
        {
          for (int j = 0;j < 3;j++)
          {
            if (map[i][j][0] == pl[playflag])
            {
              ii[i][0]++;
              ii[j][1]++;
              if (i == j) ii[0][2]++;
              if (i == 2-j) ii[1][2]++;
            }
            else if (map[i][j][0] == pl[not playflag])
            {
              ipl[i][0]++;
              ipl[j][1]++;
              if (i == j) ipl[0][2]++;
              if (i == 2-j) ipl[1][2]++;
            }
          }
        }
        
        for (int t = 0;t<3;t++)
        {
          int j1, i1;
          for (int i = 0;i<3;i++)
          {
            if (t == 2 and i == 2) break;
            if (ii[i][t] == 2 or ipl[i][t] == 2)
            {
              for (int j = 0;j<3;j++)
              {
                switch (t)
                {
                  case 0:
                    i1 = i;
                    j1 = j;
                    break;
                  case 1:
                    i1 = j;
                    j1 = i;
                    break;
                  case 2:
                    if (i == 0){i1 = j; j1 = i1;}
                    else{i1 = 2-j; j1 = j;}
                    break;
                }
                if (map[i1][j1][0] == ' ')
                {
                  iok = true;
                  ix = i1; iy = j1;
                  break;
                }
              }
            }
            if (iok) break;
          }
          if (iok) break;
        }
        
        if (not iok)
        {
          ix = rand()%3; iy = rand()%3;
          if (map[ix][iy][0] == ' ') iok = true;
        }
      }
    }

    if (map[1][1][0] != ' ')
    {
      if (map[1][0][0] == map[1][1][0] 
          and map[1][1][0] == map[1][2][0]) end = true;
      else
        for (int i = 0;i<3;i++)
        {
          if (map[0][i][0] == map[1][1][0] 
              and map[1][1][0] == map[2][2-i][0])
          {end = true; break;}
        }
    }
    if (not end)
    {
      for (int i = 0;i<3;i+=2)
      {
        if (map[i][1][0] != ' ' 
            and map[i][0][0] == map[i][1][0]
            and map[i][1][0] == map[i][2][0]) 
        {end = true; break;}
        if (map[1][i][0] != ' '
            and map[0][i][0] == map[1][i][0]
            and map[1][i][0] == map[2][i][0])
        {end = true; break;}
      }
    }
    if (end and playflag != play) win = true;
    if (not end)
    {
      for (int i = 0;i<3;i++)
      {
        for (int j = 0;j<3;j++)
        {
          if (map[i][j][0] == ' ') end = true;
        }
        if (end) break;
      }
      end = not end;
    }
  }

  gameover(win);
}

void p2048()
{
  wasd();
  srand(time(NULL));
  bool free = true;
  bool end = false;
  bool bat[20][20];
  char map[20][20][20];
  int imap[4][4];
  int imap1[4][4];
  int inp;
  int len;
  for (int i = 0;i<4;i++)
  {
    for (int j = 0;j<4;j++)
    {
      bat[i][j]=true;
      cp(i,j,map,"0");
      imap[i][j] = 0;
      imap1[i][j] = 0;
    }
  }

  while (not end)
  {
    while (true)
    {
      int rx,ry;
      rx = rand()%4; ry = rand()%4;
      if (imap[rx][ry] == 0)
      {
        imap[rx][ry] = 2*(rand()%2+1);
        break;
      }
    }
    len = 1;
    for (int i=0;i<4;i++)
    {
      for (int j=0;j<4;j++)
      {
        if (imap[i][j]!=imap1[i][j])
        {
          imap1[i][j] = imap[i][j];
          int k = imap[i][j];
          std::cout << "k = " << k << "\n";
          int t = 0;
          char q[5];
          do
          {
            q[t] = k%10+48;
            k /= 10;
            t++;
          }
          while (0<k);
          if (len < t) len = t;
          t--;
          for (int u=0;u<t+1;u++){map[i][j][u] = q[t-u];}
        }
      }
    }
    bool flag = true;
    while (flag)
    {
      x(4,4,bat,map,len);
      std::cin >> inp;
      switch (inp)
      {
        case 8:
          break;
        case 2:
          break;
        case 4:
          for (int i = 0;i<4;i++)
          {
            for (int j = 0;j<4;j++)
            {
              int k = j;
              while (true)
              {
                k++;
                if (k==3)
                {
                  if (imap[i][k] == 0 or imap[i][k] == imap[])
                }
                else if (k==4) break;
                if imap[]
              }
            }
          }
          flag = false;
          break;
        case 6:
          break;
      }
    }
    
    free = false;
    for (int i = 0;i<4;i++)           
    {                    
      for (int j=0;j<4;j++)
      {
        if (imap[i][j] == 0)
          free = true;
        if (imap[i][j] == 2048)
          end = true;
      }
    }
    if (not free) end = true;
  }
  //gameover(free);
};
