#include <iostream>

double BMI(double weight,double height);
void printBMI(double BMI);

int main()
{
  double w,h;
  std::cin >> h >> w;
  printBMI(BMI(h,w/100.0));
  return 0;
}

double BMI(double weight, double height){return weight/(height*height);}

void printBMI(double BMI)
{
  if (BMI < 18.5) std::cout << "Underweight\n";
  else if (BMI < 25.0) std::cout << "Normal weight\n";
  else if (BMI < 30.0) std::cout << "Overweight\n";
  else std::cout << "Obesity\n";
}
