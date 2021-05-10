#include "Dijkstra.h"
#include <limits>
#include <iostream>



Dijkstra::Dijkstra(Graph graph, Airport source_airport) {
    airport_ = graph.get_airports();
    route_ = graph.get_routes();

    for (unsigned i = 0; i < airport_.size(); ++i) {
        distance_[airport_[i].getAirportID()] = numeric_limits<double>::infinity();
        previous_[airport_[i].getAirportID()] = 99999;
    }

    // Create a PriorityQueue
    auto my_comp =
        [](const pair<unsigned, double>& e1, const pair<unsigned, double>& e2) 
        { return e1.second > e2.second; };
    // the container should be vector
    priority_queue<pair<unsigned, double>, vector<pair<unsigned, double>>, decltype(my_comp)> Q(my_comp);

    //To find whether the source airport exist
    
    //map<Airport, double>::iterator it = distance_.find(source_airport);
    auto airportItr = find(airport_.begin(), airport_.end(), source_airport);
    int airportIdx = distance(airport_.begin(), airportItr);

    if (airportItr == airport_.end()) {
        cout << "Source airport does not exist" << endl;
        return;
    }

    distance_[airport_[airportIdx].getAirportID()] = 0;
    Q.push(make_pair(airport_[airportIdx].getAirportID(), 0));
    //int counter = 0;
    // u- unsigned double
    while(!Q.empty()) {
        //cout << "This is the " << ++counter << "th time enter the loop" << endl;
        auto u = Q.top();
        Q.pop();
        visited_.push_back(u.first);
        //for each neighbors of u not in visited;
        unsigned j;
        for (j = 0; j < airport_.size(); ++j) {
            if (airport_[j].getAirportID() == u.first) break;
        }
        //cout << "The currect Airport is "<< airport_[j].getAirportIATACode() << endl;
        vector<Airport> adj_airport = graph.get_adj_airport(airport_[j]);
        for (unsigned v = 0; v < adj_airport.size(); ++v) {
            auto visited_it = find(visited_.begin(), visited_.end(), adj_airport[v].getAirportID());
            if (visited_it == visited_.end()) {
                // if there is a directed route
                for (Route & res : route_) {
                    if (res.getSourceAirport().getAirportID() == u.first && res.getDestinationAirport() == adj_airport[v]) {

                        double dist_u_v = res.getDistance();

                        if ((distance_[u.first] + dist_u_v) < distance_[adj_airport[v].getAirportID()]) {
                            distance_[adj_airport[v].getAirportID()] = distance_[u.first] + dist_u_v;
                            previous_[adj_airport[v].getAirportID()] = u.first;
                        }
                        //cout << res.getDestinationAirport().getAirportIATACode() << endl;
                        visited_.push_back(adj_airport[v].getAirportID());
                        Q.push(make_pair(adj_airport[v].getAirportID(), distance_[adj_airport[v].getAirportID()]));
                        break;
                    }
                }
            }
        }
    }
}

double Dijkstra::shortest_distance(Airport destination_airport) {
    auto airportItr = find(airport_.begin(), airport_.end(), destination_airport);
    int airportIdx = distance(airport_.begin(), airportItr);

    if (airportItr == airport_.end()) {
        cout << "Destination airport does not exist" << endl;
        return 0;
    }

    return distance_[airport_[airportIdx].getAirportID()];
}


vector<Airport> Dijkstra::shortest_path(Airport desti)
{
    // Our input will be the starting IATA node and destination IATA node.
    // Our output should be the shortest route between these cities' airports with the
    // shortest number of connections.
    // map<unsigned, unsigned> previous_;


    unsigned destiID = desti.getAirportID();
    std::vector<unsigned> solution;
    unsigned curID = destiID;

    while (curID != 99999)
    {
        map<unsigned, unsigned>::iterator lookup = previous_.find(curID);
        if (lookup == previous_.end() || 
        distance_[curID] == numeric_limits<double>::infinity())
        {
            solution = vector<unsigned> ();
            break;
        }
        unsigned prevID = previous_[curID]; 
        solution.push_back(prevID);
        curID = prevID;
    }
    reverse(solution.begin(), solution.end());
    //cout << "1st" << solution.size() << endl;
    vector<Airport> output;
    for (unsigned i = 0; i < solution.size(); ++i) {
        //cout << i << "time" << endl;
        unsigned j;
        for (j = 0; j < airport_.size(); ++j) {
            if (airport_[j].getAirportID() == solution[i] || airport_[j].getAirportID() == 99999) {
                output.push_back(airport_[j]);
                break;
            }
        }
    }
    //cout << "2nd" << output.size() << endl;
    output.push_back(desti);
    return output;
}




