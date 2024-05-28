/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "adts/graph.h"
#include "adjacencyListGraph.h"
#include "graphAlgorithms.h"
#include "adjacencyListUndirectedGraph.h"
#include <iostream>
#include "stringUtils.h"
#include <stdexcept>
#include "adts/stack.h"
#include "adts/stlStack.h"
#include <vector>

using namespace std;

bool checkInput(string word, vector<string> buildings);

int userMenu();

string printVector(vector<string> vect);

int main() {
  Graph<string, string, int>* campusGraph = new AdjacencyListUndirectedGraph<string, string, int>();
  //vertex is type string
  string sci = "Sci";
  string singer = "Singer";
  string beardsley = "Beardsley";
  string trotter = "Trotter";
  string martin = "Martin";
  string kohlberg = "Kohlberg";
  string lpac = "LPAC";
  string parrish = "Parrish";
  campusGraph->insertVertex(sci);
  campusGraph->insertVertex(singer);
  campusGraph->insertVertex(beardsley);
  campusGraph->insertVertex(trotter);
  campusGraph->insertVertex(kohlberg);
  campusGraph->insertVertex(lpac);
  campusGraph->insertVertex(martin);
  campusGraph->insertVertex(parrish);

  campusGraph->insertEdge(sci, singer, "", 3);
  campusGraph->insertEdge(sci, beardsley, "", 4);
  campusGraph->insertEdge(sci, martin, "", 6);
  campusGraph->insertEdge(singer, beardsley, "", 2);
  campusGraph->insertEdge(singer, trotter, "", 5);
  campusGraph->insertEdge(martin, lpac, "", 3);
  campusGraph->insertEdge(kohlberg, lpac, "", 2);
  campusGraph->insertEdge(kohlberg, parrish, "", 4);
  campusGraph->insertEdge(kohlberg, beardsley, "", 2);
  campusGraph->insertEdge(kohlberg, trotter, "", 3);

  vector<string> buildings = campusGraph->getVertices();
  int userInput = -1;
  string start, end;
  cout << "Hello there!" << endl;
  while(userInput != 0){
    userInput = userMenu();

//input 1 below
    if(userInput == 1){
      do {
        cout << "\nEnter the first building: " << endl;
        cin >> start;
      } while(!checkInput(start, buildings));

      do {
        cout << "\nEnter the second building: " << endl;
        cin >> end;
      } while(!checkInput(end, buildings));
      if(reachableDFS(start, end, campusGraph)){
        cout << end << " is reachable from " << start << endl;
      }
      else{
        cout << end << " is not reachable from " << start << endl;
      }
    }

//input 2 below
    else if(userInput == 2){
    //  shortestLengthPathBFS(sci, kohlberg, campusGraph);
      do {
        cout << "\nEnter the first building: " << endl;
        cin >> start;
      } while(!checkInput(start, buildings));

      do {
        cout << "\nEnter the second building: " << endl;
        cin >> end;
      } while(!checkInput(end, buildings));
      cout << "The shortest length path is " << printVector(shortestLengthPathBFS(start, end, campusGraph)) << endl;

//input 3 below
    }
    else if(userInput == 3){
      cout << "You chose 3" << endl;
      do {
        cout << "\nEnter the building: " << endl;
        cin >> start;
      } while(!checkInput(start, buildings));
      Dictionary<string, int>* buildingsDict = singleSourceShortestPath(start, campusGraph);
      for(int i=0; i<buildings.size(); i ++) {
        cout << buildings[i] << ": " << buildingsDict->get(buildings[i]) << endl;
      }
      delete buildingsDict;
    }

    else if(userInput != 0){
      cout << "Not an option" << endl;
    }
  }
 delete campusGraph;
 //end of main
}

bool checkInput(string word, vector<string> buildings){
  for(int i = 0; i < buildings.size(); i++){
    if(word == buildings[i]){
      return true;
    }
  }
  cout << word << " is not a valid building code" << endl;
  cout << "The building codes are: Parrish Trotter Kohlberg Singer Beardsley LPAC Martin Sci" << endl;
  return false;
}

int userMenu(){
  int choice;
  cout << "\nLet's explore Swarthmore's north campus " << endl;
  cout << "1. Reachability from one building to another" << endl;
  cout << "2. Shortest length path from one building to another" << endl;
  cout << "3. Distances from one building to another" << endl;
  cout << "0. Quit" << endl;
  cout << "Choice: " << endl;
  cin >> choice;
  return choice;
}

string printVector(vector<string> vect){
  string add_on = "";
  for(int i = vect.size()-1; i >= 0; i--){
     add_on += vect[i] + " ";
  }
  return add_on;
}
