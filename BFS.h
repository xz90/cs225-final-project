#pragma once
#include <string>
#include <vector>
#include <algorithm> 
#include "Route.h"
#include "Airport.h"
#include "Graph.h"

using namespace std;

class BFS {
    public:
    vector<Airport> traversal(Graph & graph, Airport & airport);
};
