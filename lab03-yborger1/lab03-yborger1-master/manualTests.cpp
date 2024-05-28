/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "grid.h"
#include "shape.h"
#include "point.h"
#include "horizontalLine.h"
#include "verticalLine.h"
#include "rectangle.h"
#include "picture.h"
#include <iostream>

using namespace std;

int main() {
    // You can put anything you like here.  This file exists so that
    // you can experiment with your code.  For instance, the following
    // might be a useful test after you've written your Point class.

    
    Shape *myShape1 = new Rectangle(0, 0, 7, 7, '$');
    Shape *myShape2 = new Rectangle(1, 1, 6, 4, '-');
    Shape *myShape3 = new Rectangle(3, 2, 4, 3, 'z');
    Picture myPicture;
    myPicture.addShape(myShape1);
    myPicture.addShape(myShape2);
    myPicture.addShape(myShape3);
    myPicture.print();
    

    return 0;
}
