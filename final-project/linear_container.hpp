#ifndef LINEAR_CONTAINER_H
#define LINEAR_CONTAINER_H

#include "debug.hpp"

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
  log("Trying to push!");
  if (this->is_full()) {
    log("The container is full! Allocating more space...");
    this->max_size *= 2;
  }
  if (this->head == 0 && this->tail == 0) { // Case of empty list
    log("Initialize");
    listelem<T>* temp = new listelem<T>(t, 0, 0);
    this->head = temp;
    this->tail = temp;
  } else {
    log("Add new node");
    listelem<T>* temp = new listelem<T>(t, 0, this->head);
    this->head->prev = temp;
    this->head = temp;
  }
  current_size++;
}

template <class T>
T LinearContainer<T>::pop() {
  log("Trying to pop!");
  current_size--;
  return 0;
}

template <class T>
bool LinearContainer<T>::is_empty() {
  return !(this->head != 0 && this->tail != 0);
}

template <class T>
bool LinearContainer<T>::is_full() {
  log("Checking if full...");
  return current_size == max_size;
}

#endif
