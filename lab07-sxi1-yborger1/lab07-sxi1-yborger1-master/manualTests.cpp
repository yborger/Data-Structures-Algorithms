/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include <UnitTest++/UnitTest++.h>

#include "adts/BST.h"
#include "adts/list.h"
#include "linkedBST.h"
#include "linkedBSTNode.h"

using namespace std;
int main() {
    // TODO: write any tests you want here; this is your sandbox
    LinkedBST<int, string>* bst = new LinkedBST<int, string>();

    cout << bst->isEmpty() << endl; //should print 1
    bst->insert(6, "6");
    bst->insert(2, "2");
    bst->insert(7, "7");
    bst->insert(1, "1");
    bst->insert(4, "4");
    bst->insert(9, "hello");
    bst->insert(3, "3");
    cout << bst->getSize() << endl;

    bst->checkInvariants();
    // cout << bst << endl;

    bst->update(6, "42");
    cout << bst->get(9) << endl;

    cout << bst->getHeight() << endl; //height starts at 0, this should print 3

    cout << bst->getMaxKey() << endl; //print 9
    cout << bst->getMinKey() << endl; //print 1

    cout << bst->contains(2) << endl; //print 1
    bst->remove(2); //remove!!!
    cout << "DA SIZE " << bst->getSize() << endl;

    cout << bst->contains(2) << endl; //print 0
    cout << bst->isEmpty() << endl; //should print 0
    cout << "DA SIZE " << bst->getSize() << endl;
    bst->checkInvariants();

    // vector<pair<int, string>> vectorMain = bst->traverseLevelOrder(); //ask ninjas how to print out list
    vector<pair<int, string>> vectorMain = bst->getItems(); //ask ninjas how to print out list
    cout << vectorMain.size() << endl;
    for(int i=0; i<vectorMain.size(); i++) {
      cout << vectorMain[i].first << "  " << vectorMain[i].second << endl;
    }
    // vector<int> vectorMain = bst->getKeys();
    // for(int i=0; i<vectorMain.size(); i++) {
    //   cout << vectorMain[i] << endl;
    // }
    delete bst;
    return 0;
}
