/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "rectangle.h"


Rectangle::Rectangle(int x, int y, int width, int height, char symbol){
  this->x = x;
  this->y= y;
  this->width = width;
  this->height = height;
  this->symbol = symbol;
}

Rectangle::~Rectangle(){
  //waiting to create something new to delete it but I can't really delete if there's nothing new
  //so I'm unsure what to put in the body of this part
  //oh well
};

void Rectangle::draw(Grid *table){
  for(int i = 0; i < this->height; i++){
    for(int j = 0; j < this->width; j++){
      table->placeSymbol((this->x)+(j), (this->y)+(i), this->symbol);
    }
  }
};
