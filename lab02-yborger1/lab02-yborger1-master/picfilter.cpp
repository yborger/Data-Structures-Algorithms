/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {

    // TODO: write your main program here
    // Remember:
    //   * The first command-line argument in argv is always the name of the
    //     program.
    //   * You can convert from char* to string just by assignment:
    //         string infile = argv[1];
    //   * You should have code that deals with the case that your
    //     user gave you too few or too many command-line arguments.
    // Good luck!  Remember to ask for help!
  if(argc != 4){
    cout << "Try running this program again with correct number of arguments, thank you.";
      return 1; //if there are too few or too many arguments
    
  }
  string progName = argv[0];
  string ogFileName = argv[1];
  string transformation = argv[2];
  string newFileName = argv[3];
  //  cout << "the info repeated back: " << progName << ogFileName << transformation << newFileName << endl;
   int width = ppm_width(ogFileName);
   int height = ppm_height(ogFileName);
   int* readFile = read_ppm(ogFileName);
//implement some code to actually do the transformation

  if(transformation == "noRed"){
    //cout<< "no red";
    noRed(width, height, readFile);
  }
  else if(transformation == "noGreen"){
    noGreen(width, height, readFile);
  }
  else if(transformation == "noBlue"){
    noBlue(width, height, readFile);
  }
  else if(transformation == "invert"){
    invert(width, height, readFile);
  }
  else if(transformation == "grayscale"){
    grayscale(width, height, readFile);
  }
  else if(transformation == "flipHorizontally"){
    flipHorizontally(width, height, readFile);
  }
  else if(transformation == "flipVertically"){
    flipVertically(width, height, readFile);
  }
  else{
    cout << "That transformation is not within our realm of possibility, sorry! " << endl;
    return 1; //1 is my "does not exist" number
  }

  write_ppm(newFileName, width, height, readFile);
  return 0;
}

