#include "linear_container.hpp"

template <class T>
class Queue : public LinearContainer<T> {
public:
  void push(T);
  T pop();
};

template <class T>
void Queue<T>::push(T) {

}

template <class T>
T Queue<T>::pop() {

}
