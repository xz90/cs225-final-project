#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<std::string> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;

	if (text.is_open()) {
		// stream: continuous
		std::istream_iterator<std::string> iter(text);

		while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}
	}

	return out;
} 

void filter_blank_spaces(ifstream & in_stream, ofstream & out_stream) {
	char next;
	in_stream.get(next);

	do
	{
		if (isspace(next)) {
			out_stream << ' ';
		} else {
			out_stream << next;
		}
		in_stream.get(next);
	} while (! in_stream.get(next));
	
	
}






