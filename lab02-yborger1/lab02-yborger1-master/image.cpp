/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
    // TODO: implement this function correctly
  int indexNum = (3*width*y) + 3*x;
   //3*width gives us indices of width since it is in pixels, then you can math properly
  return indexNum; // dummy value so that the code compiles at first
}

void noRed(int width, int height, int* ppm) {
    // TODO: this image transformation
  //so we want to get each individual r part of the pixel to change value ONLY
  //how: go through the whole thing in a for loop
  //width * height would give area overall, *3 because 3 indices per pixel
  int highest_index = pixelToIndex(width, 0, height); //this is 1 over the last possible so for-loop is nice
  for(int i = 0; i < highest_index; i++){
    if(i % 3 == 0){
      ppm[i] = 0; //set the r index to 0 to remove red
    }
  }
  //no return statement
}

// TODO: write your other image transformation functions here

/* Remember that the two flips are significantly harder than the
   other transofmations. We recommend that you work out the math
   on paper before attempting to write the code.
*/

void noGreen(int width, int height, int* ppm){
  int highest_index = pixelToIndex(width, 0, height);
    for(int i = 0; i < highest_index; i++){
      if(i % 3 == 1){
        ppm[i] = 0; //set the g index to 0 to remove red
      }
    }
}

void noBlue(int width, int height, int* ppm){
  int highest_index = pixelToIndex(width, 0, height);
  for(int i = 0; i < highest_index; i++){
    if(i % 3 == 2){
      ppm[i] = 0; //set the b index to 0 to remove red
    }
  }

}

void invert(int width, int height, int* ppm){
  int  highest_index = pixelToIndex(width, 0, height);
  for(int i = 0; i < highest_index; i++){
    ppm[i] = 255 - ppm[i];
  }
}

void grayscale(int width, int height, int* ppm){
  int avg = 0;
  int highest_index = pixelToIndex(width, 0, height);
  for(int i = 0; i < highest_index; i+=3){ //by going through indices by 3, we can make sure not to repeat rgb indices
    avg = (ppm[i]+ppm[i+1]+ppm[i+2])/3;
    ppm[i] = avg;
    ppm[i+1] = avg;
    ppm[i+2] = avg;
  }
}

void flipHorizontally(int width, int height, int* ppm){
  //mirror sideways
  int row, col;
  int red;
  int temp[3];
  int width_ind;
  for(row = 0; row < height; row++){
    for(col = 0; col < (width/2); col++){
      red = pixelToIndex(width, col, row);
      temp[0] = ppm[red];
      temp[1] = ppm[red+1];
      temp[2] = ppm[red+2];
      width_ind = pixelToIndex(width, (width-col), row); //the edge on opposite side
      ppm[red] = ppm[width_ind-3];
      ppm[red+1] = ppm[width_ind-2]; //green
      ppm[red+2] = ppm[width_ind-1]; //blue
      ppm[width_ind-1] = temp[2];
      ppm[width_ind-2] = temp[1];
      ppm[width_ind-3] = temp[0];
    }
  }

}

void flipVertically(int width, int height, int* ppm){
  //upside down
  int row, col;
  int red; //yes, I am using red to keep track of which index I start at
  int temp[3];
  int height_ind;
  for(row = 0; row < (height/2); row++){
    for(col = 0; col < width; col++){
      red = pixelToIndex(width, col, row);
      temp[0] = ppm[red];
      temp[1] = ppm[red+1];
      temp[2] = ppm[red+2];
      height_ind = pixelToIndex(width, col, (height-1-row));
      ppm[red] = ppm[height_ind];
      ppm[red+1] = ppm[height_ind+1];
      ppm[red+2] = ppm[height_ind+2]; //blue
      ppm[height_ind+2] = temp[2];
      ppm[height_ind+1] = temp[1];
      ppm[height_ind] = temp[0];
    }
  }
}
