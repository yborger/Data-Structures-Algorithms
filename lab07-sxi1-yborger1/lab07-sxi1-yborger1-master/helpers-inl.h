/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "helpers.h"
using namespace std;

template <typename T> vector<T> dynamicListToStaticVector(List<T>* list) {
  vector<T> vector1;
  int size = list->getSize();
  for(int i=0; i<size; i++) {
    vector1.push_back(list->get(i));
    // vector1[i].first = (list->get(i).first);
    // vector1[i].second = (list->get(i).second);
  }
  delete list;
  return vector1;
}
