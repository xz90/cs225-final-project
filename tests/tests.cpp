#include <string>
#include <vector>
#include <iostream>

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../Airport.h"
#include "../Route.h"
#include "../Graph.h"
#include "../PageRank.h"
#include "../Dijkstra.h"

// TEST CASES FOR AIRPORT CLASS
TEST_CASE("Airport Constructor") {
	unsigned id = 0;
	Airport sample(id, "test", "TEST", 1.1, 2.2 ,"Champaign", "USA", 0);
	REQUIRE(sample.getAirportID() == 0);
	REQUIRE(sample.getAirportName() == "test");
	REQUIRE(sample.getAirportIATACode() == "TEST");
	pair<double, double> sample_position = std::make_pair(1.1, 2.2);
	REQUIRE(sample.getAirportPosition() == sample_position);
	pair<std::string, std::string> sample_location = std::make_pair("Champaign", "USA");
	REQUIRE(sample.getAirportLocation() == sample_location);
}

TEST_CASE("operator== for Airport class") {
	unsigned id = 0;
	Airport sample(id, "test", "TEST", 1.1, 2.2 ,"Champagin", "USA", 0);
	Airport sample1(id, "test", "TEST", 1.1, 2.2 ,"Champagin", "USA", 0);
	Airport sample2(id, "test", "TEST", 1.1, 2.3 ,"Champagin", "USA", 0);
	REQUIRE(sample == sample1);
	REQUIRE(!(sample == sample2));
}
// END TEST CASES FOR AIRPORT CLASS


// TEST CASES FOR ROUTE CLASS
TEST_CASE("Constructor") {
	unsigned id = 0;
	unsigned id1 = 1;
	Airport sample(id, "test", "TEST", 1.1, 2.2 ,"Champaign", "USA", 0);
	Airport sample1(id, "test1", "TESTONE", 1.0, 2.2 ,"Chicago", "USA", 1);
	Route sampleRoute("route", sample, sample1, id1);
	SUCCEED();
}
// Route(string IATAcode, Airport& source, Airport& destination, 
//unsigned stops);


TEST_CASE("get distance of routes") {
	unsigned id = 0;
	unsigned id1 = 1;
	Airport sample(id, "test", "TEST", 1.1, 2.2 ,"Champaign", "USA", 0);
	Airport sample1(id, "test1", "TESTONE", 1.0, 2.2 ,"Chicago", "USA", 1);
	Route sampleRoute("route", sample, sample1, id1);
	REQUIRE(sampleRoute.getSourceAirport() == sample);
	REQUIRE(sampleRoute.getDestinationAirport() == sample1);
	REQUIRE(sampleRoute.getRouteIATACode() == "route");
	//REQUIRE(sampleRoute.getRouteID() == id);
	REQUIRE(sampleRoute.getDistance() == Approx(11.1194926645));
}

// END TEST CASES FOR ROUTE CLASS


TEST_CASE("Verify that file_to_string works on a small example") {
	std::string res = file_to_string("tests/smallSample.txt");
	// always check "expected" == "actual" --> be consistent
	REQUIRE("hello\nstudents\nof\ncs\n225\n!!!\n" == res);
}

TEST_CASE("Verify that file_to_vector works on a small example") {
	std::vector<std::string> res = file_to_vector("tests/smallSample.txt");
	std::string expected[] = {"hello", "students", "of", "cs", "225", "!!!"};
	
	REQUIRE(6 == res.size());

	// for (int i = 0; i < res.size(); i++) {
	// 	REQUIRE(expected[i] == res[i]);
	// }
}		


