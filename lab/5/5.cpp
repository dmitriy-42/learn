#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


int f(std::string * str)
{
  int i2 = 0;
  for (int i = 0; i < str->size(); i++)
  {
    if (str->at(i) == '.') break;
    i2 *= 10;
    i2 += (int)str->at(i) - 48;
  }
  return i2;
}



enum class Ind 
{
  id = 0,
  surv,
  Pclass,
  name,
  sex,
  age,
  sibsp,
  parch,
  ticket,
  fare,
  cabin,
  embar
};

//const int lenInt = (int)Ind::embar + 1;

struct Data
{
  bool is = false;
  std::string str = "";
};

struct FullData
{
  Data data[20];
};

int main()
{
  std::vector <FullData> data;
  
  {
    FullData u;
    data.push_back(u);
  }

  {
    std::ifstream file;
    file.open("./train.csv");

    if (!file.is_open())
    {
      std::cout << "Не удалось открыть файл './train.csv' для чтения" << "\n";
      return 0;
    }
    
    bool Rtext = false;
    int Rind = 0;
    char inp;
    
    while (file.get(inp))
    {
      if (inp == ',' and !Rtext) Rind++;
      /*
      if (Rind == lenInt)
      {
        std::cout << "read error\n";
        file.close();
      }
      */
      if (inp =='\r')
      {
        Rind = 0;
        FullData u;
        data.push_back(u);
      }

      int i = data.size()-1;

      if ((inp != '\r' and inp != ',') or Rtext)
      {
        data[i].data[Rind].is = true;
        data[i].data[Rind].str += inp;
      }
      
      if (inp == '"') Rtext = !Rtext;
    }
    file.close();
  }
  
  
  
  
  std::ofstream file;
  file.open("./out.csv");

  if (!file.is_open())
  {
    std::cout << "Не удалось открыть файл './out.csv' для записи" << "\n";
    return 0;
  }
  
  std::stringstream form;
  
  int s = 0;
  int sw = 0;
  int sm = 0;
  int s1 = 0, s2 = 0, s3 = 0;
  
  file << "Характеристика,Результат\r";
  for (int i = 0; i < data.size(); i++)
  {
    if (data[i].data[(int)Ind::surv].is)
    {
      int q = f(&data[i].data[(int)Ind::surv].str);
      if (q)
      {
        s++;
        if (data[i].data[(int)Ind::sex].is)
        {
          if (data[i].data[(int)Ind::sex].str[0] == 'f')
            sw++;
          else
            sm++;
        }
        if (data[i].data[(int)Ind::Pclass].is)
        {
          int r = f(&data[i].data[(int)Ind::Pclass].str);
          if (r == 1) s1++;
          if (r == 2) s2++;
          if (r == 3) s3++;
        }
      }
    }
  }
  file << "Общее число выживших," << s << '\r';
  file << "Число выживших из 1 класса," << s1 << '\r';
  file << "Число выживших из 2 класса," << s2 << '\r';
  file << "Число выживших из 3 класса," << s3 << '\r';
  file << "Количество выживших женщин," << sw << '\r';
  file << "Количество выживших мужчин," << sm << '\r';
  s = 0;
  sw = 0;
  sm = 0;
  std::vector <int> id18;
  int sa = 0, swa = 0, sma = 0;
  for (int i = 0; i < data.size(); i++)
  {
    if (data[i].data[(int)Ind::age].is)
    { 
      //form << data[i].data[(int)Ind::age].str;
      s++;
      int q = f(&data[i].data[(int)Ind::age].str);
      //form >> q;
      if (data[i].data[(int)Ind::sex].is)
      {
        if (data[i].data[(int)Ind::sex].str[0] == 'f')
        {
          swa += q;
          sw++;
        }
        else
        {
          sma += q;
          sm++;
        }
      }
      sa += q;
      if (q < 18)
      {
        int t = f(&data[i].data[(int)Ind::id].str);
        id18.push_back(t);
      }
    }
  }
  file << "Средний возраст пассажира," << (double)sa/(double)s << '\r';
  file << "Средний возраст женский," << (double)swa/(double)sw << '\r';
  file << "Средний возраст мужской," << (double)sma/(double)sm << '\r';
  s = 0;
  int q = 0, c = 0;
  for (int i = 0; i < data.size(); i++)
  {
    if (data[i].data[(int)Ind::embar].is)
    { 
      switch(data[i].data[(int)Ind::embar].str[0])
      {
        case 'Q':
        q++;
        break;
        case 'S':
        q++;
        break;
        case 'C':
        q++;
        break;
      }
    }
  }
  
  file << "\"Штат, в котором село больше всего пассажиров\",";
  if (c >= q and c >= s ) file << "Cherbourg_";
  if (q >= c and q >= s ) file << "Queenstown_";
  if (s >= q and s >= c ) file << "Southampton_";
  file << '\r';
  
  
  file << "\"Список идентификаторов несовершеннолетних (младше 18) пассажиров, через запятую\",\"";
  for (int i = 0; i < id18.size(); i++)
  {
    file << id18[i];
    if (i+1 != id18.size())
    {
      file << ',';
    }
  }
  file << "\"\r";

  file.close();
  
  return 0;
}
