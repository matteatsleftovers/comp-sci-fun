#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

template<typename Iter, typename T>
void print2largest(Iter it, Iter end, T example) {

  T first, second;

  if (it == end) { // There should be at least two elements
      printf(" Invalid Input ");
      return;
  }

  for (; it != end; ++it) {
    if (*it > first) {
      second = first;
      first = *it;
    } else if (*it > second && *it != first) {
      second = *it;
    }
  }

  cout << "The second largest element is " << second << endl;
}

int main() {
    std::vector<float> vf = {3.0, 4.0, 1.0, 5.0};
    print2largest(vf.begin(), vf.end(), *(vf.begin()));
    std::list<int> li = {100, 99, 98, 5};
    print2largest(li.begin(), li.end(), *(li.begin()));
    std::set<double> sd = {1.3, 1.7, 1.5, 5.0};
    print2largest(sd.begin(), sd.end(), *(sd.begin()));
}
