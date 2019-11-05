#include "ListNode.h"
#include <cstdlib>
#include <cstddef>
#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList
{
private:
  ListNode<T>* front;
  ListNode<T>* back;
  unsigned int size;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  ListNode<T>* deletePos(int pos);
  ListNode<T>* find(T d);

  T returnFront();

  bool isEmpty();
  void printList();
  unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  if (!isEmpty())
  {

    ListNode<T>* curr = front;
    ListNode<T>* temp;

    while (curr != NULL)
    {
      temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
}


template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return (size == 0);
}

template <class T>
void DoublyLinkedList<T>::printList()
{
  ListNode<T>* curr = front;
  while (curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d)
{
  ListNode<T>* node = new ListNode<T>(d);

  if (isEmpty())
    back = node;
  else
  {
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}


template <class T>
T DoublyLinkedList<T>::removeFront()
{
  if (isEmpty())
  {
    cerr << "Error: Unable to remove empty front" << endl;
    exit(EXIT_FAILURE);
  }

  ListNode<T>* ft = front;

  if (front->next == NULL)
    back = NULL;
  else
    front->next->prev = NULL;

  front = front->next;
  T temp = ft->data;
  ft->next = NULL;
  size--;
  delete ft;
  return temp;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d)
{
  ListNode<T>* node = new ListNode<T>(d);
  if (isEmpty())
    front = node;
  else
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
T DoublyLinkedList<T>::removeBack()
{
  if (isEmpty())
  {
    cerr << "Error: Unable to remove empty back" << endl;
    exit(EXIT_FAILURE);
  }

  ListNode<T>* bk = back;

  if (back->prev == NULL)
    front = NULL;
  else
    back->prev->next = NULL;

  back = back->prev;
  T temp = bk->data;
  bk->prev = NULL;
  size--;
  delete bk;
  return temp;
}

template <class T>
T DoublyLinkedList<T>::returnFront()
{
  if (isEmpty())
  {
    cerr << "Error: Unable to return empty back" << endl;
    exit(EXIT_FAILURE);
  }
  return front->data;
}

template <class T>
ListNode<T>* DoublyLinkedList<T>::deletePos(int pos)
{
  if (isEmpty())
  {
    cerr << "Error: Unable to remove node in empty list" << endl;
    exit(EXIT_FAILURE);
  }

  ListNode<T>* curr = front;
  int index = 0;
  while (index != pos)
  {
    curr = curr->next;
    index++;
    if (curr == NULL)
      return NULL;
  }

  if (curr == front)
    front = curr->next;
  else
    curr->prev->next = curr->next;

  if (curr == back)
    back = curr->prev;
  else
    curr->next->prev = curr->prev;

  //T temp = curr->data;
  curr->next = NULL;
  curr->prev = NULL;
  size--;
  return curr;
}

template <class T>
ListNode<T>* DoublyLinkedList<T>::find(T d)
{
  if (isEmpty())
  {
    cerr << "Error: Unable to find node in empty list" << endl;
    exit(EXIT_FAILURE);
  }

  ListNode<T>* curr = front;

  while (curr->data != d)
  {
    curr = curr->next;
    if (curr == NULL)
      return NULL;
  }

  if (curr == front)
    front = curr->next;
  else
    curr->prev->next = curr->next;

  if (curr == back)
    back = curr->prev;
  else
    curr->next->prev = curr->prev;

  //T temp = curr->data;
  curr->next = NULL;
  curr->prev = NULL;
  size--;
  return curr;
}
