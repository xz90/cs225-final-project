#include <iostream>
#include <vector>
#include "readFromFile.hpp"

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
std::vector<std::string> line_split(std::vector<std::string> vec, int position);
int main() {
	std::cout << "Filename: " << "airports.dat.txt" << std::endl;
	
	// convert file to string representation
	/*
	std::cout << "String Representation:" << std::endl;
	std::cout << file_to_string("airports.dat.txt") << std::endl;
	*/
	
	// convert file to vector representation
	std::cout << "Vector Representation:" << std::endl;
	std::vector<std::string> vectorRepr = file_to_vector("airports.dat.txt");
	

	
	std::vector<std::string> out;
	out = line_split(vectorRepr, 3);
	/*for (auto word : out) {
		std::cout << word << std::endl;
	}*/
	/*for (std::vector<std::string>::iterator it = vectorRepr.begin(); it != vectorRepr.end(); ++it) {
		std::cout << *it << std::endl;
	}*/
	/*std::cout << out[0] << std::endl;
	std::cout << out[1] << std::endl;
	std::cout << out[2] << std::endl;
	std::cout << out[3] << std::endl;
	std::cout << out[4] << std::endl;*/
	/*for (int i = 0; i < 629; ++i) {
		std::cout << out[i] << std::endl;
	}*/
	/*std::cout << vectorRepr[0] << std::endl;
	std::cout << vectorRepr[1] << std::endl;
	std::cout << vectorRepr[2] << std::endl;
	std::cout << vectorRepr[3] << std::endl;
	std::cout << vectorRepr[4] << std::endl;*/
}
