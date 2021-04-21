#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../Airport.h"
#include "../Route.h"


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
	Route sampleRoute(id, "route", sample, sample1, id1);
	SUCCEED();
}

TEST_CASE("get distance of routes") {
	unsigned id = 0;
	unsigned id1 = 1;
	Airport sample(id, "test", "TEST", 1.1, 2.2 ,"Champaign", "USA", 0);
	Airport sample1(id, "test1", "TESTONE", 1.0, 2.2 ,"Chicago", "USA", 1);
	Route sampleRoute(id, "route", sample, sample1, id1);
	REQUIRE(sampleRoute.getSourceAirport() == sample);
	REQUIRE(sampleRoute.getDestinationAirport() == sample1);
	REQUIRE(sampleRoute.getRouteIATACode() == "route");
	REQUIRE(sampleRoute.getRouteID() == id);
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
