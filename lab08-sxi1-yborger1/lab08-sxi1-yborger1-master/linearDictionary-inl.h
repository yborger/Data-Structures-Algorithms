/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
using std::pair;
using std::runtime_error;
using std::vector;
#include "hashFunctions.h"


template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return this->vector1.size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    return this->vector1.size() == 0;
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
  pair<K,V> pair1 = pair<K,V> (key, value);
  // int index = hash(key, this->vector1.capacity());
  for(int i = 0; i < this->vector1.size(); i++) {
    if(key == this->vector1[i].first){
      throw runtime_error("Key already exists.");
    }
    // index = index % this->vector1.capacity();
  }
  this->vector1.push_back(pair1);
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
  bool updated = false;
  for(int i =0; i < this->vector1.size(); i++) {
    if(key == this->vector1[i].first){
      this->vector1[i].second = value;
      updated = true;
    }
  }
  if(!updated){
    throw runtime_error("Key does not exist.");
  }
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
  // int index = hash(key, this->vector1.size());
  for(int i =0; i < this->vector1.size(); i++) {
    if(key == this->vector1[i].first){
      return this->vector1[i].second;
    }
  }
  throw runtime_error("Key does not exist.");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
  for(int i =0; i < this->vector1.size(); i++) {
    if(key == this->vector1[i].first){
      return true;
    }
  }
  return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
  bool removed = false;
  for(int i =0; i < this->vector1.size(); i++) {
    if(key == this->vector1[i].first){
      removeFromVector(this->vector1, i);
      removed = true;
    }
  }
  if(!removed){
    throw runtime_error("Key does not exist.");
  }
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
  vector<K> newVector;
  for(int i =0; i < this->vector1.size(); i++) {
    newVector.push_back(this->vector1[i].first);
  }
  return newVector;
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
  vector<pair<K,V>> newVector;
  for(int i =0; i < this->vector1.size(); i++) {
    newVector.push_back(this->vector1[i]);
  }
  return newVector;
}

template <typename T> void removeFromVector(vector<T> &list, int index){
  if(index < 0 || index >= list.size()){
    throw runtime_error("index out of range in removeFromVector");
  }
  list.erase(list.begin()+index, list.begin()+index+1);
}

// TODO: put any other definitions here
