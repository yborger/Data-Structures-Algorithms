#pragma once

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"



class Point:public Shape{
  private:
    int x, y;
    char symbol;
    //these will end up having keyword this probably
  public:
    Point(int x, int y, char symbol); //constructor
    ~Point(); //destructor?
    void draw(Grid *table); //called the grid-type "table" so I remember 
    
  
}; //don't forget semicolon!!
