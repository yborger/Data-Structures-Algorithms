/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

/*
  Kenneth Barkdoll and Yael Borger
  CS35 - F21 : September 24th
  
  This is an implementation of the quick sort algorithm, using partition as a 
  function to assist in the process
*/

#include "quickSort.h"
#include <iostream>

using namespace std;


int partition(int* array, int left, int right);

void quickSort(int *array, int startIndex, int endIndex) {
  /* quickSort
   * a function that runs recursively to quickly split and then sort the array passed
   * @param array is a pointer to the array we intend to sort
   * @param startIndex is an integer that refers to the index of where we start for the sorting of the array
   * @param endIndex is an integer that refers to the index of where we end for the sorting of the array
   * @return is void
   */
  int pivot;
  if (startIndex < endIndex) {
    pivot = partition(array, startIndex, endIndex);
    quickSort(array, startIndex, pivot-1);
    quickSort(array, pivot+1, endIndex);
  }
}

int partition(int* array, int left, int right) {
  /* partition
   * a function that takes the left and right as indices for the range to focus on in the array given
   * and sorts the values according to whether they are greater than or less than the pivot value chosen
   * @param array is a pointer to the array we intend to sort
   * @param left is the integer for the index, referring to the starting point for the portion we are sorting
   * @param right is the integer for the index, referring to the ending point for the portion of the array we are sorting
   * @return the integer that has the index of the pivot point after the last swap
   */
  int swap; //this is a temporary variable that will be used for swapping
  int pivot; //the number that we will compare to in order to sort
  
  pivot = array[right]; //pivot is the last element in the array
  int l = left; //maintain uniformity
  //we made an r to be the right side (not including pivot), so l is left side (index)
  int r = right - 1;
  while (l <= r) {
    if (array[l] <= pivot) {//if  integer at array[l] is less than pivot, we leave it on the left
      l++;
    } else if (array[r] >= pivot) {//if integer at array[r] is greater than pivot, we leave it on the right
      r -= 1;
    } else { //integer does not fit those requirements, swap them
      swap = array[l];
      array[l] = array[r];
      array[r] = swap;
    }
  }
  //this last swap is to put the pivot right in between the values it is greater than (l) and less than (r)
  swap = array[l];
  array[l] = array[right];
  array[right] = swap;
  return l; //returning the future pivot index
  
}


// qSort is a wrapper around the main quickSort function.
void qSort(int *array, int size) {
  quickSort(array, 0, size - 1);
}
