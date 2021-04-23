# include "BFS.h"
# include <vector>
# include <queue>
# include <map>
# include <string>
# include <iostream>


using namespace std;

vector<Airport> BFS::traversal(Graph graph, Airport source) {

    //given source airport find all reachable, if there is a path, we can reach
    // 

    if (!graph.exist_airport(source)) {
        return vector<Airport>();
    }

    // int count = 0;
    int V = graph.get_num_airports();

    queue<Airport> queue;
    vector<bool> visited(V);
    // which airport -> each bool
    vector<Airport> reachable_ap;
    queue.push(source);
    unsigned id = source.getAirportID();

    for(int i = 0; i < V; i++) {
        visited[i] = false; 
    }
    // id now is the index of vector visited
    visited[id] = true;

    while(!queue.empty()) {
        Airport& curr = queue.front();
        reachable_ap.push_back(curr);
        queue.pop();

        vector<Airport> adj_airports = graph.get_adj_airport(curr);
        for (size_t i = 0; i < adj_airports.size(); i++) 
        {
            unsigned cur_id = adj_airports[i].getAirportID();
            if (!visited[cur_id])
            {
                visited[cur_id] = true;
                queue.push(adj_airports[i]);
            }
        }
    }

    return reachable_ap;  
}