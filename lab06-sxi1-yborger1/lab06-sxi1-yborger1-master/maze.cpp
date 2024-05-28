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
/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"

#include "maze.h"

using namespace std;

Maze::Maze(int width, int height) {
  this->height = height;
  this->width = width;
  if (height == 0 || width == 0) {
    throw runtime_error("Position does not exist.");
  }
  this->positions = new Position**[width]; //width is x, height is y
  for(int i = 0; i < width; i++){
    this->positions[i] = new Position*[height];
    for (int j= 0; j < height; j++) {
      this->positions[i][j] = new Position(i, j);
    }
  }
}

Maze::~Maze() {
  for(int i = 0; i < this->width; i++){
    for(int j = 0; j < this->height; j++){
      delete this->positions[i][j];
    }
    delete[] this->positions[i];
    //CHECK ON VALGRIND FOR MEMORY LEAKS
  }
  delete[] this->positions;
}

int Maze::getWidth() {
  return this->width;
}

int Maze::getHeight() {
  return this->height;
}

bool Maze::isWall(int x, int y) {
  if(x < 0 || x >= this->width || y < 0 || y >= this->height){
    throw runtime_error("Position is out of bounds.");
  }
  return this->positions[x][y]->isWall();
}

void Maze::setWall(int x, int y) {
  if(x < 0 || x >= this->width || y < 0 || y >= this->height){
    throw runtime_error("Position is out of bounds.");
  }
  this->positions[x][y]->setWall();
}

List<Position*>* Maze::getNeighbors(Position* position) {
  //we are choosing to return all of the viable neighbors
  int row = position->getY();
  int column = position->getX();
  STLList<Position*>* neighbors = new STLList<Position*>();

  if (!(column-1 < 0) && !(isWall(column-1,row)) && !(positions[column-1][row]->isVisited())) { // checks WEST
    neighbors->insertLast(this->positions[column-1][row]);

    //add the position to neighbors
  }
  if (!(row+1 >= this->height) && !(isWall(column,row+1)) && !(positions[column][row+1]->isVisited())) { // checks SOUTH
    neighbors->insertLast(this->positions[column][row+1]);
  }
  if (!(column+1 >= this->width) && !(isWall(column+1,row)) && !(positions[column+1][row]->isVisited())) { // checks EAST

    neighbors->insertLast(this->positions[column+1][row]);
    //add the position to neighbors
  }
  if (!(row-1 < 0) && !(isWall(column,row-1))  && !(positions[column][row-1]->isVisited())) { // checks NORTH
    neighbors->insertLast(this->positions[column][row-1]);
  }

  return neighbors;
}

List<Position*>* Maze::solveBreadthFirst() {
  LinkedQueue<Position*>* queue = new LinkedQueue<Position*>();
  return solve(queue);
}

List<Position*>* Maze::solveDepthFirst() {
  LinkedStack<Position*>* stack = new LinkedStack<Position*>();
  return solve(stack);
}

List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
  Position* start = positions[0][0];// grabbing a position that exists and pointing to it
  start->setPrevious(nullptr);
  exploration->insert(start);
  Position* end = positions[this->width-1][this->height-1];
  start->isVisited();
  Position* current;

  while (!exploration->isEmpty()) {
    current = exploration->remove();
    if (current == end) {
      break;
    }
    else {
      List<Position*>* neighbors = this->getNeighbors(current);
      for (int i = 0; i < neighbors->getSize(); i++) {
        if (!neighbors->get(i)->isVisited()) {
          neighbors->get(i)->setVisited();
          neighbors->get(i)->setPrevious(current);
          exploration->insert(neighbors->get(i));
        }
      }
      delete neighbors; //delete the new neighbors made each time getNeighbors runs
    }
  }
  delete exploration;
  if (current != end) {
    return nullptr;
  }
  STLList<Position*>* list = new STLList<Position*>();
  while (current != start){
    list->insertFirst(current);
    current = current->getPrevious();
  }
  list->insertFirst(current);
  return list;
}
