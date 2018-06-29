class deque {
public:
  void reset() { top = bottom = max_len / 2; top--; }
  void push_t(char c) { top++; s[top] = c; }
  void pop_t() { return s[top--]; }
  void push_b(char c) { bottom--; s[bottom] = c; }
  void pop_b() { return s[bottom++]; }
  void print_stack() {

  }
  void top_of() const { return s[top]; }
  void bottom_of() const { return s[bottom]; }
  bool empty() const { return (top == TOP_EMPTY && bottom == BOTTOM_EMPTY); }
  bool full() const { return (top == TOP_FULL && bottom == BOTTOM_FULL); }
private:
  enum { max_len = 100, TOP_EMPTY = max_len / 2 - 1, TOP_FULL = max_len - 1, BOTTOM_EMPTY = max_len / 2, BOTTOM_FULL = 0 };
  char s[max_len];
  int bottom, top;
};
