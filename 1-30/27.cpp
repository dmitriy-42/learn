#include <iostream>

enum class ItemType{Sword, Bow, Spell, Magicka};
enum class TrueElement{None, Fire, Frizee, Electricity, Earth, Live, Dead, Water, Guard, Ice, Poison, Steam};
enum class Element{Fire, Air, Water, Earth};

struct Item 
{
  ItemType type;
  union Items
  {
    struct Sword{int damage;};
    struct Bow
    {
      int damage;
      int charge_time;
      double distance;
    };
    struct Spell
    {
      int damage;
      double distance;
      Element element;
    };
    struct Magicka
    {
      TrueElement elements[5];
    };
    Sword sword;
    Bow bow;
    Spell spell;
    Magicka magicka;
  };
  Items item;
};


// Создаёт и возвращает предмет со случайными характеристиками
Item getRandomItem();
// Выводит на экран информацию о предмете
void printItem(Item loot);


int main()
{
  const int len = 5;
  Item loots[len];
  int i = 0;
  for (;i<len;i++){loots[i] = getRandomItem();};
  for (i = 0;i<len;i++)
  {
    printItem(loots[i]);
    if (i<len-1) std::cout<<"\n";
  };
  return 0;
}


Item getRandomItem()
{
  static bool r = true;
  static int data = 0;
  enum Quality{Common, Uncommon, Rare, Epic, Legendary};

  if (r){srand(time(NULL)); r = false;}
  Item loot;
  if (data == 1 or data == 2) loot.type =(ItemType)(rand()%4);
  else loot.type = (ItemType)(rand()%3);

  int level = rand()%10;
  Quality quality = (Quality)(rand()%5);
  int damage = level*100.0 + ((int) quality)*20.0+rand()%21;
  if (damage == 0) damage = 1;
  double stat =level*20.0+((int)quality)*5.0 + 
    (double)(rand()%76) + 25.0;
  double size = ((double)(rand()%50)+25.0)/100.0;

  switch(loot.type)
  {
    case ItemType::Sword:
      loot.item.sword.damage = damage;
      break;
    case ItemType::Bow:
      loot.item.bow.damage = damage;
      loot.item.bow.charge_time = (int)(stat*size);
      loot.item.bow.distance=size*stat*
        (((double)(rand()%76)+25.0)/100.0);
      break;
    case ItemType::Spell:
      loot.item.spell.damage = damage;
      loot.item.spell.distance = rand()%100+1+(double)level*10
        +(double)quality*5.5;
      loot.item.spell.element = (Element)(rand()%4);
      break;
    case ItemType::Magicka:
      int i = 0;
      for (;i<5;i++)
      {loot.item.magicka.elements[i]=TrueElement::None;};

      int l = rand()%5+1;
      int len = 0;
      int elements[11];
      // 0 Fire  1 Frizee  2 Electricity  3 Earth
      // 4 Live  5 Dead    6 Water        7 Guard
      // 8 Ice   9 Poison 10 Steam
      int nel[4][2];
      nel[0][0] = 0; nel[0][1] = 1;
      nel[1][0] = 2; nel[1][1] = 3;
      nel[2][0] = 3; nel[2][1] = 4;
      nel[3][0] = 7; nel[3][1] = 7;
      int com[3][3]; //[0] + [1] = [2]
      com[0][0] = 0; com[0][1] = 6; com[0][2] = 10;
      com[1][0] = 5; com[1][1] = 6; com[1][2] = 9;
      com[2][0] = 1; com[2][1] = 6; com[2][2] = 8;
      for (i = 0;i < 11;i++){elements[i] = 0;};
      while (len < l)
      {
        len++;
        elements[rand()%8]++;
        
        if (elements[10]>0 and elements[1]>0)
        {elements[6]++; len--;
         elements[1]--; elements[10]--;};
        if (elements[9]>0  and elements[4]>0)
        {elements[6]++; len--;
         elements[4]--; elements[9]--;};
        if (elements[8]>0  and elements[0]>0)
        {elements[6]++; len--;
         elements[0]--; elements[8]--;};
       
        for (i = 0;i<4;i++)
        {
          if (elements[nel[i][0]]>0 and elements[nel[i][1]]>0)
          {
            elements[nel[i][0]]--;
            elements[nel[i][1]]--;
            len-=2;
          }
        }
        
        for (i = 0;i<3;i++)
        {
          if (elements[com[i][0]]>0 and elements[com[i][1]]>0)
          {
            elements[com[i][0]]--;
            elements[com[i][1]]--;
            elements[com[i][2]]++;
            len--;
          }
        }
      }
      
      len = 0;
      for (i=0;i<11;i++)
      {
        while (elements[i]>0)
        {
          elements[i]--;
          loot.item.magicka.elements[len]=(TrueElement)(i+1);
          len++;
        }
        if (len == l) break;
      }

      break;
  }

  data++;
  return loot;
}




void printItem(Item loot)
{
  using namespace std;
  switch(loot.type)
  {
    case ItemType::Sword:
      cout << "---SWORD---\nDamage: "
        << loot.item.sword.damage << "\n";
      break;

    case ItemType::Bow:
      cout << "---BOW---\nDamage: " << loot.item.bow.damage
        << "\nCharge Time: " << loot.item.bow.charge_time
        <<"\nDistance: "<<(int)loot.item.bow.distance << "\n";
      break;

    case ItemType::Spell:
      cout << "---SPELL---\nDamage: "<< loot.item.spell.damage
        << "\nElement: ";
      switch (loot.item.spell.element)
      {
        case Element::Fire:
          cout << "Fire";
          break;
        case Element::Air:
          cout << "Air";
          break;
        case Element::Water:
          cout << "Water";
          break;
        case Element::Earth:
          cout << "Earth";
          break;
      }
      cout << "\nDistance: "
        << (int) loot.item.spell.distance << "\n";
      break;

    case ItemType::Magicka:
      cout << "---Magicka---\n";
      bool end = false;
      for (int i = 0;i < 5;i++)
        {
          switch (loot.item.magicka.elements[i])
          {
            case TrueElement::Fire: cout << "Fire"; break;
            case TrueElement::Frizee: cout << "Frizee"; break;
            case TrueElement::Electricity: 
              cout << "Electricity"; break;
            case TrueElement::Earth: cout << "Earth"; break;

            case TrueElement::Live: cout << "Live"; break;
            case TrueElement::Dead: cout << "Dead"; break;
            case TrueElement::Water: cout << "Water"; break;
            case TrueElement::Guard: cout << "Guard"; break;

            case TrueElement::Steam: cout << "Steam"; break;
            case TrueElement::Poison: cout << "Poison"; break;
            case TrueElement::Ice: cout << "Ice"; break;
          }
          if (i == 4 or loot.item.magicka.elements[i+1]
              == TrueElement::None)
            break;
          cout << " + ";
        }
      cout << "\n";
      break;
  }
}
