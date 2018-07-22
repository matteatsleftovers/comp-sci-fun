#include "linear_container.hpp"

template <class T>
class Queue : public LinearContainer<T> {
public:
  Queue<T>() : LinearContainer<T>() { };
  Queue<T>(int n) : LinearContainer<T>(n) { };
  void push(T);
  T pop();
};

template <class T>
void Queue<T>::push(T t) {
  LinearContainer<T>::push(t);
}

template <class T>
T Queue<T>::pop() {
  LinearContainer<T>::pop();
  std::cout << "Trying to pop this queue!" << "\n";
  std::cout << "The value of head is " << this->head->data << "\n";
  std::cout << "The value of tail is " << this->tail->data << "\n";
  assert(!(this->is_empty()));
  listelem<T>* temp = this->tail;
  T data = temp->data;
  this->tail = this->tail->prev;
  delete temp;
  return data;
}
