/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

#include <UnitTest++/UnitTest++.h>

#include "adts/list.h"
#include "maze.h"
#include "mazeUtils.h"

using namespace std;

#include <cmath>
#include <sstream>

// TODO: put #includes here

using namespace std;

int main() {
  Maze* maze = loadMap("test_data/impossible3.map");
  List<Position*>* path = maze->solveDepthFirst();


  string answer;
  answer = renderAnswer(maze, path);
  cout << answer << endl;
  delete maze;
  return 0;
}
