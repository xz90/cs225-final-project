#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cctype>

//#include <boost/algorithm/string/split.hpp>
//#include <boost/algorithm/string/classification.hpp>
//#include <boost>

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
    	string      line; //保存读入的每一行
    	//while(getline(text,line))//会自动把\n换行符去掉 
		while(getline(text,line, ','))//会自动把\n换行符去掉 
    	{
        	out.push_back(line);  
    	}
		/*while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}*/
	}

	return out;
} 

std::vector<std::string> line_split(std::vector<std::string> vec, int position) {
	std::vector<std::string> out;
	int counter = position;
	int i = 0;
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it, ++i) {
		if (counter == i) {
			counter += 13;
			if (*it != "\\N") {
				out.push_back(*it);
			}
		}
	}
	return out;
}





