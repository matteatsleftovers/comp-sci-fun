#include <iostream>
#include <string>
using namespace std;

struct point {
  double x, y, z;
};

int main(void)
{
  double x, y, z;
  cout << "Please give me an x coordinate." << endl;
  cin >> x;
  cout << "Please give me a y coordinate." << endl;
  cin >> y;
  cout << "Please give me a z coordinate." << endl;
  cin >> z;
  point p = { x, y, z };
  cout << "Fabulous. Your point has " << p.x << " for x, " << p.y << " for y, and " << p.z << " for z."<< endl;
  return 0;
}
