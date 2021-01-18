#ifndef IOUTILS_H
#define IOUTILS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

namespace ioutils {
	bool is_file_input();
	string read_file(char* struct_student);
	void print_array(vector<int> vect);
	class SaveManager;
	void save_to_file(
		char* struct_student,
		vector<int> vect,
		string delimiter = ",",
		string opener = "[",
		string closer = "]");
}

class ioutils::SaveManager {

private:
	char* struct_student;
	vector<int> vect;
	string delimiter;
	string opener;
	string closer;

public:
	SaveManager(char* struct_student, vector<int> vect, string delimiter = ",", string opener = "[", string closer = "]");
	void setStruct_student(char* struct_student);
	string getStruct_student();
	void setVect(vector<int> vect);
	vector<int> getVect();
	void setDelimiter(string delimiter);
	string getDelimiter();
	void setOpener(string opener);
	string getOpener();
	void setCloser(string closer);
	string getCloser();
	void save_to_file();
};

#endif // !IOUTILS_H
