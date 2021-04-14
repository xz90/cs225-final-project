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
    	string      line; //保存读入的每一行
    	while(getline(text,line))//会自动把\n换行符去掉 
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







