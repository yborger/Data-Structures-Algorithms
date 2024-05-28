/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "verticalLine.h"

//
VerticalLine::VerticalLine(int x, int y, int length, char symbol){
  this->x = x;
  this->y = y;
  this->length = length;
  this->symbol = symbol;
}

VerticalLine::~VerticalLine(){
  //destructor, when there is something NEW added then this needs to destroy it!
}

void VerticalLine::draw(Grid* table){
  for(int i = 0; i < this->length; i++){
    table->placeSymbol(this->x, ((this->y)+i), this->symbol);
  }
}
