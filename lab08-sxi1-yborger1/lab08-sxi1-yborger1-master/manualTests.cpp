/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <algorithm>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

#include <UnitTest++/UnitTest++.h>

#include "adts/dictionary.h"
#include "hashFunctions.h"
#include "hashTable.h"

using namespace std;

int main(int argc, char** argv) {
  // You can use this main to experiment with the code you have written
  Dictionary<int, string>* example = new HashTable<int, string>;
  vector<pair<int, string>> newVector;
  example->insert(2, "hi");
  example->insert(3, "hello");
  example->insert(0, "zeroeth");
  example->insert(1, "zero pt 2");
  //example->insert(4, "expand should start now");


  cout<< example->get(0) << endl; //should print hi
  cout << example->get(3) << endl; //should print hello
  example->update(3, "ayo");

  newVector = example->getItems();
  for(int i = 0; i < newVector.size(); i++){
    if(example->contains(newVector[i].first)){
      cout << "Listing Vector: " << newVector[i].first << " " << newVector[i].second << endl;
    }
  }
  cout << example->get(0) << endl;
  example->remove(2);
  cout << example->contains(2) << endl; //should print 0
  delete example;
  return 0;
}
