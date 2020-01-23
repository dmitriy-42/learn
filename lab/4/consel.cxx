#include "head.h"
#include <iostream>
#include <fstream>






void userTurn(Game* game)
{
  bool end = false;
  concof con;
  scol(con);
  d2text logo;
  int x,y;
  bool ok;
  while (not end)
  {
	ok = true;
	int inp;
	std::cin >> inp;
	setcol(con.col[0][0],con.col[0][1]);
	switch (inp)
	{
	  case 7: x = 0; y = 0; break;
	  case 8: x = 1; y = 0; break;
	  case 9: x = 2; y = 0; break;
	  case 4: x = 0; y = 1; break;
	  case 5: x = 1; y = 1; break;
	  case 6: x = 2; y = 1; break;
	  case 1: x = 0; y = 2; break;
	  case 2: x = 1; y = 2; break;
	  case 3: x = 2; y = 2; break;
	  case 10102007:
		ok = false;
		endcol();
		scol(con,yellow,def,yellow,def,true);
		setcol(con.col[0][0],con.col[0][1]);
		dontext('l',&logo);
		for (int i = 0; i < logo.y;i++)
		  {std::cout << logo.text[i] << "\n";}
		break;
	  default:
		ok = false;
		std::cout << "[программа ругается]\n[программа просит ввести заново]";
	}
	endcol();
	if (game->bord[y][x] == 'n')
	{
	  end = true;
	  game->bord[y][x] = game->userChar;
	}
  }
}


/*
void colarmenu()
{
  int inp = 0;
  int gps = 0;
  concof con;
  for (int i = 0; i < 4)
	{con.ly[i] = 1}
  con.lx[0] = 1;
  con.x = 1;
  con.y = 4;
  for (int i = 0;i<3;i++)
  {
	con.bat[i][0] = false;
	if (i%2 == 1)
	  con.bat[i][0] = 'b';
	else
	  con.bat[i][0] = 'f';
  }
  scol(con);
  colar ncol[4];
  for (int i = 0; i < 4; i++)
  {
	ncol[i] = con.col[i/2][i%2];
  }
  while (inp !=5)
  {


	for (int i = 0;i<3;i++)
	  {con.bat[i][0] = false;}
	scol(con)
	x(con);
  }
}
*/


bool updateGame(Game* game)
{
  bool end = false;
  bool win = false;
  char map[3][3][1];
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
	  map[i][j][0] = game->bord[i][j];
    }
  }
  
  if (map[1][1][0] != 'n')
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
      if (map[i][1][0] != 'n' 
          and map[i][0][0] == map[i][1][0]
          and map[i][1][0] == map[i][2][0]) 
      {end = true; break;}
      if (map[1][i][0] != 'n'
          and map[0][i][0] == map[1][i][0]
          and map[1][i][0] == map[2][i][0])
      {end = true; break;}
    }
  }
  if (end and game->isUserTurn) win = true;
  if (not end)
  {
    for (int i = 0;i<3;i++)
    {
      for (int j = 0;j<3;j++)
      {
        if (map[i][j][0] == 'n') end = true;
      }
      if (end) break;
    }
    end = not end;
	if (end)
	{
	  game->status = NOT_WIN;
	  return true;
	}
  }
  if (end)
  {
	if (win) game->status = USER_WIN;
	else game->status = BOT_WIN;
	return true;
  }
  game->isUserTurn = not game->isUserTurn;
  return false;
}


Game initGame(char userChar)
{
  Game game;
  for (int i=0;i<9;i++)
  {
	game.bord[(i)/3][(i)%3] = 'n';
  }
  game.userChar = userChar;
  if (userChar == 'x')
  {
	game.botChar = 'o';
	game.isUserTurn = false;
  }
  else
  {
	game.botChar = 'x';
	game.isUserTurn = true;
  }
  game.status = PLAY;
  updateDisplay(game);
  return game;
}





