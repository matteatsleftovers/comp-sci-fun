#include <iostream>
#include <list>
#include <string>
#include <typeinfo>

using namespace std;

struct birth_date {
  int bd_year;  // year since 1900
  int bd_mon;   // month of year from 0 to 11
  int bd_mday;  // day of month from 1 to 31

  birth_date() : bd_year(2095), bd_mon(1), bd_mday(1) {}
  birth_date(int year, int month, int day) : bd_year(year), bd_mon(month), bd_mday(day) {}
  birth_date(birth_date const &bd) : bd_year(bd.bd_year), bd_mon(bd.bd_mon), bd_mday(bd.bd_mday) {}
};

enum gender { male, female, other };

class person {
private:
  string name;
  string address;
  birth_date bd;
  gender g;
public:
  person() : name("Dolores Abernathy"), address("123 Fake St"), bd(*(new birth_date())), g(female) {}
  person(string name, string address, birth_date bd, gender g) : name(name), address(address), bd(bd), g(g) {}
  string get_name() { return name; };
  string get_address() { return address; }
  void print_bd() { cout << bd.bd_year << "-" << bd.bd_mon << "-" << bd.bd_mday; }
  string get_gender() {
    switch(g) {
      case male: return "male";
      case female: return "female";
      case other: return "other";
    }
  }
};

class student : virtual public person {

};

class worker : virtual public person {

};

class student_worker : public student, public worker {

};

int main() {
  person* p_p1 = new person();
  birth_date* bd = new birth_date(2088, 2, 14);
  person* p_p2 = new person("William", "456 Bogus Ave", *bd, male);
  list<person> l_p = { *p_p1, *p_p2 };

  for (person p : l_p) {
    cout << "The name is " << p.get_name() << endl;
    cout << "I live at " << p.get_address() << endl;
    cout << "I was born on ";
    p.print_bd();
    cout << endl;
    cout << "I identify as " << p.get_gender() << endl;
    cout << endl;
  }
}