// TEST CASE FOR GRAPH CLASS
TEST_CASE("Graph Test") {
	unsigned idA = 0;
	unsigned idB = 1;
	unsigned idC = 2;
	unsigned idD = 3;
	unsigned idE = 4;
	Airport sampleA(idA, "test1", "A", 1.1, 2.2 ,"Champaign", "USA", 0);
	Airport sampleB(idB, "test1", "B", 1.0, 2.2 ,"Chicago", "USA", 0);
	Airport sampleC(idC, "test1", "C", 1.0, 2.2 ,"New York", "USA", 0);
	Airport sampleD(idD, "test1", "D", 1.0, 2.2 ,"Los Angeles", "USA", 0);
	Airport sampleE(idE, "test1", "E", 1.0, 2.2 ,"Washington", "USA", 0);
	vector<Airport> sampleAirportList;
	sampleAirportList.push_back(sampleA);
	sampleAirportList.push_back(sampleB);
	sampleAirportList.push_back(sampleC);
	sampleAirportList.push_back(sampleD);
	sampleAirportList.push_back(sampleE);
	Route sampleRouteAB("routeAB", sampleA, sampleB, 0);
	Route sampleRouteAC("routeAC", sampleA, sampleC, 0);
	Route sampleRouteAD("routeAD", sampleA, sampleD, 0);
	Route sampleRouteBA("routeBA", sampleB, sampleA, 0);
	Route sampleRouteBD("routeBD", sampleB, sampleD, 0);
	Route sampleRouteCA("routeCA", sampleC, sampleA, 0);
	Route sampleRouteDB("routeDB", sampleD, sampleB, 0);
	vector<Route> sampleRouteList;
	sampleRouteList.push_back(sampleRouteAB);
	sampleRouteList.push_back(sampleRouteAC);
	sampleRouteList.push_back(sampleRouteAD);
	sampleRouteList.push_back(sampleRouteBA);
	sampleRouteList.push_back(sampleRouteBD);
	sampleRouteList.push_back(sampleRouteCA);
	sampleRouteList.push_back(sampleRouteDB);
	Graph sampleGraph(sampleAirportList, sampleRouteList);
	SUCCEED();

	SECTION("Graph Constructor test"){
		REQUIRE(sampleGraph.get_num_airports() == 5);

		// rank matrix
		REQUIRE(sampleGraph.get_rank_matrix()[0][1] == 1);
		REQUIRE(sampleGraph.get_rank_matrix()[1][0] == 1);
		REQUIRE(sampleGraph.get_rank_matrix()[3][0] == 0);

		// adj matrix
		REQUIRE(sampleGraph.get_adj_matrix()[0][1] == 1);
		REQUIRE(sampleGraph.get_adj_matrix()[3][0] == 1);
	}

	SECTION("Adj Airport Test"){
		vector<Airport> adj_airport = sampleGraph.get_adj_airport(sampleA);
		REQUIRE(std::find(adj_airport.begin(), adj_airport.end(), sampleB) != adj_airport.end());
		REQUIRE(std::find(adj_airport.begin(), adj_airport.end(), sampleC) != adj_airport.end());
		REQUIRE(std::find(adj_airport.begin(), adj_airport.end(), sampleD) != adj_airport.end());
	}

}

// END TEST CASE FOR GRAPH CLASS

// TEST CASE FOR PAGERANK
TEST_CASE("Graph Constructor for PageRank") {
	unsigned idA = 0;
	unsigned idB = 1;
	unsigned idC = 2;
	unsigned idD = 3;
	unsigned idE = 4;
	Airport sampleA(idA, "test1", "A", 1.1, 2.2 ,"Champaign", "USA", 0);
	Airport sampleB(idB, "test1", "B", 1.0, 2.2 ,"Chicago", "USA", 0);
	Airport sampleC(idC, "test1", "C", 1.0, 2.2 ,"New York", "USA", 0);
	Airport sampleD(idD, "test1", "D", 1.0, 2.2 ,"Los Angeles", "USA", 0);
	Airport sampleE(idE, "test1", "E", 1.0, 2.2 ,"Washington", "USA", 0);
	vector<Airport> sampleAirportList;
	sampleAirportList.push_back(sampleA);
	sampleAirportList.push_back(sampleB);
	sampleAirportList.push_back(sampleC);
	sampleAirportList.push_back(sampleD);
	sampleAirportList.push_back(sampleE);
	Route sampleRouteAB("routeAB", sampleA, sampleB, 0);
	Route sampleRouteAC("routeAC", sampleA, sampleC, 0);
	Route sampleRouteAD("routeAD", sampleA, sampleD, 0);
	Route sampleRouteBA("routeBA", sampleB, sampleA, 0);
	Route sampleRouteBD("routeBD", sampleB, sampleD, 0);
	Route sampleRouteCA("routeCA", sampleC, sampleA, 0);
	Route sampleRouteDB("routeDB", sampleD, sampleB, 0);
	vector<Route> sampleRouteList;
	sampleRouteList.push_back(sampleRouteAB);
	sampleRouteList.push_back(sampleRouteAC);
	sampleRouteList.push_back(sampleRouteAD);
	sampleRouteList.push_back(sampleRouteBA);
	sampleRouteList.push_back(sampleRouteBD);
	sampleRouteList.push_back(sampleRouteCA);
	sampleRouteList.push_back(sampleRouteDB);
	Graph sampleGraph(sampleAirportList, sampleRouteList);
	PageRank pagerank;
	SUCCEED();

	SECTION("Pagerank modify test"){
		REQUIRE(sampleGraph.get_rank_matrix()[0][1] == 1);
		REQUIRE(sampleGraph.get_rank_matrix()[1][0] == 1);
		pagerank.ModifyRankMatrix(sampleGraph);
		REQUIRE(sampleGraph.get_rank_matrix()[0][1] == Approx(0.333333333333));
		REQUIRE(sampleGraph.get_rank_matrix()[1][0] == Approx(0.5));
	}

	SECTION("Pagerank calculate test"){
		REQUIRE(sampleGraph.get_rank_matrix()[0][1] == 1);
		REQUIRE(sampleGraph.get_rank_matrix()[1][0] == 1);
		pagerank.ModifyRankMatrix(sampleGraph);
		REQUIRE(sampleGraph.get_rank_matrix()[0][0] == 0.0);
		REQUIRE(sampleGraph.get_rank_matrix()[0][1] == Approx(0.333333333333));
		REQUIRE(sampleGraph.get_rank_matrix()[1][0] == Approx(0.5));
		vector<double> answer = pagerank.Calculate(sampleGraph);
		REQUIRE(answer.size() == sampleGraph.get_airports().size());
		REQUIRE(answer[0] == Approx(0.268));
	}

	SECTION("Pagerank empty row"){
		REQUIRE(sampleGraph.get_rank_matrix()[4][0] == 0);
		pagerank.ModifyRankMatrix(sampleGraph);
		REQUIRE(sampleGraph.get_rank_matrix()[4][0] == 0.2);
	}

	SECTION("Pagerank rank test"){
		pagerank.ModifyRankMatrix(sampleGraph);
		vector<Airport> rank = pagerank.rank_airport(sampleGraph);
		REQUIRE(rank[0] == sampleB);
	}
	
	
	
	
	
}
// END TEST CASE FOR PAGERANK

