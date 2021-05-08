#pragma once
#include "Graph.h"
#include <map>
#include <functional>
#include <queue>
#include <utility>

using namespace std;

//using my_pair_t = std::pair<Airport, double>;
 
//using my_container_t = std::map<my_pair_t>;
static auto my_comp =
        [](const pair<Airport, double>& e1, const pair<Airport, double>& e2) 
        { return e1.second > e2.second; };

class Dijkstra{
    public:
    Dijkstra(Graph graph, Airport source_airport, Airport destination_airport);
    private:
    Airport airport_;
    Route route_;
    Graph graph_;

    map<Airport, double> distance_;
    map<Airport, Airport*> previous_;
    
    priority_queue<pair<Airport, double>, map<Airport, double>, decltype(my_comp)> priority_queue_(decltype(my_comp));

    map<Airport, bool> visited_;
};
// priority_queue in reference https://en.cppreference.com/w/cpp/container/priority_queue/priority_queue


// Dijkstra(Graph, source, destination):

//   initialize distances  // initialize tentative distance value
//   initialize previous   // initialize a map that maps current node -> its previous node
//   initialize priority_queue   // initialize the priority queue
//   initialize visited

//   while the top of priority_queue is not destination:
//       get the current_node from priority_queue
//       for neighbor in current_node's neighbors and not in visited:
//           if update its neighbor's distances:
//               previous[neighbor] = current_node
//       save current_node into visited

//   extract path from previous
//   return path and distance