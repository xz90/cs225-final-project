# include "PageRank.h"
# include <vector>
// # include <queue>
// # include <map>
// # include <string>
# include <iostream>
# include <algorithm>

using namespace std;

void PageRank::ModifyRankMatrix(Graph & graph) {
    // operation with rankMatrix
    for (size_t i = 0; i < graph.get_num_airports(); i++) {
        size_t count = 0;
        for (size_t j = 0; j < graph.get_num_airports(); j++) {
            if (graph.get_rank_matrix()[i][j] != 0) {
                count++;
            }
        }
        if (count == 0) {
            for (size_t j = 0; j < graph.et_num_airports(); j++) {
                graph.rankMatrix[i][j] = 1.0/double(graph.et_num_airports());
            }
        } else {
            for (size_t j = 0; j < graph.et_num_airports(); j++) {
                if (graph.rankMatrix[i][j] != 0) {
                    graph.rankMatrix[i][j] = graph.rankMatrix[i][j]/count;
            }
        }
        }
        
    }
}

vector<double> PageRank::Calculate(Graph & graph) {
    size_t n = graph.get_num_airports();
    vector<double> result(n);
    // initialize the vector
    for (size_t i = 0; i < n; i++) {
        result[i] = 1.0/double(n);
    }
    // loop until converge
    while (true) {
        double lastValue = result[0];
        vector<double> copy = result;
        for (size_t i = 0; i < n; i++) {
            double sum = 0;
            for (size_t j = 0; j < n; j++) {
                sum += double(copy[j]) * double(graph.get_rank_matrix()[j][i]);
            }    
            result[i] = sum;
        }

        if (abs(result[0] - lastValue) < 0.000001) {
            break;
        }
    }

    return result;
}

vector<Airport> PageRank::rank_airport(Graph & graph) {
    // Modify the rank matrix of the graph
    ModifyRankMatrix(graph);
    double** matrix = graph.get_rank_matrix();

    // Stationary vector x
    vector<double> x_stationary = Calculate(graph);

    // initialize the rank vector
    vector<Airport> rank(graph.get_num_airports());
    vector<Airport> airport = graph.get_airports();
}