TEST_CASE("Dijkstra's algorithm") {
	unsigned idA = 0;
	unsigned idB = 1;
	unsigned idC = 2;
	unsigned idD = 3;
	unsigned idE = 4;
	Airport sampleA(idA, "test1", "TESTONE", 1.0, 1.0 ,"Champaign", "USA", 0);
	Airport sampleB(idB, "test1", "TESTONE", 1.0, 2.0 ,"Chicago", "USA", 0);
	Airport sampleC(idC, "test1", "TESTONE", 1.0, 4.0 ,"New York", "USA", 0);
	Airport sampleD(idD, "test1", "TESTONE", 1.0, 8.0 ,"Los Angeles", "USA", 0);
	Airport sampleE(idE, "test1", "TESTONE", 1.0, 16.0 ,"Washington", "USA", 0);
	vector<Airport> sampleAirportList;
	sampleAirportList.push_back(sampleA);
	sampleAirportList.push_back(sampleB);
	sampleAirportList.push_back(sampleC);
	sampleAirportList.push_back(sampleD);
	sampleAirportList.push_back(sampleE);
	Route sampleRouteAB("routeAB", sampleA, sampleB, 0);
	Route sampleRouteAC("routeAC", sampleA, sampleC, 0);
	Route sampleRouteAD("routeAD", sampleA, sampleD, 0);
	Route sampleRouteBA("routeBA", sampleB, sampleA, 0);
	Route sampleRouteBD("routeBD", sampleB, sampleD, 0);
	Route sampleRouteCA("routeCA", sampleC, sampleA, 0);
	Route sampleRouteDB("routeDB", sampleD, sampleB, 0);
	vector<Route> sampleRouteList;
	sampleRouteList.push_back(sampleRouteAB);
	sampleRouteList.push_back(sampleRouteAC);
	sampleRouteList.push_back(sampleRouteAD);
	sampleRouteList.push_back(sampleRouteBA);
	sampleRouteList.push_back(sampleRouteBD);
	sampleRouteList.push_back(sampleRouteCA);
	sampleRouteList.push_back(sampleRouteDB);
	Graph sampleGraph(sampleAirportList, sampleRouteList);
	Dijkstra dijkstra(sampleGraph, sampleA);
	SUCCEED();
	REQUIRE(dijkstra.shortest_distance(sampleA) == 0);
	REQUIRE(dijkstra.shortest_distance(sampleB) == sampleRouteAB.getDistance());
	REQUIRE(dijkstra.shortest_distance(sampleC) == sampleRouteAC.getDistance());
	REQUIRE(dijkstra.shortest_distance(sampleE) == numeric_limits<double>::infinity());
	REQUIRE(dijkstra.shortest_distance(sampleD) == min(sampleRouteAB.getDistance() + sampleRouteBD.getDistance(), sampleRouteAD.getDistance()));
}
