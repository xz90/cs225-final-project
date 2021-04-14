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
	
	/*std::cout << vectorRepr[0] << std::endl;
	std::cout << vectorRepr[1] << std::endl;
	std::cout << vectorRepr[2] << std::endl;
	std::cout << vectorRepr[3] << std::endl;
	std::cout << vectorRepr[4] << std::endl;*/
	
	for (auto word : vectorRepr) {
		std::cout << word << std::endl;
	}
	


}
