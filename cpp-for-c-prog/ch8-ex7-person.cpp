#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

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
  person() : name("Dolores Abernathy"), address("123 Fake St"), bd(*(new birth_date())), g(other) {}
  person(string name, string address, birth_date bd, gender g) : name(name), address(address), bd(bd), g(g) {}
  string get_name() { return name; };
  void set_name(string name) { this->name = name; }
  string get_address() { return address; }
  void set_address(string address) { this->address = address; }
  void print_bd() { cout << bd.bd_year << "-" << bd.bd_mon << "-" << bd.bd_mday; }
  void set_bd(string bd_string);
  string get_gender();
  void assign_person(int data_marker);
  virtual int get_number() = 0;
};

class student : virtual public person {
  int get_number() {
    return 1;
  }
};

class worker : virtual public person {
  int get_number() {
    return 2;
  }
};

class student_worker : public student, public worker {
  int get_number() {
    return 3;
  }
};

void set_bd(string bd_string) {
  string date_delimiter = "-";

  size_t pos = 0;
  string token;
  int i = 0;

  while ((pos = bd_string.find(date_delimiter)) != string::npos) {
    token = bd_string.substr(0, pos);
    cout << token << endl;
    bd_string.erase(0, pos + date_delimiter.length());
    i++;
  }
}

string person::get_gender() {
  switch(g) {
    case male: return "male";
    case female: return "female";
    case other: return "other";
  }
}

void person::assign_person(int data_marker) {
  // switch(data_marker) {
  //   case 0:
  // }
}

person& create_person(string person_type) {
  if (person_type == "student") {
    cout << "That's a student!" << endl;
    return *(new student());
  } else if (person_type == "worker") {
    cout << "That's a worker!" << endl;
    return *(new worker());
  } else {
    cout << "That's a student worker!" << endl;
    return *(new student_worker());
  }
}

void print_person(person& p_r) {
  // UNSOLVED
  cout << "My type is " << typeid(p_r).name() << endl;
  cout << "My number is " << p_r.get_number() << endl;
  // UNSOLVED
  cout << "The name is " << p_r.get_name() << endl;
  cout << "I live at " << p_r.get_address() << endl;
  cout << "I was born on ";
  p_r.print_bd();
  cout << endl;
  cout << "I identify as " << p_r.get_gender() << endl;
  cout << endl;
}

int main() {
  string line;
  string delimiter = ", ";
  ifstream personfile("ch8-ex7-person.txt");

  vector<unique_ptr<person>> v_p;

  if (personfile.is_open()) {
    while (getline(personfile, line)) {
      size_t pos = 0;
      string token;
      int i = 0;
      // person* p_p;

      while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        if (i == 0) {
          // EXPERIMENTAL PLS CLEAN UP
          if (token == "student") {
            student s = student();
            // p_p = &s;
            print_person(s);
            v_p.emplace_back(&s);
            // l_p.push_back(new student());
          } else if (token == "worker") {
            worker w = worker();
            // p_p = &w;
            print_person(w);
            v_p.emplace_back(&w);
          } else {
            student_worker sw = student_worker();
            // p_p = &sw;
            print_person(sw);
            v_p.emplace_back(&sw);
          }
          // p_p = &create_person(token);
          // cout << "The person type is " << typeid(*p_p).name() << endl;
        }
        cout << token << endl;
        line.erase(0, pos + delimiter.length());
        i++;
      }
      cout << line << endl << endl;

      // v_p.emplace_back(p_p);
    }
    personfile.close();
    cout << endl;
  }
  else cout << "Unable to open file." << endl;

  // All
  for (const auto &p_p : v_p) {
    print_person(*p_p);
  }

  // Students
  cout << "STUDENTS" << endl;
  for (const auto &p_p : v_p) {
    if (typeid(p_p) == typeid(student)) {
      print_person(*p_p);
    }
  }

  // Workers
  cout << "WORKERS" << endl;
  for (const auto &p_p : v_p) {
    if (typeid(p_p) == typeid(worker)) {
      print_person(*p_p);
    }
  }

  // Student Workers
  cout << "STUDENT WORKERS" << endl;
  for (const auto &p_p : v_p) {
    if (typeid(p_p) == typeid(student_worker)) {
      print_person(*p_p);
    }
  }
}
