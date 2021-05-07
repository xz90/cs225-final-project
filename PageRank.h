#pragma once
#include <vector>
#include "Graph.h"

using namespace std;

class PageRank {
    private:
    vector<Airport> rank;

    public:
    void ModifyRankMatrix(Graph & graph);
    vector<double> Calculate(Graph & graph);
    vector<Airport> rank_airport();
};