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
	
	std::cout << vectorRepr[0] << std::endl;
	std::cout << vectorRepr[1] << std::endl;
	std::cout << vectorRepr[2] << std::endl;
	std::cout << vectorRepr[3] << std::endl;
	std::cout << vectorRepr[4] << std::endl;
	/*
	for (auto word : vectorRepr) {
		std::cout << word << std::endl;
	}
	*/

	// Remove space in our data
	ifstream fin("airports.dat.txt");
	ofstream fout("airports.out.txt");

	if (fin.fail()) {
		cout << "Input file cound not be opened. \n";
		exit(1);
	}

	fout.open("airports.out.txt");

	if (fout.fail()) {
		cout << "Output file cound not be opened. \n";
		exit(1);
	}

	filter_blank_spaces(fin, fout);
	fin.close();
	fout.close();
	cout << "Done.\n";

	std::cout << "Vector Representation:" << std::endl;
	std::vector<std::string> vectorRepr2 = file_to_vector("airports.out.txt");
	
	std::cout << vectorRepr2[0] << std::endl;
	std::cout << vectorRepr2[1] << std::endl;
	std::cout << vectorRepr2[2] << std::endl;

	return 0;
	
}
