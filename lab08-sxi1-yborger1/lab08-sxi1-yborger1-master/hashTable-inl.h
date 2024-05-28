/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <iostream>
#include "hashFunctions.h"
using std::pair;
using std::runtime_error;
using std::vector;


template <typename K, typename V> HashTable<K, V>::HashTable() {
      //data members:
    //size, capacity, maxLoadFactor, and dynamic array of lineartable
    this->size = 0;
    this->capacity = 5;
    this->maxLoad = 0.75;
    this->table = new LinearDictionary<K,V>[this->capacity];
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
  this->size = 0;
  this->capacity = 5;
  this->maxLoad = maxLoadFactor;
  this->table = new LinearDictionary<K,V>();
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    delete[] this->table;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
  return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    return this->size == 0;
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
  int index = hash(key, this->capacity);
  this->table[index].insert(key, value);
  this->size++;
  float load = float(this->size)/this->capacity;
  if(load > maxLoad){
    expandCapacity();
  }
}

template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
  int index = hash(key, this->capacity);
  this->table[index].update(key,value);
}

template <typename K, typename V> V HashTable<K, V>::get(K key) {
  int index = hash(key, this->capacity);
  return this->table[index].get(key);
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
  int index = hash(key, this->capacity);
  return this->table[index].contains(key);
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
  int index = hash(key, this->capacity);
  this->table[index].remove(key);
  this->size--;
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
  vector<K> result;
  vector<K> current;
  for(int i = 0; i < this->capacity; i++) {
    current = this->table[i].getKeys();
    result.insert(result.end(), current.begin(), current.end());
  }
  return result;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
  vector<pair<K,V>> result;
  vector<pair<K,V>> current;
  for(int i = 0; i < this->capacity; i++) {
    current = this->table[i].getItems();
    for(int j = 0; j < current.size(); j++){
        result.push_back(current[j]);
    }
  }
  return result;
}

template <typename K, typename V> void HashTable<K, V>::expandCapacity() {
  int index;
  vector<pair<K, V>> vector1 = this->getItems();
//  std::cout << vector1.size() << std::endl;
  this->capacity *= 2;
  LinearDictionary<K,V>* temp = new LinearDictionary<K,V>[this->capacity];
  for(int i = 0; i < vector1.size(); i++){ //each key is found
    index = hash(vector1[i].first, this->capacity); //hash each key
    temp[index].insert(vector1[i].first, vector1[i].second); //grab from vector
  }
  delete[] this->table;
  this->table = temp;
}

// TODO: put any other definitions here
