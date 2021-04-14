#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"


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
