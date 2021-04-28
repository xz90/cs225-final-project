# include "BFS.h"
# include <vector>
# include <queue>
# include <map>
# include <string>
# include <iostream>
#include <algorithm>

using namespace std;

vector<Airport> BFS::traversal(Graph & graph, Airport & source) {

    //given source airport find all reachable, if there is a path, we can reach
    // 

    if (!graph.exist_airport(source)) {
        return vector<Airport>();
    }
    // int count = 0;
    int V = graph.get_num_airports();

    queue<Airport> queue;
    vector<bool> visited(V);//2d
    // which airport -> each bool
    vector<Airport> reachable_ap;//顺序和visited顺序一样
    queue.push(source);
    //unsigned id = source.getAirportID();// 

    auto sourceItr = find(reachable_ap.begin(), reachable_ap.end(), source);//iterator
    // int distance(source, idx)
    int sourceidx = distance(reachable_ap.begin(), sourceItr);// idx of source
    for(int i = 0; i < V; i++) {
        visited[i] = false; 
    }
    // id now is the index of vector visited
    visited[sourceidx] = true;
    // https://www.geeksforgeeks.org/how-to-find-index-of-a-given-element-in-a-vector-in-cpp/
    while(!queue.empty()) {
        Airport& curr = queue.front();
        reachable_ap.push_back(curr);

        queue.pop();

        vector<Airport> adj_airports = graph.get_adj_airport(curr);
        for (size_t i = 0; i < adj_airports.size(); i++) 
        {
            auto curItr = find(reachable_ap.begin(), reachable_ap.end(), adj_airports[i]);
            int cur_idx = distance(reachable_ap.begin(), curItr);
            //unsigned cur_id = adj_airports[i].getAirportID();
            if (!visited[cur_idx])
            {
                visited[cur_idx] = true;
                queue.push(adj_airports[i]);
            }
        }
    }

    return reachable_ap;  
}