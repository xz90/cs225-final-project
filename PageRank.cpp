# include "PageRank.h"
# include <vector>
// # include <queue>
// # include <map>
// # include <string>
# include <iostream>
# include <algorithm>
# include <cmath>

using namespace std;

void PageRank::ModifyRankMatrix(Graph & graph) {
    // operation with rankMatrix
    for (int i = 0; i < graph.get_num_airports(); i++) {
        int count = 0;
        for (int j = 0; j < graph.get_num_airports(); j++) {
            if (graph.get_rank_matrix()[i][j] != 0) {
                count++;
            }
        }
        if (count == 0) {
            for (int j = 0; j < graph.get_num_airports(); j++) {
                graph.rankMatrix[i][j] = 1.0/double(graph.get_num_airports());
            }
        } else {
            for (int j = 0; j < graph.get_num_airports(); j++) {
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

        // Check
        if (abs(result[0] - lastValue) < 0.00000001) {
            break;
        }
    }

    return result;
}

vector<Airport> PageRank::rank_airport(Graph & graph) {
    // Modify the rank matrix of the graph
    // ModifyRankMatrix(graph);
    // double** matrix = graph.get_rank_matrix();

    // Stationary vector x
    vector<double> x_stationary = Calculate(graph);

    // initialize the rank vector
    vector<Airport> rank;
    vector<Airport> airport = graph.get_airports();

    for (int i = 0; i < graph.get_num_airports(); i++) {
        // Find the maximum_element index in x_stationary
        // Reference: https://stackoverflow.com/questions/2953491/finding-the-position-of-the-max-element
        int max_index = distance(x_stationary.begin(), max_element(x_stationary.begin(), x_stationary.end()));
        // cout << max_index << endl;

        // The importance of the airports base on the value of x_stationary
        // Push the corresponding airports with max_index in the rank
        rank.push_back(airport[max_index]);

        // Let the x_stationary[max_index] = -1 (remove this airport)
        x_stationary[max_index] = -1;
    }

    return rank;
    
}

void PageRank::print_rank(Graph & graph) {
    vector<Airport> rank = rank_airport(graph);
    for (size_t i = 0; i < rank.size(); i++) {
        cout << i+1 << ":" << rank[i].getAirportIATACode() << endl;
        cout << "\n";
    }
}