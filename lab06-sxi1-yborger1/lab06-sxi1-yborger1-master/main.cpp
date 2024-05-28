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

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main(int argc, char** argv) {
  Maze* maze;
  List<Position*>* path;
  string str;
  if (argc != 3) {
    cout << "Wrong number of arguments." << endl;
    return 1;
  }

  string search_type = argv[2];

  if (search_type != "breadth" && search_type != "depth"){
    cout << "Invalid argument." << endl;
    return 1;
  }
  if (search_type == "breadth") {
    string file_name = argv[1];
    maze = loadMap(file_name);
    path = maze->solveBreadthFirst();
  }
  if (search_type == "depth") {
    string file_name = argv[1];
    maze = loadMap(file_name);
    path = maze->solveDepthFirst();
  }
  str = renderAnswer(maze, path);
  cout << str << endl;

  delete path;
  delete maze;
  return 0;
}
