#include <iostream>
using namespace std;

template <class T>
void cycle(T &a, T &b, T&c) {
  T temp;
  temp = a;
  a = b;
  b = c;
  c = temp;
}

int main() {
  int ia = 1;
  int ib = 2;
  int ic = 3;
  cout << "The current values of the ints: " << ia << " " << ib << " " << ic << endl;
  cycle(ia, ib, ic);
  cout << "The cycled values of the ints: " << ia << " " << ib << " " << ic << endl;

  char ca = 'a';
  char cb = 'b';
  char cc = 'c';

  cout << "The current values of the chars: " << ca << " " << cb << " " << cc << endl;
  cycle(ca, cb, cc);
  cout << "The cycled values of the chars: " << ca << " " << cb << " " << cc << endl;
}
