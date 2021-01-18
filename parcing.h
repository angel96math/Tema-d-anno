#ifndef PARCING_H
#define PARCING_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

namespace parcing {
	class Parser;
};

class parcing::Parser {

public:
	Parser();
	Parser(string input);
	void setInput(string input);
	string getInput();
	void strip(char to_strip);
	void strip_multiple(vector<char> to_strip);
	vector<int> strip_int_array(string delimiter = ",");

private:
	string input;
};
#endif // !PARCING_H
