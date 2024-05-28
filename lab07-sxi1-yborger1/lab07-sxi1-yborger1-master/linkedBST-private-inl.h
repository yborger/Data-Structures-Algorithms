/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <utility>

#include "adts/list.h"
#include "adts/stlList.h"

using std::runtime_error;

template <typename K, typename V>
V LinkedBST<K, V>::findInSubtree(LinkedBSTNode<K, V>* current, K key) {
  if (current == nullptr) {
    throw runtime_error("Node does not exist!");
  }
  if (current->getKey() == key) {
    return current->getValue();
  }
  if (current->getKey() > key) {
    return findInSubtree(current->getLeft(), key);
  }
  return findInSubtree(current->getRight(), key);
}

template <typename K, typename V>
bool LinkedBST<K, V>::containsInSubtree(LinkedBSTNode<K, V>* current, K key) {
  if (current == nullptr) {
    return false;
  }
  else if (current->getKey() == key) {
    return true;
  }
  else if (current->getKey() > key ) {
    return containsInSubtree(current->getLeft(), key);
  }
  else {
    return containsInSubtree(current->getRight(), key);
  }
}

template <typename K, typename V>
void LinkedBST<K, V>::updateInSubtree(LinkedBSTNode<K, V>* current, K key,
                                      V value) {
  if (current == nullptr) {
    throw runtime_error("Node does not exist!");
  }
  if (current->getKey() == key) {
    current->setValue(value);
  }
  if (current->getKey() > key) {
    updateInSubtree(current->getLeft(), key, value);
  }
  if (current->getKey() < key) {
    updateInSubtree(current->getRight(), key, value);
  }
}

