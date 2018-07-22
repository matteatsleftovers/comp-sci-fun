#ifndef LINEAR_CONTAINER_H
#define LINEAR_CONTAINER_H

template <class T>
struct listelem {
  T              data;
  listelem<T>*   prev;
  listelem<T>*   next;
  listelem(T t, listelem<T>* prev, listelem<T>* next);
};

template <class T>
listelem<T>::listelem(T t, listelem<T>* prev, listelem<T>* next) {
  this->data = t;
  this->prev = prev;
  this->next = next;
}

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
  listelem<T>* head = 0;
  listelem<T>* tail = 0;
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
}

template <class T>
bool LinearContainer<T>::is_empty() {
  return !(this->head != 0 && this->tail != 0);
}

template <class T>
bool LinearContainer<T>::is_full() {
  bool is_full = true;
  return is_empty;
}

#endif
