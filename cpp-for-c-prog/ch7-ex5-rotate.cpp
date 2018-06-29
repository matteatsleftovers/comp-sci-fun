#include <iostream>
using namespace std;

template <class T>
void rotate(T array[], int n) {
  T temp;
  temp = array[n - 1];
  for (int i = n - 1; i > 0; i--) {
    array[i] = array[i - 1];
  }
  array[0] = temp;
}

int main() {
  int i_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 9;
  for (int i = 0; i < n; i++) {
    cout << "Array element " << i << " has the value " << i_array[i] << endl;
  }
  rotate(i_array, n);
  for (int i = 0; i < n; i++) {
    cout << "Array element " << i << " now has the value " << i_array[i] << endl;
  }

  char c_array[] = {'a', 'b', 'c'};
  n = 3;

  for (int i = 0; i < n; i++) {
    cout << "Array element " << i << " has the value " << c_array[i] << endl;
  }
  rotate(c_array, n);
  for (int i = 0; i < n; i++) {
    cout << "Array element " << i << " now has the value " << c_array[i] << endl;
  }
}
