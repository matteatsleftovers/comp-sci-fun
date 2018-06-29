#include <iostream>
using namespace std;

struct slistelem {
  char        data;
  slistelem*  next;
  slistelem(char c, slistelem* n);
};

slistelem::slistelem(char c, slistelem* n) {
  data = c;
  next = n;
}

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
  int length() const;
  int count_c(char c) const;
private:
  slistelem* h;
};

slist::slist(const char* c) {
  slistelem* temp;
  slistelem* to_add;

  if (*c != '\0') {
    to_add = new slistelem(*c, NULL);
    h = to_add;
    temp = h;
    c++;
  }

  while (*c != '\0') {
    to_add = new slistelem(*c, NULL);
    temp->next = to_add;
    temp = temp->next;
    c++;
  }
}

void slist::append(slist &e) {
  slistelem* temp = h;

  while (temp->next != NULL) { // Go to the end of the list
    temp = temp->next;
  }

  if (e.first() != NULL) {
    temp->next = e.first();
    temp = temp->next;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }
}

void slist::prepend(char c) {
  slistelem* temp = new slistelem(c, h);
  h = temp;
}

void slist::del() {
  if (h != NULL) {
    slistelem* temp = h;
    h = h->next;
    delete temp;
  }
}

void slist::print() const {
  slistelem* temp = h;

  while (temp != NULL) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "\n###" << endl;
}

void slist::release() {
  while (h != NULL) del();
}

int slist::length() const {
  int i = 0;
  slistelem* temp = h;

  while (temp != NULL) {
    i++;
    temp = temp->next;
  }
  return i;
}

int slist::count_c(char c) const {
  int i = 0;
  slistelem* temp = h;

  while (temp->next != NULL) {
    if (temp->data == c) i++;
    temp = temp->next;
  }
  return i;
}

int main() {
  const char* pc1 = "Hello, there.";
  slist v(pc1);
  v.print();
  cout << "The list is " << v.length() << " long" << endl;

  cout << "How many 'l's? " << v.count_c('l') << endl;

  const char* pc2 = "Nice weather outside.";
  slist w(pc2);
  w.print();
  cout << "The list is " << w.length() << " long" << endl;

  cout << "Now let's append these lists!" << endl;
  v.append(w);
  v.print();
  cout << "The list is " << v.length() << " long" << endl;
}