// Dijkstra::Dijkstra(Graph graph, Airport source_airport) {
//     //graph_ = graph;
//     airport_ = graph.get_airports();
//     route_ = graph.get_routes();
    
//     // Initialize distance and previous
//     for (unsigned i = 0; i < airport_.size(); ++i) {
//         //auto pair = make_pair(airport_[i], numeric_limits<double>::infinity());
//         //distance_.insert(pair);
//         //distance_.insert({airport_[i], numeric_limits<double>::infinity()});
//         distance_[airport_[i]] = numeric_limits<double>::infinity();
//         previous_[airport_[i]] = Airport();
//     }
//     //cout << distance_[airport_[4125]] << endl;
//     // Create a PriorityQueue
//     auto my_comp =
//         [](const pair<Airport, double>& e1, const pair<Airport, double>& e2) 
//         { return e1.second > e2.second; };
//     // the container should be vector
//     priority_queue<pair<Airport, double>, vector<pair<Airport, double>>, decltype(my_comp)> Q(my_comp);

//     //To find whether the source airport exist
    
//     //map<Airport, double>::iterator it = distance_.find(source_airport);
//     auto airportItr = find(airport_.begin(), airport_.end(), source_airport);
//     int airportIdx = distance(airport_.begin(), airportItr);

//     // cout << (airport_[3] == source_airport) << endl;
//     // cout << numeric_limits<double>::infinity() << endl;
//     // cout << distance_[source_airport] << endl;
//     // auto it = distance_.find(source_airport);
//     //if (it == distance_.end()) {
//     if (airportItr == airport_.end()) {
//         cout << "Source airport does not exist" << endl;
//         return;
//     }
//     distance_[airport_[airportIdx]] = 0;
//     Q.push(make_pair(airport_[airportIdx], 0));
//     // Repeat n times
//     int j = 0;
//     while(!Q.empty()) {
//         auto u = Q.top();
//         Q.pop();
//         //visited_[u.first] = true;
//         visited_.push_back(u.first);
//         //for each neighbors of u not in visited;
//         vector<Airport> adj_airport = graph.get_adj_airport(u.first);
//         //cout << ++j <<endl;
//         for (unsigned v = 0; v < adj_airport.size(); ++v) {
//             //cout << v << endl;
//             //map<Airport, bool>::iterator visited_it = visited_.find(adj_airport[v]);
//             auto visited_it = find(visited_.begin(), visited_.end(), adj_airport[v]);
//             if (visited_it == visited_.end()) {
//                 //cout << "hi" << endl;
//                 // if there is a directed route
//                 for (Route & res : route_) {
//                     if (res.getSourceAirport() == u.first && res.getDestinationAirport() == adj_airport[v]) {
//                         //cout << "hi" << endl;
//                         double dist_u_v = res.getDistance();

//                         auto uItr = find(airport_.begin(), airport_.end(), u.first);
//                         int uIdx = distance(airport_.begin(), uItr);
//                         auto vItr = find(airport_.begin(), airport_.end(), adj_airport[v]);
//                         int vIdx = distance(airport_.begin(), vItr);
//                         //if (uItr == airport_.end() || vItr == airport_.end()) break;
//                         if (uIdx == 4125) {
//                             //cout << (distance_[airport_[uIdx]] + dist_u_v) << endl;
//                             cout << j++ <<"th time" << endl;
//                             cout << distance_[airport_[4125]]<< endl;
//                         }
//                         if ((distance_[airport_[uIdx]] + dist_u_v) < distance_[airport_[vIdx]]) {
//                             distance_[airport_[vIdx]] = distance_[airport_[uIdx]] + dist_u_v;
//                             previous_[airport_[vIdx]] = (u.first);
//                         }
//                         /*if ((distance_[u.first] + dist_u_v) < distance_[adj_airport[v]]) {
//                             distance_[adj_airport[v]] = distance_[u.first] + dist_u_v;
//                             previous_[adj_airport[v]] = (u.first);
//                         }*/
//                         Q.push(make_pair(adj_airport[v], distance_[adj_airport[v]]));
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     //cout << distance_[airport_[4125]] << endl;
// }

// double Dijkstra::shortest_distance(Airport destination_airport) {
//     auto airportItr = find(airport_.begin(), airport_.end(), destination_airport);
//     int airportIdx = distance(airport_.begin(), airportItr);
//     return distance_[airport_[airportIdx]];
// }