# include "PageRank.h"
# include <vector>
// # include <queue>
// # include <map>
// # include <string>
// # include <iostream>
// #include <algorithm>

using namespace std;

vector<double> PageRank::calculate(Graph & graph) {
    vector<double> result;
    // operation with rankMatrix
    for (size_t i = 0; i < graph.get_airports().size(); i++) {
        size_t count = 0;
        for (size_t j = 0; j < graph.get_airports().size(); j++) {
            if (graph.get_rank_matrix()[i][j] != 0) {
                count++;
            }
        }
        for (size_t j = 0; j < graph.get_airports().size(); j++) {
            if (graph.get_rank_matrix()[i][j] != 0) {
                graph.get_rank_matrix()[i][j] = graph.get_rank_matrix()[i][j]/count;
            }
        }
    }
    return result;
}