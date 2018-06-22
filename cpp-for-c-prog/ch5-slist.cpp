#include <iostream>
using namespace std;

struct slistelem {
  char        data;
  slistelem*  next;
};

class slist {
public:
  slist() : h(0) { }
  slist(const char* c);
  ~slist() {
    cout << "destructor invoked" << endl;
    release();
  }
  void append(slist& e);
  void prepend(char c);
  void copy(const slist &e);
  void del();
  slistelem* first() const { return h; }
  void print() const;
  void release();
  int length();
  int count_c(char c);
private:
  slistelem* h;
};

slist::slist(const char* c) {
  h -> data = *c;
}

void slist::append(slist &e) {
  cout << "Let's append!" << endl;
  slistelem* temp = h;

  cout << "The length of the list to append is " << e.length() << endl;

  e.prepend(temp -> data);
  temp = e.first();
  h = temp;
}

void slist::prepend(char c) {
  slistelem* temp = new slistelem;
  assert(temp != 0);
  temp -> next = h;
  temp -> data = c;
  h = temp;
}

void slist::del() {
  cout << "OH YEAH DELETE" << endl;
  if (h != 0) {
    slistelem* temp = h;
    h = h -> next;
    delete temp;
  }
}

void slist::print() const {
  slistelem* temp = h;

  while (temp != 0) {
    cout << temp -> data << " -> ";
    temp = temp -> next;
  }
  cout << "\n###" << endl;
}

void slist::release() {
  while (h != 0) del();
}

int slist::length() {
  int i = 0;
  slistelem* temp = h;

  while (temp != 0) {
    i++;
    temp = temp -> next;
  }
  return i;
}

int main() {
  slist* p;
  {
    char a = 'A';
    char* ap = &a;
    slist v(&a);

    // char b = 'B';
    // char* bp = &b;
    slist w = v;

    v.print();
    cout << "The list is " << v.length() << " long" << endl;

    v.append(w);
    v.print();
    cout << "The list is " << v.length() << " long" << endl;
    // w.del();
    // w.print();
    // cout << "The list is " << w.length() << " long" << endl;
    // p = &w;
    // p -> print();
    cout << "exiting inner block" << endl;
  }
  cout << "exiting outer block" << endl;
}
