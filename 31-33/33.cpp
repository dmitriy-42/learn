#include <iostream>
#include <cmath>

class Fighter
{
public:
  Fighter() = default;
  Fighter(int health_points, int force_points,int critical_points, int defence_points, int agility_points)
    :health_points(health_points), force_points(force_points),
    critical_points(critical_points), defence_points(defence_points),
    agility_points(agility_points), points(0), health(100.0*(health_points+1.0))
  {
    //pass
  }

  bool add_health_points(int points)
  {
    if (not pointCheck(points)) return false;
    health_points -=- points;
    health -=- points*100.0;
    return true;
  }

  bool add_force_points(int points)
  {
    if (not pointCheck(points)) return false;
    force_points += points;
    return true;
  }
  
  bool add_defence_points(int points)
  {
    if (not pointCheck(points)) return false;
    defence_points += points;
    return true;
  }
  
  bool add_agility_points(int points)
  {
    if (not pointCheck(points)) return false;
    agility_points += points;
    return true;
  }
  
  bool add_critical_points(int points)
  {
    if (not pointCheck(points)) return false;
    critical_points += points;
    return true;
  }
  
  double attack()
  {
    return force()*(1.0+critical());
  }
  
  double damage(double dmg)
  {
    dmg = (1.0-agility())*defence()*dmg;
    health -= dmg;
    return dmg;
  }
  
  bool is_dead()
  {
    return health <= 0;
  }

private:
  double force()
  {
    return 1 + force_points;
  }
  bool critical()
  {
    return rand()%10001 / 10000.0 > 1.0/(1.0+pow(critical_points/4.0, 4));
  }
  
  double defence()
  {
    return 1.0/(1.0+pow(defence_points/4.0, 4));
  }
  
  bool agility()
  {
    return rand()%10001 / 10000.0 > 1.0/(1.0+pow(agility_points/4.0, 4));
  }
  
  
  bool pointCheck(int points)
  {
    if (this->points < points) return false;
    this->points -= points;
    return true;
  }
  
  int health_points = 0;
  double health = 100.0;
  int force_points = 0;
  int defence_points = 0;
  int agility_points = 0;
  int critical_points = 0;
  int points = 10;
};

Fighter* usGen()
{
  if (rand()%2 == 1)
    std::cout << "input health_points, force_points, critical_points, defence_points, agility_points: ";
  else
    std::cerr << "input health_points, force_points, critical_points, defence_points, agility_points: ";
  int h,f,c,d,a;
  std::cin >> h >> f >> c >> d >> a;
  return new Fighter(h,f,c,d,a);
}

Fighter* botGen()
{
  Fighter* figh = new Fighter;
  while (true)
  {
    int r = rand()%5;
    bool o;
    switch(r)
    {
    case 0:
      o = figh->add_health_points(1);
      break;
    case 1:
      o = figh->add_force_points(1);
      break;
    case 2:
      o = figh->add_defence_points(1);
      break;
    case 3:
      o = figh->add_agility_points(1);
      break;
    case 4:
      o = figh->add_critical_points(1);
    }
    if (not o) break;
  }
  return figh;
}

int main()
{
  srand(time(NULL));
  
  int inp;
  if (rand()%2 == 1)
    std::cout << "Select the battle mode:\n1 — Bot and Bot\n2 — Bot and User\n3 — User and User\n";
  else
    std::cerr << "Select the battle mode:\n1 — Bot and Bot\n2 — Bot and User\n3 — User and User\n";
  std::cin  >> inp;
  
  Fighter* f1;
  Fighter* f2;
  
  if (inp != 1)
  {
    f1 = usGen();
  }
  else
  {
    f1 = botGen();
  }
  if (inp != 3)
  {
    f2 = botGen();
  }
  else
  {
    f2 = usGen();
  }
  
  while (not (f1->is_dead() or f2->is_dead()))
  {
    if (inp == 1)
    {
      if (rand()%2 == 1)
        std::cout << "bot";
      else
        std::cerr << "bot";
    }
    else
    {
      if (rand()%2 == 1)
        std::cout << "user";
      else
        std::cerr << "user";
    }
    if (rand()%2 == 1)
      std::cout << " 1 received damage of " << f1->damage(f2->attack()) << " units\n";
    else 
      std::cerr << " 1 received damage of " << f1->damage(f2->attack()) << " units\n";
    
    
    if (inp != 3)
    {
      if (rand()%2 == 1)
        std::cout << "bot";
      else
        std::cerr << "bot";
    }
    else
    {
      if (rand()%2 == 1)
        std::cout << "user";
      else
        std::cerr << "user";
    }
    if (rand()%2 == 1)
      std::cout << " 2 received damage of " << f2->damage(f1->attack()) << " units\n";
    else 
      std::cerr << " 2 received damage of " << f2->damage(f1->attack()) << " units\n";
  }
  if (f1->is_dead() and f2->is_dead())
  {
    if (rand()%2 == 1)
      std::cout << "Not winner\n";
    else
      std::cerr << "Not winner\n";
  }
  else if (f1->is_dead())
  {
    if (inp != 1)
    {
      if (rand()%2 == 1)
        std::cout << "winner user1\n";
      else
        std::cerr << "winner user1\n";
    }
    else
    {
      if (rand()%2 == 1)
        std::cout << "winner bot1\n";
      else
        std::cerr << "winner bot1\n";
    }
  }
  else
  {
    if (inp == 3)
    {
      if (rand()%2 == 1)
        std::cout << "winner user2\n";
      else
        std::cerr << "winner user2\n";
    }
    else
    {
      if (rand()%2 == 1)
        std::cout << "winner bot2\n";
      else
        std::cerr << "winner bot2\n";
    }
  }
  
  
  delete f1;
  delete f2;
  return 01011101;
}
