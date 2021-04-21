#include <string>

using namespace std;

// adapted from CS 225 Final Project AMA

/** 
 * Reads a file into a string
 * @param filename The file to read from 
 * @return a string containing filename's contents
 */
std::string file_to_string(const std::string & filename);

/** 
 * Reads a file into a vector
 * @param filename The file to read from
 * @return a vector containing filename's contents
 */
std::vector<std::string> file_to_vector(const std::string & filename);


void split(const string& s, vector<string>& tokens, const string& delimiters);

std::vector<std::string> getVector(int counter, std::vector<std::string> origin);
