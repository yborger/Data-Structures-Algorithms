/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main() {

  LinkedList<int> *intList = new LinkedList<int>();
  cout << intList->isEmpty() << endl;
  intList->insertFirst(5);
  intList->insertLast(7);
  intList->insertFirst(3);
  cout << intList->getFirst() << endl;
  cout << intList->getLast() << endl;
  cout << intList->isEmpty() << endl;
  cout << intList->removeFirst() << endl;
  cout << intList->removeLast() << endl;
  cout << intList->removeFirst() << endl;
  cout << intList->getSize() << endl;
  cout << intList->isEmpty() << endl;
  delete intList;

  /* Should output:
     
     1
     3
     7
     0
     3
     7
     5
     0
     1
     
  */

  cout << endl;

  
  List<pair<int, string>> *list = loadMovie("test_data/smiley.asciimation");
  playMovie(list);

  return 0;
}
