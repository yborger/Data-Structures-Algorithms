/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////

template <typename T> LinkedList<T>::LinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}

template <typename T> LinkedList<T>::~LinkedList() {

  if(this->size > 0){
    LinkedListNode<T> *currentNode = this->head;
    LinkedListNode<T> *nextNode = this->head->next;

    while(nextNode != nullptr){
      delete currentNode;
      currentNode = nextNode;
      nextNode = nextNode->next;
    }

    delete currentNode;
      
  }
  
}

template <typename T> void LinkedList<T>::checkInvariants() {
  if(size < 0){
    throw runtime_error("Size cannot be less than zero.");
  }
  if(this->tail != nullptr && this->tail->next != nullptr){
    throw runtime_error("There cannot be an element after tail.");
  }
 
}

template <typename T> int LinkedList<T>::getSize() {
  return this->size;
}

template <typename T> bool LinkedList<T>::isEmpty() {
  return (this->size == 0);
}

template <typename T> T LinkedList<T>::getFirst() {
  if(this->size==0){
    throw runtime_error("Can't get first value of empty list");
  }
  return this->head->value;
}

template <typename T> T LinkedList<T>::getLast() {
  if(this->size==0){
    throw runtime_error("Can't get last value of empty list");
  }
  return this->tail->value;
}

template <typename T> T LinkedList<T>::get(int index) {
  LinkedListNode<T>* currentNode;
  if(index>=this->size || this->size == 0 || index<0){
    throw runtime_error("Index does not exist in this LinkedList");
  }
  currentNode = this->head;
  for(int i = 0; i < index; i++){
    currentNode = currentNode->next;
  }
  return currentNode->value;
}

template <typename T> void LinkedList<T>::insertFirst(T value) {
  LinkedListNode<T> *fresh = new LinkedListNode<T>(value, this->head);
  this->head = fresh; //reassign the private var head to the new node
  this->size++;
  if (this->size == 1){ //tail would be unassigned otherwise, leading to other errors
    this->tail = fresh;
  }
}

template <typename T> void LinkedList<T>::insertLast(T value) {
  LinkedListNode<T> *fresh = new LinkedListNode<T>(value, nullptr);
  if (this->size == 0){ //empty array means we need both head and tail to be this new element
    this->head = fresh;
    this->tail = fresh;
  }
  else{
    this->tail->next = fresh;
    this->tail = fresh; //reassign the private var tail to the new node
  }
  this->size++;
  
}

template <typename T> T LinkedList<T>::removeFirst() {

  T nValue;
  
  if(this->size == 0){
    throw runtime_error("Index does not exist in this LinkedList");
  }
  if(this->size == 1){
    nValue = this->head->value;
    delete this->head;
    this->tail = nullptr;
    this->head = nullptr;
    this->size = 0;
    return nValue;
  }
  LinkedListNode<T>* nHead = this->head->next;
  nValue = this->head->value;
  delete this->head;
  head = nHead;
  this->size--;
  return nValue;
}

template <typename T> T LinkedList<T>::removeLast() {

  T nValue;
  LinkedListNode<T>* currentNode;
  
  if(this->size == 0){
    throw runtime_error("Index does not exist in this LinkedList");
  }
  if(this->size == 1){
    nValue = this->tail->value;
    delete this->tail;
    this->tail = nullptr;
    this->head = nullptr;
    this->size = 0;
    return nValue;
  }
  else{
    currentNode = this->head;
    while(currentNode->next->next != nullptr){
      currentNode = currentNode->next;
    }
    nValue = this->tail->value;
    delete this->tail;
    currentNode->next = nullptr;
    this->tail = currentNode;
    this->size--;
    return nValue;
  }
  
}
