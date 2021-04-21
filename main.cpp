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
	// store each line into a vector
	/*std::vector<std::string> vectorRepr = file_to_vector("airports.dat.txt");
	std::vector<std::string> out;
	for (unsigned i = 1; i < 7699; ++i) {
		size_t n = std::count(vectorRepr[i].begin(), vectorRepr[i].end(), ',');
		if (n == 13) {	// to check if the data satisfy our required format
			split(vectorRepr[i], out, ",");	// call split function to 
		}
	}
	std::vector<std::string> newout;
	int counter = 4;
	newout = getVector(counter, out);
	for (auto word : newout) {
		std::cout << word << std::endl;
	}*/
	std::vector<std::string> vectorRepr = file_to_vector("routes.dat.txt");
	for (unsigned i = 1; i < 67663; ++i) {
		std::vector<std::string> out;
		size_t n = std::count(vectorRepr[i].begin(), vectorRepr[i].end(), ',');
		if (n == 8) {	// to check if the data satisfy our required format
			split(vectorRepr[i], out, ",");	// call split function to 
			std::cout<< out[0]<<std::endl;
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
}
