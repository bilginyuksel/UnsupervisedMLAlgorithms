#ifndef READER
#include <vector>
#include <fstream>
#include <utility>
#include <stdexcept>
#include <sstream>
#include <iostream>


#define READER 
class freader {
public:
	std::vector<std::pair<std::string, std::vector<float>>> read_csv(std::string filename);

	/*
	read from txt files. 
	read from csv files.
	parsing char is comma for default but user can change it
	if he wants so.
	*/
};

#endif