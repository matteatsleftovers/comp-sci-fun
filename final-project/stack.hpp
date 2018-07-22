#include "linear_container.hpp"

template <class T>
class Stack : public LinearContainer<T> {
public:
  Stack<T>() : LinearContainer<T>() { };
  Stack<T>(int n) : LinearContainer<T>(n) { };
  void push(T);
  T pop();
};

template <class T>
void Stack<T>::push(T t) {
  LinearContainer<T>::push(t);
}

template <class T>
T Stack<T>::pop() {
  LinearContainer<T>::pop();
  assert(!(this->is_empty()));
  listelem<T>* temp = this->head;
  T data = temp->data;
  this->head = this->head->next;
  delete temp;
  return data;
}
