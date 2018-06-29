#include <iostream>
#include <string>
using namespace std;

struct dairy {
  string name;
  double weight;
  double calories;
  double protein;
  double fat;
  double carbs;
};

int main(void)
{
  double weight, ratio, calories;
  dairy americanCheese = { "American Cheese", 25, 375, 5, 8, 0 };
  cout << "Please enter the number of grams of your dairy." << endl;
  cin >> weight;
  ratio = weight / americanCheese.weight;
  calories = ratio * americanCheese.calories;
  cout << "That dairy has " << calories << " calories." << endl;
  return 0;
}
