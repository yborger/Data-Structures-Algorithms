/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>

#include "picture.h"
using namespace std;

Picture::Picture() {
  this->numberOfShapes=0;
  this->shapes = new Shape*[50];
  //throw runtime_error("Not yet implemented: Picture::Picture");
}

Picture::~Picture() {
  delete[] shapes; //do I need to put the asterisks or not
}

string Picture::toString() {
  //make this still  
  Grid* temp = new Grid;
  //for -- go through each shape in shapes and draw it then convert to string
  for(int i = 0; i < this->numberOfShapes; i++){
    this->shapes[i]->draw(temp); //this is either exactly what I want, or not even close
  }
  string str = "";
  str = temp->toString(); //now it is a string!
  delete temp; //delete the grid!
  return str;
  //throw runtime_error("Not yet implemented: Picture::print");
}

void Picture::print() {
    cout << this->toString() << endl;
}

void Picture::addShape(Shape* shape) {
    this->shapes[this->numberOfShapes] = shape;
    this->numberOfShapes+=1; //since there is no counter incrementing anywhere else
    //throw runtime_error("Not yet implemented: Picture::addShape");
}
