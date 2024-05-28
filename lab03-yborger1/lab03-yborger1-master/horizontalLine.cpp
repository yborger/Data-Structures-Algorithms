/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "horizontalLine.h"

HorizontalLine::HorizontalLine(int x, int y, int length, char symbol){
  this->x = x;
  this->y = y;
  this->length = length;
  this->symbol = symbol;
}

HorizontalLine::~HorizontalLine(){
  //destroy! nothing new, so what do I destroy?
}

void HorizontalLine::draw(Grid *table){
  for(int i = 0; i < this->length; i++){
    table->placeSymbol(((this->x)+i), this->y, this->symbol); //sorry for the parenthesis!
    //parenthesis are basically making sure that this->x is used, that i is added to the
    //number that this->x is, and the parenthesis around that is to make sure that number
    //is only for the x position and does not interfere with the y position
  }
}
