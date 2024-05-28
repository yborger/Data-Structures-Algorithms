 /*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include "adts/stack.h"
#include "adts/stlStack.h"
#include "adts/queue.h"
#include "adts/stlQueue.h"
#include "adjacencyListGraph.h"
#include "adjacencyListUndirectedGraph.h"
#include <vector>
#include "stringUtils.h"
#include "adts/priorityQueue.h"
#include "adts/stlMinPriorityQueue.h"


using namespace std;

template <typename V, typename E, typename W>
bool reachableDFS(V src, V dest, Graph<V, E, W>* g) {
    Dictionary<V, bool>* visited = new STLHashTable<V, bool>();
    Stack<V>* stack = new STLStack<V>;
    stack->push(src);
    visited->insert(src, true);
    V temp;
    vector<V> neighbors_vector;
    while(!stack->isEmpty()){
      temp = stack->pop();
      //getneighbors with temp as the parameter of it
      if(temp == dest) {
        delete stack;
        delete visited;
        return true;
      }
      neighbors_vector = g->getNeighbors(temp);
      for(int i=0; i<neighbors_vector.size(); i++) {
        if (!visited->contains(neighbors_vector[i])){ //if the element is NOT visited
          stack->push(neighbors_vector[i]);
          visited->insert(neighbors_vector[i], true); //we only add the element if it wasn't in there originally
        }
      }
    }
    delete stack;
    delete visited;
    return false;
}

template <typename V, typename E, typename W>
vector<V> shortestLengthPathBFS(V src, V dest, Graph<V, E, W>* g) {
    Dictionary<V, V>* previous = new STLHashTable<V,V>(); //the key is the current and the value is the getPrevious of current
    Queue<V>* queue = new STLQueue<V>();
    V temp;
    vector<V> path;
    vector<V> neighbors_vector;
    queue->enqueue(src);
    previous->insert(src, src);
    while(!queue->isEmpty()){
        temp = queue->dequeue();
        if(temp == dest){
          path.push_back(dest);
          while(temp != src){
            temp = previous->get(temp);
            path.push_back(temp);
          }
          delete previous;
          delete queue;
          return path;
        }
        neighbors_vector = g->getNeighbors(temp);
        for(int i=0; i<neighbors_vector.size(); i++) {
          if (!previous->contains(neighbors_vector[i])){ //if the element is NOT visited
            queue->enqueue(neighbors_vector[i]);
            previous->insert(neighbors_vector[i], temp);
          }
        }
      }
      delete previous;
      delete queue;
      return path;
}

template <typename V, typename E, typename W>
Dictionary<V, W>* singleSourceShortestPath(V src, Graph<V, E, W>* g) {
    Dictionary<V, W>* cost = new STLHashTable<V, W>();
    PriorityQueue<W, V>* pq = new STLMinPriorityQueue<W, V>();
    cost->insert(src, 0);
    pq->insert(0,src);
    W currPriority, currCost, newCost;
    V currVertex, next;
    vector<Edge<V, E, W>> outgoingEdges;
    while(!pq->isEmpty()){
      currPriority = pq->peekPriority();
      currVertex = pq->remove();
      currCost = cost->get(currVertex);
      outgoingEdges = g->getOutgoingEdges(currVertex);
      if(currCost == currPriority){
        for(int i = 0; i < outgoingEdges.size(); i++){
          next = outgoingEdges[i].getDestination();
          newCost = currCost + outgoingEdges[i].getWeight();
          if(!cost->contains(next)){
            cost->insert(next, newCost);
            pq->insert(newCost, next);
          }
          else if(newCost < cost->get(next)){
            //lower cost! woo!!
            cost->update(next, newCost);
            pq->insert(newCost, next);
          }
        }
      }
    }
    delete pq;
    return cost;
}
