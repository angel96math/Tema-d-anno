#include "ioutils.h"
#include <stdbool.h>
#include <string>
/*
*
* Determines where the input comes from
*
* Returns the mode of the input
*/

bool ioutils::is_file_input()
{
	string input_mode;
	while (1) {
		getline(cin, input_mode);
		//Lenght of the unit input
		if (input_mode.length() == 1)
			//Check validity of the input
		{
			if (input_mode == "f") {
				return true;
			}
			else if (input_mode == "r") {
				return false;
			}
			else {
				cout << "Input is not valid. Please try again" << endl;
				continue;
			}
		}
	}
}

/*
*
* Read the contents of the file ande returns it as a string
*
* @param login
*/

string ioutils::read_file(char* struct_student)
{
	ifstream input(struct_student);
	string vector_string;
	if (input.is_open()) {
		cout << "Reading successful" << endl;
		string line;
		while (getline(input, line)) {
			vector_string.append(line);
		}
	}
	else {
		cout << "Error reading the file" << endl;
	}
	return string();
}

/*
*Print the array on the screen
*
* @param vect vector to be printed on screen
*/

void ioutils::print_array(vector<int> vect)
{
	for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it) {
		cout << *it << "\t";
	}
	cout << endl;
}


/*
*
*Save the contents of teh array to a file
*
* @param login
* @param vect array to save
* @param delimiter
* @param opener opening string
* @param closer closing string
*/

void ioutils::save_to_file(
	char* struct_student,
	vector<int> vect,
	string delimiter,
	string opener,
	string closer)
{
	ofstream output(struct_student);
	if (output.is_open()) {
		if (output.good()) {
			output << opener;
		}
		vector<int>::iterator it = vect.begin();
		while (output.good() && it != vect.end()) {
			output << *it << delimiter;
			++it;
		}
		if (output.good()) {
			output << closer;
		}
	}
}

ioutils::SaveManager::SaveManager(char* struct_student, vector<int> vect, string delimiter, string opener, string closer)
{
	setStruct_student(struct_student);
	setVect(vect);
	setDelimiter(delimiter);
	setOpener(opener);
	setCloser(closer);
}
void ioutils::SaveManager::setStruct_student(char* struct_student)
{
	this->struct_student = struct_student;
}

string ioutils::SaveManager::getStruct_student()
{
	return this->struct_student;
}

void ioutils::SaveManager::setVect(vector<int> vect)
{
	this->vect = vect;
}

vector<int> ioutils::SaveManager::getVect()
{
	return this->vect;
}

void ioutils::SaveManager::setDelimiter(string delimiter)
{
	this->delimiter = delimiter;
}

string ioutils::SaveManager::getDelimiter()
{
	return this->delimiter;
}

void ioutils::SaveManager::setOpener(string opener)
{
	this->opener = opener;
}

string ioutils::SaveManager::getOpener()
{
	return this->opener;
}

void ioutils::SaveManager::setCloser(string closer)
{
	this->closer = closer;
}

string ioutils::SaveManager::getCloser()
{
	return this->closer;
}

void ioutils::SaveManager::save_to_file()
{
	ofstream output(this->struct_student);
	if (output.is_open()) {
		if (output.good()) {
			output << this->opener;
		}
		vector<int>::iterator it = vect.begin();
		while (output.good() && it != vect.end()) {
			output << *it << this->delimiter;
			++it;
		}
		if (output.good()) {
			output << this->closer;
		}
	}
}