/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

//Yael Borger Lab 1
//Due Date: September 8, 2021
#include <iostream>
#include <fstream>
using namespace std;

/* lastNum
 * a function that returns the last number in the array passed
 * @param total is the size of the array
 * @param arr[] is the array of integers being passed
 * @return the last integer in the array
 */
int  lastNum(int total, int arr[]);


/* largestNum
 * a function that compares all the integers in the array to
 *     determine the largest integer
 * @param total is the size of the array
 * @param arr[] is the array of integers being passed
 * @return the largest integer decided after going through the array
 */
int largestNum(int total, int arr[]);


/* lessThanTen
 * a function that compares each integer to the number 10 and 
 *     increases a counter variable that keeps track of how many
 *     integers are less than 10
 * @param total is the size of the array
 * @param arr[] is the array of integers being passed
 * @return the counter that kept track of the number of integers
 *     less than 10
 */
int lessThanTen(int total, int arr[]);


/* average
 * a function that determines the average of all of the numbers 
 *     in the array in float form (no integer division)
 * @param total is the size of the array
 * @param arr[] is the array of integers being passed
 * @return the average of the array of integers as a float
 */
float average(int total, int arr[]);

int main() {
  int i = 0;
  ifstream file_object;
  string file_name;
  cout << "Hello! What is the name of the file you would like to open? ";
  //greet the user
  cin >> file_name; //this is a string, it holds the name of the file exactly
  file_object.open(file_name);
  int total_nums;
  file_object >> total_nums;
  int arr[total_nums]; //make an array in the size that we actually want it
  for(i = 0; i < total_nums; i++){
     file_object >> arr[i];

  }
  cout << "The last number is " << lastNum(total_nums, arr) << "." << endl;
  cout << "The largest number is " << largestNum(total_nums, arr) << "." << endl;
  cout << "There are " << lessThanTen(total_nums, arr) << " numbers less than 10 in the sequence." << endl;
  cout << "The average is " << average(total_nums, arr) << "." << endl;

  return 0;
}

int lastNum(int total, int arr[]){
  return arr[total-1];
}

int largestNum(int total, int arr[]){
  int largest = 0;
  for(int i = 0; i < total; i++){
    if(largest < arr[i]){
       largest = arr[i];
     }
  }
  return largest;
}

int lessThanTen(int total, int arr[]){
  int counter = 0;
  for(int i = 0; i < total; i++){
    if(arr[total] < 10){
      counter++;
    }
  }
  return counter;
}

float average(int total, int arr[]){
  int temp = 0;
  float makeFloat;
  float avg;
  for(int i = 0; i < total; i++){
      temp+=arr[i];
  }
  makeFloat = total/1.0; //we want this to be a float so the average is not done in integer division
  avg = temp/makeFloat; //decimal math
  return avg;
}
