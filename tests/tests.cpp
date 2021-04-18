#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../Airport.h"


// TEST CASES FOR AIRPORT CLASS
TEST_CASE("Constructor") {
	unsigned id = 0;
	Airport sample(id, "test", "TEST", 1.1, 2.2 ,"Champagin", "USA", 0);
	// REQUIRE(sample.getAirportID() == 0);
	// REQUIRE(sample.getAirportName() == "test");
	// REQUIRE(sample.getAirportIATACode() == "TEST");
	// pair<double, double> sample_position = std::make_pair(1.1, 2.2);
	// REQUIRE(sample.getAirportPosition() == sample_position);
	// pair<std::string, std::string> sample_location = std::make_pair("Champaign", "USA");
	// REQUIRE(sample.getAirportLocation() == sample_location);
}

// TEST_CASE("operator== for Airport class") {
// 	unsigned id = 0;
// 	Airport sample(id, "test", "TEST", 1.1, 2.2 ,"Champagin", "USA", 0);
// 	Airport sample1(id, "test", "TEST", 1.1, 2.2 ,"Champagin", "USA", 0);
// 	Airport sample2(id, "test", "TEST", 1.1, 2.3 ,"Champagin", "USA", 0);
// 	REQUIRE(sample == sample1);
// 	REQUIRE(!(sample == sample2));
// }
// END TEST CASES FOR AIRPORT CLASS



TEST_CASE("Verify that file_to_string works on a small example") {
	std::string res = file_to_string("tests/smallSample.txt");
	// always check "expected" == "actual" --> be consistent
	REQUIRE("hello\nstudents\nof\ncs\n225\n!!!\n" == res);
}

TEST_CASE("Verify that file_to_vector works on a small example") {
	std::vector<std::string> res = file_to_vector("tests/smallSample.txt");
	std::string expected[] = {"hello", "students", "of", "cs", "225", "!!!"};
	
	REQUIRE(6 == res.size());

	for (int i = 0; i < res.size(); i++) {
		REQUIRE(expected[i] == res[i]);
	}
}		
