#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include "Route.h"
#include "Graph.h"
#include "BFS.h"

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
	for (unsigned i = 1; i < 7699; ++i) { //7699
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

	vector<Airport> out = graph.get_airports();
	for (unsigned i = 0; i < out.size(); ++i) {
		std::cout << out[i].getAirportIATACode() << std::endl;
	}
	
	
	vector<Airport> adj_airport = graph.get_adj_airport(airports[3]);
	cout << "Our input airport is" << airports[3].getAirportIATACode() <<endl;
	cout << "The number of adjacent airports" << endl;
	cout << adj_airport.size() <<endl;
	cout << "Our adjacent airports are" << endl;
	for (unsigned i = 0; i < adj_airport.size(); ++i) {
		cout<< adj_airport[i].getAirportIATACode()<<endl;
	}
	

	// print adj matrix
	// graph.print_adj_matrix();

	// print rank matrix
	// graph.print_rank_matrix();

	bool** adj_matrix = graph.get_adj_matrix();
	double ** rank_matrix = graph.get_rank_matrix();
	cout << graph.is_equal(adj_matrix, rank_matrix) <<endl;
	

	//vector<Airport> BFStraversal = traversal(graph, airports[1]);

	// BFS

	/*
	BFS bfs;
	vector<Airport> out = bfs.traversal(graph, airports[4]);
	cout << out.size() << endl;

	cout << "BFS:" << endl;
	for (unsigned i = 0; i < out.size(); ++i) {
		cout<< out[i].getAirportIATACode() << endl;
	}

	cout << out.size() << endl;
	*/

}

		
	/*for (auto word : newout) {
		std::cout << word << std::endl;
	}*/
	/*
	// The same as above
	for (std::vector<std::string>::iterator it = vectorRepr.begin(); it != vectorRepr.end(); ++it) {
		std::cout << *it << std::endl;
	}*/