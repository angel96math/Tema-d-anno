#ifndef SORTING_H
#define SORTING_H
#include <vector>
#include <iostream>

using namespace std;

namespace sorting {
	class Sorter;
}

class sorting::Sorter {

public:
	Sorter();
	Sorter(vector<int> to_sort);
	void setVector(vector<int> to_sort);
	vector<int> getVector();

private:
	vector<int> to_sort;
	vector<int>::iterator it;
	void insertionSort();
	//TODO
	//void mergeSort();
};

#endif // !SORTING_H
