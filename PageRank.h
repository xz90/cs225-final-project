#pragma once
#include <vector>
#include "Graph.h"

using namespace std;

class PageRank {
    public:
    void ModifyRankMatrix(Graph & graph);
    vector<double> Calculate(Graph & graph);
};