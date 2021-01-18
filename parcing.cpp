#include "parcing.h"
#include <iostream>

parcing::Parser::Parser()
{
	setInput(string());
}

parcing::Parser::Parser(string input)
{
	setInput(input);
}

void parcing::Parser::setInput(string input)
{
	this->input = input;
}

string parcing::Parser::getInput()
{
	return this->input;
}

void parcing::Parser::strip(char to_strip)
{
	string output;
	for (string::iterator it = this->input.begin();
		it != this->input.end();
		++it) {
		if (*it != to_strip) {
			output.append(1, *it);
		}
	}
	setInput(output);
}

void parcing::Parser::strip_multiple(vector<char> to_strip)
{
	for (vector<char>::iterator it = to_strip.begin(); it != to_strip.end(); ++it) {
		strip(*it);
	}
}

vector<int> parcing::Parser::strip_int_array(string delimiter)
{
	int i = 0;
	string helper = this->input;
	string token;
	vector<int> output;
	while ((i = helper.find(delimiter)) != string::npos) {
		token = helper.substr(0, i);
		helper.erase(0, i + delimiter.length());
		output.push_back(stoi(token));
	}
	output.push_back(stoi(helper));
	return vector<int>();
}