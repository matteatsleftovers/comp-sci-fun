#include <iostream>
using namespace std;

class deque {
public:
  void reset() { top = bottom = max_len / 2; top--; }
  void push_t(char c) { s[--top] = c; }
  char pop_t() { return s[top++]; }
  void push_b(char c) { s[++bottom] = c; }
  char pop_b() { return s[bottom--]; }
  void print_stack() {
    for (int i = top; i <= bottom; ++i) {
      cout << pop_t() << endl;
    }
  }
  void set_up_dummy_deque() {
    char number_string[] = "1234567890";
    for (int i = 0; i < 9; ++i) {
      if (number_string[i] != '\0') push_t(number_string[i]);
    }
    for (int i = 0; i < 9; ++i) {
      if (number_string[i] != '\0') push_b(number_string[i]);
    }
  }
  char top_of() const { return s[top]; }
  char bottom_of() const { return s[bottom]; }
  bool empty() const { return ((top == max_len / 2 - 1) && bottom == max_len / 2); }
  bool full() const { return (top == 0 && bottom == max_len - 1); }
private:
  static const int max_len = 100;
  char s[max_len];
  int bottom, top;
};

int main(void) {
  deque dq;
  dq.reset();
  cout << "The deque should be empty, and indeed it is " << dq.empty() << endl;
  dq.set_up_dummy_deque();
  cout << "The deque should no longer be empty, and indeed it is " << dq.empty() << endl;
  cout << "The top of the deque is " << dq.top_of() << endl;
  cout << "The bottom of the deque is " << dq.bottom_of() << endl;
  dq.print_stack();
  cout << "Look at that, the deque is empty again. Right? " << dq.empty() << endl;
}
