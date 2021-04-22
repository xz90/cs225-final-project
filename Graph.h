#pragma once
#include <string>
#include <vector>
#include <algorithm> 
#include "Route.h"
#include "Airport.h"

using namespace std;

// Graph Implementation: Adj Matrix 

/*
Reference: 
1. programiz.com/dsa/graph-adjacency-matrix
*/

class Graph
{
private:
  // Vertices : Airport
  // Edges: Route
  bool** adjMatrix;
  vector<Airport> _airports;
  vector<Route> _routes;

    
public:
  Graph();
  Graph(vector<Airport> airports, vector<Route> routes);
  ~Graph();

  bool areAdjacent(Airport airport1, Airport airport2);
  vector<Route> incidentEdges(Airport airport);
  
    
};



