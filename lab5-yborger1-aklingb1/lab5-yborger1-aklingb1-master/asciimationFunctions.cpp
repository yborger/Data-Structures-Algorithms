/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

List<pair<int, string>>* loadMovie(string filename) {

  ifstream file;
  file.open(filename);

  if(!file.is_open()){
    throw runtime_error("File " + filename + " could not be found");
  }

  LinkedList<pair<int,string>> *movie = new LinkedList<pair<int,string>>();

  string data, str;
  int frameCount;
  
  getline(file, data);

  while(!file.eof()){

    frameCount = stoi(data);
    for(int i = 0; i < 13; i++){
      getline(file, data);
      str += data + "\n";
    }
      
    //cout << frameCount << endl;
    //cout << str << endl;

    pair<int,string> p1 = pair<int,string>(frameCount,str);
    movie->insertLast(p1);
    str = "";

    getline(file, data);
    
  }

  return movie;
  
}

void playMovie(List<pair<int, string>>* list) {

  system("clear");
  
  for(int i = 0; i < list->getSize(); i++){
    cout << list->get(i).second;
    usleep(1000000*(list->get(i).first)/15);
    system("clear");
  }
 
}

List<pair<int, string>>* reverse(List<pair<int, string>>* list){

  List<pair<int,string>> *newList = new LinkedList<pair<int,string>>();
  for(int i = 0; i < list->getSize(); i++){
    newList->insertFirst(list->get(i));
  }

  return newList;
  
}