template <typename K, typename V>
int LinkedBST<K, V>::getHeightInSubtree(LinkedBSTNode<K, V>* current) {
    //logic: recursive call where you add in the result + 1
    //does this work out how we need it to
    if(current == nullptr){
      return -1; //the height of nothing is considered -1
    }
    int left = 1+getHeightInSubtree(current->getLeft());
    int right = 1+getHeightInSubtree(current->getRight());
    if(left > right){
      return left;
    }
    return right;
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMinInSubtree(LinkedBSTNode<K, V>* current) {
  if (current == nullptr) {
    throw runtime_error("Key has no value.");
  }
  else {
    if (current->getLeft() == nullptr) { //left is always min
      pair<K,V> minPair = pair<K,V> (current->getKey(), current->getValue());
      return minPair;
    }
    else {
      return getMinInSubtree(current->getLeft());
    }
  }
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMaxInSubtree(LinkedBSTNode<K, V>* current) {
  if (current == nullptr) {
    throw runtime_error("Key has no value.");
  }
  else {
    if (current->getRight() == nullptr) {
      pair<K,V> maxPair = pair<K,V> (current->getKey(), current->getValue());
      return maxPair;
    }
    else {
      return getMaxInSubtree(current->getRight());
    }
  }
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::insertInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
  if (current == nullptr) {
    LinkedBSTNode<K, V>* newNode = new LinkedBSTNode<K, V>(key, value);
    return newNode;
  }
  else if (current->getKey() == key){
    throw runtime_error("Key is duplicate.");
  }
  else if (key < current->getKey()) {
    //left
    current->setLeft(insertInSubtree(current->getLeft(), key, value));
    return current;
  }
  else {
    current->setRight(insertInSubtree(current->getRight(), key, value));
    return current;
  }
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::removeFromSubtree(LinkedBSTNode<K, V>* current, K key) {

  if (current == nullptr) {
    return nullptr;
  }
  else if (key < current->getKey()) {
    return removeFromSubtree(current->getLeft(), key);
  }
  else if (key > current->getKey()) {
    return removeFromSubtree(current->getRight(), key);
  }
  else {
    //we found it!
    //there are three cases to cover here:
    // 1) no children
    // 2) one child
    // 3) two children

    if(current->getLeft() == nullptr && current->getRight() == nullptr){
      //no children
      //can we just delete the node? - ninja said yes
      delete current; //since current is a pointer this deletes the node
      current = nullptr; //probably not necessary
      return nullptr;
    }
  //case: one child on RIGHT
    else if(current->getLeft() == nullptr){
      LinkedBSTNode<K, V>* temp = current->getRight();
      // temp = removeFromSubtree(this->get(holdPair.first, holdPair.second));
      delete current;
      return temp;
    }
    //case: one child on LEFT
    else if(current->getRight() == nullptr){
      LinkedBSTNode<K, V>* temp = current->getLeft();
      delete current;
      return temp;
    }

    //case: two children
    else {
      pair<K,V> holdBig = getMaxInSubtree(current->getLeft());
      current->setKey(holdBig.first);
      current->setValue(holdBig.second);
      current->setLeft(removeFromSubtree(current->getLeft(), holdBig.first));
      return current;
    }
  }
}

  template <typename K, typename V>
  void LinkedBST<K, V>::deleteSubtree(LinkedBSTNode<K, V>* current) {
      //delete everything current and down

  //case 1: no children
  if(current->getLeft() == nullptr && current->getRight() == nullptr){
    //no children
    delete current;
  }
  //case 2: 1 and 2 child
  else{
    if (current->getLeft() != nullptr){
      deleteSubtree(current->getLeft());
    }
    if (current->getRight() != nullptr){
      deleteSubtree(current->getRight());
    }
    delete current;
  }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPreOrderTraversal(LinkedBSTNode<K, V>* current,
                                             List<pair<K, V>>* list) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::buildPreOrder");
    //root then left subtree then right subtree
    //root implementation
  pair<K, V> temp(current->getKey(), current->getValue()); //new pair for root
  list->insertLast(temp);
  if(current->getLeft() != nullptr) {
    buildPreOrderTraversal(current->getLeft(), list);
  }
  if(current->getRight() != nullptr) {
    buildPreOrderTraversal(current->getRight(), list);
  }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildInOrderTraversal(LinkedBSTNode<K, V>* current,
                                            List<pair<K, V>>* list) {
    // throw runtime_error("Not yet implemented: LinkedBST<K,V>::buildInOrder");
    //left subtree, then root, then right subtree
  pair<K, V> temp(current->getKey(), current->getValue());

  if(current->getLeft() != nullptr) {
    buildInOrderTraversal(current->getLeft(), list);
  }

  list->insertLast(temp);

  if(current->getRight() != nullptr) {
    buildInOrderTraversal(current->getRight(), list);
  }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPostOrderTraversal(LinkedBSTNode<K, V>* current,
                                              List<pair<K, V>>* list) {
  // throw runtime_error("Not yet implemented: LinkedBST<K,V>::buildPostOrder");
  //left subtree, the right subtree, then root
  pair<K, V> temp(current->getKey(), current->getValue());

  if(current->getLeft() != nullptr) {
    buildPostOrderTraversal(current->getLeft(), list);
  }
  if(current->getRight() != nullptr) {
    buildPostOrderTraversal(current->getRight(), list);
  }
  list->insertLast(temp);
}

template <typename K, typename V>
int LinkedBST<K, V>::countNodes(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return 0;
    } else {
        return this->countNodes(current->getLeft()) +
               this->countNodes(current->getRight()) + 1;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::verifyKeysBoundedBy(LinkedBSTNode<K, V>* current,
                                          bool minApplies, K minBound,
                                          bool maxApplies, K maxBound) {
    if (minApplies && current->getKey() < minBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a "
                            "right descendent with lesser key");
    }
    if (maxApplies && current->getKey() > maxBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a left "
                            "descendent with greater key");
    }
    if (current->getLeft() != nullptr) {
        verifyKeysBoundedBy(current->getLeft(), minApplies, minBound, true,
                            current->getKey());
    }
    if (current->getRight() != nullptr) {
        verifyKeysBoundedBy(current->getRight(), true, current->getKey(),
                            maxApplies, maxBound);
    }
}
