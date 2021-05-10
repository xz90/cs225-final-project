#pragma once
#include "Graph.h"
#include <map>
#include <functional>
#include <queue>
#include <utility>

using namespace std;


class Dijkstra{
    public:
    Dijkstra(Graph graph, Airport source_airport);
    double shortest_distance(Airport destination_airport);
    vector<Airport> shortest_path(Airport destination_airport);
    //Dijkstra(Graph graph, Airport source_airport, Airport destination_airport);
    private:
    vector<Airport> airport_;
    vector<Route> route_;

    map<unsigned, double> distance_;
    map<unsigned, unsigned> previous_;

    vector<unsigned> visited_;
    //vector<Airport> visited_;
};
// priority_queue in reference https://en.cppreference.com/w/cpp/container/priority_queue/priority_queue


