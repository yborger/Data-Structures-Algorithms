/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char** argv) {

  if(argc == 2){

    string filename = argv[1];
    List<pair<int, string>> *movie = loadMovie(filename);
    playMovie(movie);
    
    delete(movie);
    
  }
  
  else if (argc == 3){
    string str = argv[1];
    if(str.compare("--reverse") == 0){
      
      string filename = argv[2];
      List<pair<int, string>> *movie = loadMovie(filename);
      List<pair<int, string>> *reverseMovie = reverse(movie);
      playMovie(reverseMovie);
      
      delete(reverseMovie);
      
      delete(movie);
    
    }
    else{
      throw runtime_error("Invalid parameters. Implementation: ./asciimation --reverse filename");
    }
  }
  
  else{
    throw runtime_error("Invalid parameters. Implementation: ./asciimation filename or  ./asciimation --reverse filename");
  }

    return 0;
    
}
