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
// split string by delimiters
// Reference: https://stackoverflow.com/questions/26328793/how-to-split-string-with-delimiter-using-c
void split(const string& s, vector<string>& tokens, const string& delimiters)
{
        string::size_type lastPos = s.find_first_not_of(delimiters, 0);
        string::size_type pos = s.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos) {
                tokens.push_back(s.substr(lastPos, pos - lastPos));
                lastPos = s.find_first_not_of(delimiters, pos);
                pos = s.find_first_of(delimiters, lastPos);
        }
}

std::vector<std::string> getVector(int counter, std::vector<std::string> origin) {
	std::vector<std::string> res;
	int i = 0;
	for (std::vector<std::string>::iterator it = origin.begin(); it != origin.end(); ++it, ++i) {
		if (counter == i) {
			counter += 14;
			//if (*it != "\\N" && *it != "\"\"") {
				res.push_back(*it);
			//}
		}
	}
	return res;
}