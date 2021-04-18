#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "Airport.h"



TEST_CASE("Constructor") {
	
	REQUIRE(1==2);
}

// TEST_CASE("Verify that file_to_vector works on a small example") {
// 	std::vector<std::string> res = file_to_vector("tests/smallSample.txt");
// 	std::string expected[] = {"hello", "students", "of", "cs", "225", "!!!"};
	
// 	REQUIRE(6 == res.size());

// 	for (int i = 0; i < res.size(); i++) {
// 		REQUIRE(expected[i] == res[i]);
// 	}
// }	