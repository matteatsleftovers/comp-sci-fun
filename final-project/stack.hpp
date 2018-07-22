#include "linear_container.hpp"

template <class T>
class Stack : public LinearContainer<T> {
public:
  void push(T);
  T pop();
};

template <class T>
void Stack<T>::push(T) {

}

template <class T>
T Stack<T>::pop() {

}
