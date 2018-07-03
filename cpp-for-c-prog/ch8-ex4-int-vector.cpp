#include <iostream>
#include <vector>
using namespace std;

class int_vector : public vector<int> {
  using vector<int>::vector;
  using vector<int>::operator=;
};

int main() {
    int_vector x(4);
    assert(x[0] == 0);
    assert(x[1] == 0);
    assert(x[2] == 0);
    assert(x[3] == 0);
    cout << "The four ints of int_vector x are all initialized to 0!" << endl;
    cout << "Now swap with an int_vector y initialized with 1, 2, 3, 4..." << endl;
    int_vector y = {1, 2, 3, 4};
    x.swap(y);
    assert(x[0] == 1);
    assert(x[1] == 2);
    assert(x[2] == 3);
    assert(x[3] == 4);
    cout << "The four ints of int_vector x are 1, 2, 3, 4, in order!" << endl;
}
