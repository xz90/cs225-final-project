#pragma once
#include <vector>
#include "Graph.h"

using namespace std;

class PageRank {
    public:
    vector<double> calculate(Graph & graph);
};