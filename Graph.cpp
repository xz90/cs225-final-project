#include "Graph.h"

using namespace std;

Graph::Graph() {}

Graph::~Graph() {
    for (unsigned long i = 0; i < _airports.size(); i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

// Adj matrix constructor 
Graph::Graph(vector<Airport> airports, vector<Route> routes) {
    _airports = airports;
    _routes = routes;

    _numAirports = _airports.size();

    adjMatrix = new bool*[_numAirports];

    // initialize the matrix to zero
    for (int i = 0; i < _numAirports; i++) {
        adjMatrix[i] = new bool[_numAirports];
        for (int j = 0; j < _numAirports; j++) {
            adjMatrix[i][j] = false;
        }
    }

    // initilize the matrix with the route
    for (unsigned k = 0; k < _routes.size(); k++) {
        Airport source = _routes[k].getSourceAirport();
        Airport destination = _routes[k].getDestinationAirport();

        auto sourceItr = find(_airports.begin(), _airports.end(), source);
        auto destinationItr = find(_airports.begin(), _airports.end(), destination);

        // Check whether the source and destination are in the airports vector
        if (sourceItr != _airports.end() && destinationItr != _airports.end()) 
        {
            int sourceIdx = distance(_airports.begin(), sourceItr);
            int destinationIdx = distance(_airports.begin(),destinationItr);
            adjMatrix[sourceIdx][destinationIdx] = true;
        }
    }
   
}

  Graph::Graph(const Graph& other) {
    adjMatrix = new bool*[other._numAirports];
    for (int i = 0; i < other._numAirports; i++) {
        adjMatrix[i] = new bool[other._numAirports];
        for (int j = 0; j < other._numAirports; j++) {
            adjMatrix[i][j] = other.adjMatrix[i][j];
        }
    }
    _airports = other._airports;
    _routes = other._routes;
    _numAirports = other._numAirports;
  }

vector<Airport> Graph::get_adj_airport(Airport airport) {

    vector<Airport> res = vector<Airport>();

    auto airportItr = find(_airports.begin(), _airports.end(), airport);

    // Check _airports whether contains airport
    if (airportItr != _airports.end()) {
        // get the Index of this airport
        int airportIdx = distance(_airports.begin(), airportItr);

        // Find the Adj edges
        for (int i = 0; i < _numAirports; i++) {
            if (adjMatrix[airportIdx][i]) {
                res.push_back(_airports[i]);
            }
        }
    }

    return res;
}