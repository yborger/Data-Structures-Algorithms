/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedQueue.h"


using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedQueue<T>::LinkedQueue() {
  //Because list is statically allocated, nothing needed here
  //Dynamically allocated version: this->newList = new STLList<T>();
}

template <typename T> int LinkedQueue<T>::getSize() {
  return this->newList.getSize();
}

template <typename T> bool LinkedQueue<T>::isEmpty() {
  return this->newList.isEmpty();
}

template <typename T> T LinkedQueue<T>::peek() {
  /*Retrieves the next element from the collection (without removing it).
  * This is the same element which would be returned by the take() method.
  * @return The next element in the collection.
  */
  return this->newList.getFirst();
}

template <typename T> void LinkedQueue<T>::enqueue(T element) {
  return this->newList.insertLast(element);
}

template <typename T> T LinkedQueue<T>::dequeue() {
  return this->newList.removeFirst();
}

template <typename T> void LinkedQueue<T>::insert(T element) {
  // NOTE: for a hint on how to implement this, see LinkedStack<T>::insert
  this->enqueue(element);
}

template <typename T> T LinkedQueue<T>::remove() {
  return this->dequeue();
}
