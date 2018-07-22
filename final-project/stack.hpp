#include <iostream>
#include "linear_container.hpp"

template <class T>
class Stack : public LinearContainer<T> {
public:
  void push(T);
  T pop();
};

template <class T>
void Stack<T>::push(T t) {
  std::cout << "The value of T is " << t << "\n";
  if (this->head == 0 && this->tail == 0) { // Case of empty list
    std::cout << "Initialize stack" << "\n";
    listelem<T>* temp = new listelem<T>(t, 0, 0);
    this->head = temp;
    this->tail = temp;
  } else {
    std::cout << "Add new node" << "\n";
    listelem<T>* temp = new listelem<T>(t, 0, this->head);
    this->head->prev = temp;
    this->head = temp;
    std::cout << "The value of head is " << this->head->data << "\n";
  }
  std::cout << "\n";
}

template <class T>
T Stack<T>::pop() {
  std::cout << "Trying to pop this stack!" << "\n";
  std::cout << "The value of head is " << this->head->data << "\n";
  std::cout << "The value of tail is " << this->tail->data << "\n";
  assert(!(this->is_empty()));
  listelem<T>* temp = this->head;
  T data = temp->data;
  this->head = this->head->next;
  delete temp;
  return data;
}
