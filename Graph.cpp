#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph() {}

Graph::~Graph() {
    for (unsigned long i = 0; i < _airports.size(); i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

// Adj matrix constructor 
Graph::Graph(vector<Airport> & airports, vector<Route> & routes) {
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
    for (size_t k = 0; k < _routes.size(); k++) {
        Airport source = _routes[k].getSourceAirport();
        /*if (k == 0) {
            cout << source.getAirportIATACode() <<endl;
            cout << _airports[2806].getAirportIATACode()<<endl;
            cout << source.getAirportID() << "/" << _airports[2806].getAirportID() <<endl;
            cout << source.getAirportName() << "/" << _airports[2806].getAirportName() <<endl;
            //cout << source.getAirportPosition() << "/" << _airports[2806].getAirportPosition() <<endl;
            //cout << source.getAirportLocation() << "/" << _airports[2806].getAirportLocation() <<endl;
            cout << source.getAirportAltitude() << "/" << _airports[2806].getAirportAltitude() <<endl;
            cout << (source == _airports[2806]) << endl;
        }*/
        //
        Airport destination = _routes[k].getDestinationAirport();

        auto sourceItr = find(_airports.begin(), _airports.end(), source);
        auto destinationItr = find(_airports.begin(), _airports.end(), destination);

        // Check whether the source and destination are in the airports vector
        if (sourceItr != _airports.end() && destinationItr != _airports.end()) 
        {
            int sourceIdx = distance(_airports.begin(), sourceItr);
            //cout << sourceIdx << endl;
            int destinationIdx = distance(_airports.begin(),destinationItr);
            adjMatrix[sourceIdx][destinationIdx] = true;
            adjMatrix[destinationIdx][sourceIdx] = true;
        }
    }

    // Create rankMatrix;
    rankMatrix = new double*[_numAirports];

    // initialize the matrix to zero
    for (int i = 0; i < _numAirports; i++) {
        rankMatrix[i] = new double[_numAirports];
        for (int j = 0; j < _numAirports; j++) {
            rankMatrix[i][j] = 0;
        }
    }

    // initilize the matrix with the route
    for (size_t k = 0; k < _routes.size(); k++) {
        Airport source = _routes[k].getSourceAirport();
        Airport destination = _routes[k].getDestinationAirport();

        auto sourceItr = find(_airports.begin(), _airports.end(), source);
        auto destinationItr = find(_airports.begin(), _airports.end(), destination);

        // Check whether the source and destination are in the airports vector
        if (sourceItr != _airports.end() && destinationItr != _airports.end()) 
        {
            int sourceIdx = distance(_airports.begin(), sourceItr);
            //cout << sourceIdx << endl;
            int destinationIdx = distance(_airports.begin(),destinationItr);
            rankMatrix[sourceIdx][destinationIdx] = 1;
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

bool** Graph::get_adj_matrix() const {
      return adjMatrix;
}

int Graph::get_num_airports() {
    return _numAirports;
}

vector<Airport> & Graph::get_airports() {
    return _airports;
}

vector<Route> & Graph::get_routes() {
    return _routes;
}

double** Graph::get_rank_matrix() const {
    return rankMatrix;
}

vector<Airport> Graph::get_adj_airport(Airport airport) {

    vector<Airport> res = vector<Airport>();

    auto airportItr = find(_airports.begin(), _airports.end(), airport);

    // Check _airports whether contains airport
    //cout << "checkpoint 1" << endl;
    if (airportItr != _airports.end()) {
        //cout << "checkpoint 2" <<endl;
        // get the Index of this airport
        int airportIdx = distance(_airports.begin(), airportItr);
        //cout << airportIdx << endl;
        // Find the Adj edges
        for (int i = 0; i < _numAirports; i++) {
            if (adjMatrix[airportIdx][i]) {
                res.push_back(_airports[i]);
            }
        }
    }
    // maybe too slow
    // O (deg(airport)) use map airport -> index
    
    return res;
}

bool Graph::exist_airport(Airport airport) {
    for (size_t i = 0; i < _airports.size(); i++) {
        if (airport == _airports[i]) {
            return true;
        }
    }
    return false;
}

void Graph::print_adj_matrix() {
    for (int i = 0; i < _numAirports; i++) {
        cout << i << ":";
        for (int j = 0; j < _numAirports; j++) {
            cout <<adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void Graph::print_rank_matrix() {
    for (int i = 0; i < _numAirports; i++) {
        cout << i << ":";
        for (int j = 0; j < _numAirports; j++) {
            cout <<rankMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

bool Graph::is_equal(bool** adj, double** rank) {
    bool res = true;
    for (int i = 0; i < _numAirports; i++) {
        for (int j = 0; j < _numAirports; j++) {
            if (adj[i][j] == true && rank[i][j] == 0) {
                res = false;
            }

            if (adj[i][j] == false && rank[i][j] == 1) {
                res = false;
            }
        }
    }
    return false;
}


