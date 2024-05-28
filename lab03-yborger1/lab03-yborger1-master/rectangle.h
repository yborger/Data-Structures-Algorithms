#pragma once

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"


class Rectangle:public Shape{
  private:
    int x, y, width, height;
    char symbol;
  public:
    Rectangle(int x, int y, int width, int height, char symbol);
    ~Rectangle();
    void draw(Grid *table);
};
