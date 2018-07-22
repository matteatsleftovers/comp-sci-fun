template <class T>
class LinearContainer {
public:
  LinearContainer();
  LinearContainer(int n);
  virtual void push(T);
  virtual T pop();
private:
  int size;
};

LinearContainer::LinearContainer() {
  this->size = 10;
}

LinearContainer::LinearContainer(int n) {
  this->size = n;
}
