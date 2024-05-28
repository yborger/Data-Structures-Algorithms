/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#include "quickSort.h"

using namespace std;

TEST(threeElements) {
  // Create a static array containing the numbers 4, 8, 6.
  int array[3] = {4, 8, 6};
  quickSort(array, 0, 2);
  CHECK_EQUAL(4, array[0]);
  CHECK_EQUAL(6, array[1]);
  CHECK_EQUAL(8, array[2]);
}

TEST(reverseSorted) {
  int size = 20;
  int *array = new int[size]; //dynamically allocated array
  for (int i = 0; i < size; i++) {
    array[i] = size - 1 - i;
  }
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; i++) {
    CHECK_EQUAL(i, array[i]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}



//sortSingle tests whether the quick sort can handle a single-element array (it should be able)
TEST(sortSingle) {
  //create a single-element array (allocated) 
  int* array = new int[1];
  array[0] = 168;

  qSort(array, 1);

  CHECK_EQUAL(168, array[0]);
  //de-allocate
  delete[] array;
}

//alreadySorted sends quick sort an array that is already in order to guarantee that it remains sorted afterwards
TEST(alreadySorted) {
  int* array = new int[50];
  for(int i = 0; i < 50; i++) {
    array[i] = i;
  }

  qSort(array, 50);

  for(int j = 0; j < 50; j++) {
    CHECK_EQUAL(j, array[j]);
  }
}

//sortingWithDuplicates checks if quick sort can handle sorting an array with repeated numbers
TEST(sortingWithDuplicates) {
  int* array = new int[50];
  for(int i = 0; i < 50; i++) {
    array[i] = i;
  }
  for(int i = 0; i < 50; i += 5) {
    array[i] = 39;
  }

  qSort(array, 50);

  int checkArray[] = {1,2,3,4,6,7,8,9,11,12,13,14,16,17,18,
                      19,21,22,23,24,26,27,28,29,31,32,33,34,
                      36,37,38,39,39,39,39,39,39,39,39,39,39,
                      39,41,42,43,44,46,47,48,49};
  
  for(int j = 0; j < 50; j++) {
    CHECK_EQUAL(checkArray[j], array[j]);
  
  }
}

//confusingMegaSort verifies if quick sort can sort a really big mixed array
TEST(confusingMegaSort) {
  int* array = new int[1000];
  for(int i = 0; i < 1000; i++) {
    if (i%2 == 0) {
      array[i] = i/2;
    } else {
      array[i] = 1000 - (i/2 + 1);
    }
  }

  qSort(array, 1000);

  for(int j = 0; j < 1000; j++) {
    CHECK_EQUAL(j, array[j]);

  }
}


/* no need to modify main */
int main() {
  return UnitTest::RunAllTests();
}
