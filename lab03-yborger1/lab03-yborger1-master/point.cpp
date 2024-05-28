/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "point.h"



Point::Point(int x, int y, char symbol){ //constructor
  this->x = x;
  this->y = y;
  this->symbol = symbol;
}

Point::~Point(){ //destructor
  //no new memory allocated in this portion, nothing needs to be specifically deleted with delete[]
}

void Point::draw(Grid *table){
  table->placeSymbol(this->x, this->y, this->symbol);  
}