void botTurn(Game* game)
{
  bool iok = false;
  int ix, iy;

  int ii[3][3];
  int ipl[3][3];
  char map[3][3][1];
  bool clear = true;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      ii[i][j] = 0;
      ipl[i][j] = 0;
	  map[i][j][0] = game->bord[i][j];
    }
  }
  for (int i = 0;i < 3;i++)
  {
    for (int j = 0;j < 3;j++)
    {
      if (map[i][j][0] == game->botChar)
      {
		if (clear) clear = false;
        ii[i][0]++;
        ii[j][1]++;
        if (i == j) ii[0][2]++;
        if (i == 2-j) ii[1][2]++;
      }
      else if (map[i][j][0] == game->userChar)
      {
		if (clear) clear = false;
        ipl[i][0]++;
        ipl[j][1]++;
        if (i == j) ipl[0][2]++;
        if (i == 2-j) ipl[1][2]++;
      }
    }
  }
  if (clear)
  {
	ix = 1; iy =1;
	iok = true;
  }
  else
  {
	for (int h = 0;h<2;h++)
	{
	  for (int t = 0;t<3;t++)
	  {
		int j1, i1;
		for (int i = 0;i<3;i++)
		{
		  if (t == 2 and i == 2) break;
		  if ((ii[i][t] == 2 or ipl[i][t] == 2) or (h and ipl[i][t] == 1))
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
		      if (map[i1][j1][0] == 'n')
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
	if (iok) break;
	}
  }
  
  if (not iok)
  {
    ix = rand()%3; iy = rand()%3;
    if (map[ix][iy][0] == 'n') iok = true;
  }

  game->bord[ix][iy] = game->botChar;
}







void scol(concof &con, colar f1, colar b1, colar f2, colar b2, bool set)
{
  static colar sf1 = def, sb1 = def;
  static colar sf2 = def, sb2 = def;
  if (set)
  {
	sf1 = f1; sb1 = b1;
	sf2 = f2; sb2 = b2;
  }
  con.col[0][0] = sf1;
  con.col[0][1] = sb1;
  con.col[1][0] = sf2;
  con.col[1][1] = sb2;
}


void updateDisplay(const Game game)
{
  x(game.bord);
}


d2text* dontext(const char text, d2text* tex)
{
  if (text == 'n')
  {
	cp(0,tex,"   ");
	cp(1,tex,"   ");
	cp(2,tex,"   ");
	tex->x = 3;
	tex->y = 3;
  }
  if (text == 'x')
  {
	cp(0,tex,"\\ /");
	cp(1,tex," x ");
	cp(2,tex,"/ \\");
	tex->x = 3;
	tex->y = 3;
  }
  if (text == 'o')
  {
	cp(0,tex,"/-\\");
	cp(1,tex,"| |");
	cp(2,tex,"\\-/");
	tex->x = 3;
	tex->y = 3;
  }
  if (text == 'l')
  {
	cp(0,tex, "             .,-:;//;:=,");
	cp(1,tex, "         . :H@@@MM@M#H/.,+%;,");
	cp(2,tex, "      ,/X+ +M@@M@MM%=,-%HMMM@X/,");
	cp(3,tex, "     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-");
	cp(4,tex, "    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.");
	cp(5,tex, "  ,%MM@@MH ,@%=            .---=-=:=,.");
	cp(6,tex, "  -@#@@@MX .,              -%HX$$%%%+;");
	cp(7,tex, " =-./@M@M$                  .;@MMMM@MM:");
	cp(8,tex, " X@/ -$MM/                    .+MM@@@M$");
	cp(9,tex, ",@M@H: :@:                    . -X#@@@@-");
	cp(10,tex,",@@@MMX, .                    /H- ;@M@M=");
	cp(11,tex,".H@@@@M@+,                    %MM+..%#$.");
	cp(12,tex," /MMMM@MMH/.                  XM@MH; -;");
	cp(13,tex,"  /%+%$XHH@$=              , .H@@@@MX,");
	cp(14,tex,"   .=--------.           -%H.,@@@@@MX,");
	cp(15,tex,"   .%MM@@@HHHXX$$$%+- .:$MMX -M@@MM%.");
	cp(16,tex,"     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=");
	cp(17,tex,"       =%@M@M#@$-.=$@MM@@@M; %M%=");
	cp(18,tex,"               =++%%%%+/:-.");
	tex->x = 40;
	tex->y = 19;
  }
  return tex;
}


void setcol(colar f,colar b)
{
  std::cout << "\033[" << (int)f;
  if (b != def)
  {
	b = (colar)((int)b + 10);
    std::cout << ";" << (int)b; 
  }
  std::cout << "m";
}
void endcol()
{
  std::cout << "\033[0m";
}



void cp(int x, d2text* tex, const char b[])
{
  int k = 0;
  do
  {
	tex->text[x][k] = b[k]; k++;
  }
  while (b[k]!='\0');
}


void xd2(bool start, d2text tex1[20],int lx1[20],int ly1,int x2,colar f1, colar b1)
{
  static d2text tex[20];
  static int lx[20], ly, i, x1, x;
  static colar f, b;
  if (start)
  {
	i = 0;
	x1 = 0;
	x = x2;
	for (int i = 0;i < x;i++){lx[i]=lx1[i];}
	ly = ly1;
	f = f1;
	b = b1;
	for (int k = 0; k < ly;k++)
	{
	  tex[k] = tex1[k];
	}
  }
  else
  {
	setcol(f,b);
	d2text p = tex[x1];
	int l = lx[x1];
	bool end = false;
	for (int k = 0;k < l;k++)
	{
	  if (k >= (l-p.x)/2 or k <= (l-p.x)/2+p.x)
	  {
		if (p.text[i][k-(l-p.x)/2] != '\0')
		{
		  std::cout << p.text[i][k-(l-p.x)/2];
		} 
		else
		{
		  std::cout << " ";
		  end = true;
		}
	  }
	  else std::cout << " ";
	}
	endcol();
	x1++;
	if (x1 == x){x1 = 0; i++;}
  }
}


void x(const char namebat[3][3])
{
  bool bat1[20][20];
  d2text namebat1[20][20];
  char g;

  for (int i = 0;i<3;i++)
  {
	
	for (int j = 0;j<3;j++)
	{
	  bat1[i][j] = true;
	  if (namebat[i][j] != 'n')
	  {
		dontext(namebat[i][j], &namebat1[i][j]);
	  }
	  else namebat1[i][j].x = 0;
	}
  }
  x(3,3,3,3,namebat1,bat1);
}



void x(const int x, const int y, int lx1, int ly1, d2text namebat[20][20], bool bat[20][20], bool end)
{
  concof con;
  for (int i = 0; i < x; i++) {con.lx[i] = lx1; }
  for (int i = 0; i < y; i++) {con.ly[i] = ly1; }
  con.x = x;
  con.y = y;
  for (int i = 0; i < x; i++)
  {
	for (int j = 0; j < y; j++)
	{
	  con.bat[i][j] = bat[i][j];
	  con.text[i][j] = namebat[i][j];
	}
  }
  scol(con);
  ::x(con,end);
}

void x(concof con,const bool end)
{
  if (end) system("clear");
  setcol(con.col[0][0], con.col[0][1]);
  endcol();
  for (int i1 = 0;i1<con.y;i1++)
  {
	xd2(true,con.text[i1],con.lx,con.ly[i1],con.x,con.col[0][0],con.col[0][1]);

	
	
	for (int i2 = 0;i2<con.x;i2++)
	{
	  if (con.bat[i1][i2])
	  {
		setcol(con.col[1][0],con.col[1][1]);
		std::cout << "+";
		endcol();
	  }
	  else
	  {
		setcol(con.col[0][0],con.col[0][1]);
		std::cout << " ";
		endcol();
	  }
	  for (int u = 0;u < con.lx[i1];u++)
	  {
	  if (con.bat[i1][i2])
	  {
		setcol(con.col[1][0],con.col[1][1]);
		std::cout << "-";
		endcol();
	  }
	  else
	  {
		setcol(con.col[0][0],con.col[0][1]);
		std::cout << " ";
		endcol();
	  }
	}
	  if (con.bat[i1][i2])
	  {
		setcol(con.col[1][0],con.col[1][1]);
		std::cout << "+";
		endcol();
	  }
	  else
	  {
		setcol(con.col[0][0],con.col[0][1]);
		std::cout << " ";
		endcol();
	  }
	}
	std::cout << "\n"; 
	  
	for (int i = 0;i<con.y;i++)
	{
	  for (int i2 = 0;i2<con.x;i2++)
	  {
		if (con.bat[i1][i2])
		{
		  setcol(con.col[1][0],con.col[1][1]);
		  std::cout << "|";
		  endcol();
		}
		else
		{
		  setcol(con.col[0][0],con.col[0][1]);
		  std::cout << " ";
		  endcol();
		}
		xd2();
		if (con.bat[i1][i2])
		{
		  setcol(con.col[1][0],con.col[1][1]);
		  std::cout << "|";
		  endcol();
		}
		else
		{
		  setcol(con.col[0][0],con.col[0][1]);
		  std::cout << " ";
		  endcol();
		}
	  }
	  std::cout << "\n"; 
	}


	for (int i2 = 0;i2<con.x;i2++)
	{
	  if (con.bat[i1][i2])
	  {
		setcol(con.col[1][0],con.col[1][1]);
		std::cout << "+";
		endcol();
	  }
	  else
	  {
		setcol(con.col[0][0],con.col[0][1]);
		std::cout << " ";
		endcol();
	  }
	  for (int u = 0;u < con.lx[i1];u++)
	  {
	  if (con.bat[i1][i2])
	  {
		setcol(con.col[1][0],con.col[1][1]);
		std::cout << "-";
		endcol();
	  }
	  else
	  {
		setcol(con.col[0][0],con.col[0][1]);
		std::cout << " ";
		endcol();
	  }
	}
	  if (con.bat[i1][i2])
	  {
		setcol(con.col[1][0],con.col[1][1]);
		std::cout << "+";
		endcol();
	  }
	  else
	  {
		setcol(con.col[0][0],con.col[0][1]);
		std::cout << " ";
		endcol();
	  }
	}
	std::cout << "\n"; 
	
  }
}