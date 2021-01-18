#include "ioutils.h"
#include "parcing.h"
#include "sorting.h"
#include <iostream>
#include <string>
#include <vector>


using namespace ioutils;
using namespace parcing;
using namespace sorting;

int main() {
	cout << "Enter 'f' to use the text file: " << endl;
	string vector_string;

	if (ioutils::is_file_input()) {
		string login;
		cout << "Place file enter login: " << endl;
		cin >> login;
		std::string vector_string;
		std::string read_file(login);
	}
	else {
		cout << "Place enter array values: " << endl;
		cin >> vector_string;
	}

	vector<int> values;
	try {
		Parser parser(vector_string);
		vector<char> to_remove = { '[', ']', '{', '}' };
		parser.strip_multiple(to_remove);
		values = parser.strip_int_array();
	}
	catch (invalid_argument exc) {
		cout << "Array values format is not valid! Please try again." << endl;
		return 0;
	}

	print_array(values);
	Sorter sort_helper(values);
	print_array(sort_helper.getVector());


	string save;
	cout << "Save results on whit Y" << endl;
	cin >> save;
	if (save == "Y") {
		string login;
		cout << "Please enter login. " << endl;
		cin >> login;
		std::string save_to_file(login);
	}
}