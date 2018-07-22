#ifndef LINEAR_CONTAINER_H
#define LINEAR_CONTAINER_H

#include <iostream>

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
  LinearContainer<T>() { };
  LinearContainer<T>(int n);
  virtual void push(T t);
  virtual T pop();
  bool is_empty();
  bool is_full();
protected:
  listelem<T>* head = 0;
  listelem<T>* tail = 0;
private:
  int current_size = 0;
  int max_size = 10;
};

template <class T>
LinearContainer<T>::LinearContainer(const int n) {
  this->max_size = n;
}

template <class T>
void LinearContainer<T>::push(T t) {
  std::cout << "Trying to push!" << "\n";
  std::cout << "The value of T is " << t << "\n";
  if (this->is_full()) {
    std::cout << "The container is full! Allocating more space..." << "\n";
    this->max_size *= 2;
    std::cout << "There are now " << max_size << " spaces allocated." << "\n";
  }
  if (this->head == 0 && this->tail == 0) { // Case of empty list
    std::cout << "Initialize" << "\n";
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
  current_size++;
}

template <class T>
T LinearContainer<T>::pop() {
  current_size--;
  return 0;
}

template <class T>
bool LinearContainer<T>::is_empty() {
  return !(this->head != 0 && this->tail != 0);
}

template <class T>
bool LinearContainer<T>::is_full() {
  std::cout << "Checking if full..." << "\n";
  std::cout << "current_size is " << current_size << "\n";
  std::cout << "max_size is " << max_size << "\n";
  return current_size == max_size;
}

#endif
