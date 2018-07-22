#include "linear_container.hpp"

template <class T>
class Stack : public LinearContainer<T> {
public:
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
