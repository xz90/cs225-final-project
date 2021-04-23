# include "BFS.h"
# include <vector>
# include <queue>
# include <map>
# include <string>
# include <iostream>


using namespace std;

vector<Airport> BFS::traversal(Graph graph, Airport airport) {
    
    int count = 0;
    Airport& start_airport = graph.get_airports()[0];
    int V = graph.get_num_airports();

    queue<Airport> queue;
    vector<bool> visited(V);
    vector<Airport> path;


    for(int i = 0; i < V; i++) {
        visited[i] = false; 
        queue.push(graph.get_airports()[i]);
    }

    visited[0] = true;

    while(!queue.empty()) {
        Airport& curr = queue.front();
        cout << curr.getAirportID() + " ";
        path.push_back(curr);
        queue.pop();

        vector<Airport> adj_airports = graph.get_adj_airport(curr);
        for (Airport& airport : adj_airports)
        {
            if (!visited[])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    // not finished



    return path;  
}