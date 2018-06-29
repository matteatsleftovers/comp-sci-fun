#include <iostream>

int gcd(int u, int v) {
  while (v != 0) {
    int r = u % v;
    u = v;
    v = r;
  }
  return u;
}

class rational {
public:
  rational(int n = 0) : a(n), q(1) {}
  rational(int i, int j);
  rational(double r) : q(BIG), a(r * BIG) {}
  void print() const { std::cout << a << " / " << q; }
  operator double() { return static_cast<double>(a)/q; }
  bool operator==(const rational other);
  bool operator!=(const rational other);
private:
  long a, q;
  enum { BIG = 100 };
};

rational::rational(int i, int j) {
  int d = gcd(i, j);
  a = i / d;
  q = j / d;
}

bool rational::operator==(const rational other) {
  return (this->a == other.a) && (this->q == other.q);
}

bool rational::operator!=(const rational other) {
  return !(*this == other);
}

inline int greater(int i, int j) { return (i > j ? i : j); }
inline double greater(double x, double y) { return (x > y ? x : y); }
inline rational greater(rational w, rational z) { return (w > z ? w : z); }

int main() {
  int i = 10, j = 5;
  float x = 7.0;
  double y = 14.5;
  rational w(10), z(3.5), zmax;

  std::cout << "\ngreater(" << i << ", " << j << ") = " << greater(i, j);
  std::cout << "\ngreater(" << x << ", " << y << ") = " << greater(x, y);
  std::cout << "\ngreater(" << i << ", ";
  z.print();
  std::cout << ") = " << greater(static_cast<rational>(i), z);
  zmax = greater(w, z);
  std::cout << "\ngreater(";
  w.print();
  std::cout << ", ";
  z.print();
  std::cout << ") = ";
  zmax.print();
  std::cout << std::endl;

  rational r(10, 30);
  rational s(20, 60);

  std::cout << "Oh yeah, while we're at it, this is what r looks like reduced: ";
  r.print();
  std::cout << std::endl;
  std::cout << "And this is what s looks like reduced: ";
  s.print();
  std::cout << std::endl;
  std::cout << "Is rational r equal to rational s? " << (r == s) << std::endl;
  std::cout << "Is rational r NOT equal to rational s? " << (r != s) << std::endl;
}
