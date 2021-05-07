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
  bool** adjMatrix; // Undirected
  vector<Airport> _airports;
  vector<Route> _routes;
  int _numAirports; // number of airports we want to use
  

    
public:
  Graph();
  Graph(vector<Airport> & airports, vector<Route> & routes);
  Graph(const Graph& other);
  ~Graph();

  double** rankMatrix; // Directed, Used for PageRank

  
  bool** get_adj_matrix() const;
  double** get_rank_matrix() const;
  int get_num_airports();
  vector<Airport> & get_airports();
  vector<Route> & get_routes();
  vector<Airport> get_adj_airport(Airport airport);
  bool exist_airport(Airport airport);
  void print_adj_matrix();
  void print_rank_matrix();

  bool is_equal(bool** adj, double** rank); // Check whether adjMatrix and rankMatrix are the same
    
};



