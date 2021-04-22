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
  int _numAirports; // number of airports we want to use

    
public:
  Graph();
  Graph(vector<Airport> airports, vector<Route> routes);
  ~Graph();

  vector<Airport> get_adj_airport(Airport airport);
  
    
};


