/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <utility>
#include <vector>

#include "adts/list.h"
#include "adts/queue.h"
#include "adts/stlList.h"
#include "adts/stlQueue.h"

#include "linkedBSTNode.h"
#include "helpers.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> LinkedBST<K, V>::LinkedBST() {
  V value;
  K key;
  this->size = 0;
  this->root = nullptr;
}

template <typename K, typename V> LinkedBST<K, V>::~LinkedBST() {
  // To do: implement the destructor
  // Use the helper deleteSubtree
  if(this->root != nullptr){
    deleteSubtree(this->root);
  }
}

template <typename K, typename V> int LinkedBST<K, V>::getSize() {
  return this->size;
}

template <typename K, typename V> bool LinkedBST<K, V>::isEmpty() {
  return (countNodes(this->root) == 0);
}

template <typename K, typename V> void LinkedBST<K, V>::insert(K key, V value) {
  // Use the helper insertInSubtree
  this->root = insertInSubtree(this->root, key, value);
  this->size++;
}

template <typename K, typename V> void LinkedBST<K, V>::update(K key, V value) {
  // Use the helper updateInSubtree
  updateInSubtree(this->root, key, value);
}

template <typename K, typename V> V LinkedBST<K, V>::get(K key) {
  // Use the helper findInSubtree
  return this->findInSubtree(this->root, key);
}

template <typename K, typename V> bool LinkedBST<K, V>::contains(K key) {
  // Use the helper containsInSubtree
  return containsInSubtree(this->root, key);
}

template <typename K, typename V> void LinkedBST<K, V>::remove(K key) {
  // Use the helper removeFromSubtree
  removeFromSubtree(this->root, key);
  this->size--;
}

template <typename K, typename V> vector<K> LinkedBST<K, V>::getKeys() {
  // Use one of the traversals
  vector<pair<K, V>> pairedVector = traverseInOrder();
  vector<K> justKeys;
  for(int i = 0; i < pairedVector.size(); i++){
    justKeys.push_back(pairedVector[i].first);
  }
  return justKeys;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::getItems() {
  // Use one of the traversals
  return traverseInOrder();
}

template <typename K, typename V> int LinkedBST<K, V>::getHeight() {
  // Use the helper getHeightInSubtree
  return getHeightInSubtree(this->root);
}

template <typename K, typename V> K LinkedBST<K, V>::getMaxKey() {
  // Use the helper getMaxInSubtree
  return getMaxInSubtree(this->root).first;
}

template <typename K, typename V> K LinkedBST<K, V>::getMinKey() {
  // Use the helper getMinInSubtree
  return getMinInSubtree(this->root).first;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePreOrder() {
  // Use the helper buildPreOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K, V>>* newList = new STLList<pair<K, V>> ();
  buildPreOrderTraversal(this->root, newList);
  vector<pair<K,V>> newVector = dynamicListToStaticVector(newList);
  return newVector;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseInOrder() {
  // Use the helper buildInOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K, V>>* newList = new STLList<pair<K, V>> ();
  buildInOrderTraversal(this->root, newList);
  vector<pair<K,V>> newVector = dynamicListToStaticVector(newList);
  return newVector;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePostOrder() {
  // Use the helper buildPostOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K, V>>* newList = new STLList<pair<K, V>> ();
  buildPostOrderTraversal(this->root, newList);
  vector<pair<K,V>> newVector = dynamicListToStaticVector(newList);
  return newVector;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseLevelOrder() {
  // Do a breadth-first search (no need to mark visited or generate path)

  Queue<LinkedBSTNode<K, V>*>* newQueue = new STLQueue<LinkedBSTNode<K, V>*>; //Queue that holds BSTNodes
  vector<pair<K, V>> vector1;
  LinkedBSTNode<K, V>* current;
  newQueue->enqueue(this->root);

  while(!newQueue->isEmpty()) {
    current = newQueue->dequeue();
    if (current->getLeft() != nullptr) {
      newQueue->enqueue(current->getLeft());
    }
    if (current->getRight() != nullptr) {
      newQueue->enqueue(current->getRight());
    }
    pair<K,V> newPair = pair<K,V> (current->getKey(), current->getValue());
    vector1.push_back(newPair);
  }
  delete newQueue;
  return vector1;
}

template <typename K, typename V> void LinkedBST<K, V>::checkInvariants() {
    if (this->countNodes(this->root) != this->size) {
        throw runtime_error(
            "Problem in BST: Node count doesn't match tree size");
    }
    if (this->root != nullptr) {
        // The bounds provided here are arbitrary because the false
        // arguments indicate that they do not apply.  But we need a
        // value of type K to fill this parameter since we don't have
        // globally min/max K values generically.
        this->verifyKeysBoundedBy(this->root, false, this->root->getKey(),
                                  false, this->root->getKey());
    }
}
