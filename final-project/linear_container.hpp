#ifndef LINEAR_CONTAINER_H
#define LINEAR_CONTAINER_H

template <class T>
class LinearContainer {
public:
  LinearContainer<T>();
  LinearContainer<T>(int n);
  virtual void push(T) = 0;
  virtual T pop() = 0;
  bool is_empty();
  bool is_full();
protected:
  T* elements[10];
private:
  int size;
};

template <class T>
LinearContainer<T>::LinearContainer() {
  this->size = 10;
}

template <class T>
LinearContainer<T>::LinearContainer(const int n) {
  this->size = n;
  elements[size];
}

template <class T>
bool LinearContainer<T>::is_empty() {
  bool is_empty = true;
  for (int i = 0; i < size; ++i) {
    if (elements[i] != 0) {
      is_empty = false;
    }
  }
  return is_empty;
}

template <class T>
bool LinearContainer<T>::is_full() {
  bool is_full = true;
  for (int i = 0; i < size; ++i) {
    if (elements[i] == 0) {
      is_full = false;
    }
  }
  return is_empty;
}

#endif
