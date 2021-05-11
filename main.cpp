#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include "Route.h"
#include "Graph.h"
#include "BFS.h"
#include "PageRank.h"
#include "Dijkstra.h"

using namespace std;

/*
int main(int argc, const char * argv[]) {
	std::cout << "Filename: " << argv[1] << std::endl;
	
	// convert file to string representation
	std::cout << "String Representation:" << std::endl;
	std::cout << file_to_string(argv[1]) << std::endl;
	
	// convert file to vector representation
	std::cout << "Vector Representation:" << std::endl;
	std::vector<std::string> vectorRepr = file_to_vector(argv[1]);
	for (auto word : vectorRepr) {
		std::cout << word << std::endl;
	}	

	std::cout << argc << std::endl;
}
*/

Airport* findAirport(vector<Airport> & airports, string identifier);
Airport* findAirport(vector<Airport> & airports, string identifier){
	string tmp = "\"" + identifier + "\"";
	for (unsigned i = 0; i < airports.size(); ++i) {
		//cout << identifier << endl;
		if (tmp == airports[i].getAirportIATACode()) {
			return &airports[i];
		}
	}
	return NULL;
}

int main() {
	//std::cout << "Filename: " << "airports.dat.txt" << std::endl;
	
	// convert file to string representation
	/*
	std::cout << "String Representation:" << std::endl;
	std::cout << file_to_string("airports.dat.txt") << std::endl;
	*/
	
	// convert file to vector representation
	//std::cout << "Vector Representation:" << std::endl;
	// store each line into a vector


	vector<Airport> airports;
	std::vector<std::string> airportRepr = file_to_vector("airports.dat.txt");
	for (unsigned i = 1; i < 7699; ++i) { //TOTAL:7699 .. 2179
		std::vector<std::string> airportOut;
		size_t n = std::count(airportRepr[i].begin(), airportRepr[i].end(), ',');
		if (n == 13) {	// to check if the data satisfy our required format
			split(airportRepr[i], airportOut, ",");	// call split function to 
			Airport airport_target(stoul(airportOut[0]), airportOut[1], airportOut[4], stod(airportOut[6]), stod(airportOut[7]), airportOut[2], airportOut[3], stod(airportOut[8]));
			airports.push_back(airport_target);
		}
	}
	/*for (unsigned i = 0; i < airports.size(); ++i) {
		std::cout << airports[i].getAirportID() << std::endl;
	}*/

	vector<Route> routes;
	std::vector<std::string> routeRepr = file_to_vector("routes.dat.txt");
	for (unsigned i = 0; i < 67663; ++i) {
		std::vector<std::string> routeOut;
		size_t n = std::count(routeRepr[i].begin(), routeRepr[i].end(), ',');
		if (n == 8) {	// to check if the data satisfy our required format
			split(routeRepr[i], routeOut, ",");	// call split function to 
			string source_airport_id = routeOut[2];
			//cout << source_airport_id <<endl;
			string destination_airport_id = routeOut[4];
			Airport* source_airport_airport = findAirport(airports, source_airport_id);
			Airport* destination_airport_airport = findAirport(airports, destination_airport_id);
			//cout << i << endl;
			if (source_airport_airport == NULL || destination_airport_airport == NULL) continue;
			Route route_target(routeOut[0], *source_airport_airport, *destination_airport_airport, stoul(routeOut[routeOut.size()-2]));
			routes.push_back(route_target);
		}
	}
	//cout << routes.size() << endl;
	/*for (unsigned i = 0; i < routes.size(); ++i) {
		std::cout << routes[i].getSourceAirport().getAirportIATACode() << std::endl;
	}*/
		Graph graph(airports, routes);
	/*
	vector<Airport> out = graph.get_airports();
	for (unsigned i = 0; i < out.size(); ++i) {
		std::cout << out[i].getAirportIATACode() << std::endl;
	}
	*/
	
	/*
	vector<Airport> adj_airport = graph.get_adj_airport(airports[3]);
	cout << "Our input airport is" << airports[3].getAirportIATACode() <<endl;
	cout << "The number of adjacent airports" << endl;
	cout << adj_airport.size() <<endl;
	cout << "Our adjacent airports are" << endl;
	for (unsigned i = 0; i < adj_airport.size(); ++i) {
		cout<< adj_airport[i].getAirportIATACode()<<endl;
	}
	*/
	

	// print adj matrix
	// graph.print_adj_matrix();

	// print rank matrix
	// graph.print_rank_matrix();

	/*
	bool** adj_matrix = graph.get_adj_matrix();
	double ** rank_matrix = graph.get_rank_matrix();
	cout << graph.is_equal(adj_matrix, rank_matrix) <<endl;
	*/

	
	

	//vector<Airport> BFStraversal = traversal(graph, airports[1]);

	// BFS

	unsigned start;
	do {
		cout << "Now it is the BFS algoritm " << endl;
		cout << "Please type in the airport's IATA code that you want to start with" << endl;
		string source_in;
		cin >> source_in;
		source_in = "\""+source_in+"\"";
		cout << "Your starting airport is " << source_in << endl;
		for (start = 0; start < airports.size(); ++start) {
			if (airports[start].getAirportIATACode() == source_in) {
				break;
			}
		}
		if (start == airports.size()) {
			cout << "Your input IATA code for the starting airport is not correct" << endl;
			cout << "Please try it again" << endl;
		}
	} while (start == airports.size());

	BFS bfs;
	vector<Airport> out = bfs.traversal(graph, airports[start]);
	cout << out.size() << endl;

	cout << "BFS:" << endl;
	for (unsigned i = 0; i < out.size(); ++i) {
		cout<< out[i].getAirportIATACode() << endl;
	}

	cout << out.size() << endl;
	

	// PageRank
	cout << "Now it is the PageRank algoritm " << endl;
	cout << "Press any keys to continue" << endl;
	string page;
	cin >> page;
	cout << "Please wait for a second" << endl;
	PageRank pagerank;
	vector<double> x = pagerank.Calculate(graph);

	vector<Airport> rank = pagerank.rank_airport(graph);
	// cout << rank[0].getAirportIATACode() << endl;
	pagerank.print_rank(graph);
	
	// Dijkstra
	// 3 4 connected
	// BEJ 3364 ORD 3830 GKA1
	unsigned s, d;
	do {
		cout << "Now it is the Dijkstra algoritm " << endl;
		cout << "Please enter the source airport you wanted to search" << endl;
		string source_d;
		cin >> source_d;
		source_d = "\""+source_d+"\"";
		
		for (s = 0; s < airports.size(); ++s) {
			if (airports[s].getAirportIATACode() == source_d) {
				break;
			}
		}

		cout << "Please enter the destination airport you wanted to search" << endl;
		string dest_d;
		cin >> dest_d;
		dest_d = "\""+dest_d+"\"";
		
		for (d = 0; d < airports.size(); ++d) {
			if (airports[d].getAirportIATACode() == dest_d) {
				break;
			}
		}

		if ( s == airports.size() ) {
			cout << "Your input IATA code for source airport is not correct" << endl;
			cout << "Please try it again" << endl;
		}
		
		if ( d == airports.size() ) {
			cout << "Your input IATA code for destination airport is not correct" << endl;
			cout << "Please try it again" << endl;
		}

	} while ( (s == airports.size()) || (d == airports.size()) );

	cout << "Please wait for a second" << endl;

	cout << "Our source airport is " << airports[s].getAirportIATACode() << endl;
	Dijkstra dijkstra(graph, airports[s]);
	cout << "Our destination airport is " << airports[d].getAirportIATACode() << endl;
	cout << "Shortest distance between them is " << dijkstra.shortest_distance(airports[d]) << endl;
	cout << "The shortest path between them is" << endl;
	vector<Airport> shortest_path_id = dijkstra.shortest_path(airports[d]);
	for (unsigned i = 0; i < shortest_path_id.size(); ++i) {
		cout << shortest_path_id[i].getAirportIATACode()<< endl;
	}
}

		
	/*for (auto word : newout) {
		std::cout << word << std::endl;
	}*/
	/*
	// The same as above
	for (std::vector<std::string>::iterator it = vectorRepr.begin(); it != vectorRepr.end(); ++it) {
		std::cout << *it << std::endl;
	}*/