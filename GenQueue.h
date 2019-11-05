#include "DoublyLinkedList.h"

template <class T>
class GenQueue
{
public:
  GenQueue();
  ~GenQueue();

  void insert(T d);
  T remove();

  T peek();
  bool isFull();
  bool isEmpty();

  int getSize();

  DoublyLinkedList<T>* myQueue;
};

template <class T>
GenQueue<T>::GenQueue()
{
  myQueue = new DoublyLinkedList<T>;
}

template <class T>
GenQueue<T>::~GenQueue()
{
  delete myQueue;
}

template <class T>
void GenQueue<T>::insert(T d)
{
  myQueue->insertBack(d);
}

template <class T>
T GenQueue<T>::remove()
{
  return myQueue->removeFront();
}

template <class T>
T GenQueue<T>::peek()
{
  return myQueue->returnFront();
}

template <class T>
bool GenQueue<T>::isFull()
{
  return false;
}

template <class T>
bool GenQueue<T>::isEmpty()
{
  return myQueue->isEmpty();
}

template <class T>
int GenQueue<T>::getSize()
{
  return myQueue->getSize();
}
