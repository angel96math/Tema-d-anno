#include "sorting.h"
#include <string>

sorting::Sorter::Sorter()
{
    this->to_sort = {};
}

sorting::Sorter::Sorter(vector<int> to_sort)
{
    setVector(to_sort);
}

void sorting::Sorter::setVector(vector<int>to_sort)
{
    this->to_sort = to_sort;
}

vector<int> sorting::Sorter::getVector()
{
    return this->to_sort;
}

void sorting::Sorter::insertionSort()
{
    for (int i = 0; i < this->to_sort.size(); i++) {
        int curr = this->to_sort[i];
        int swap_index = i;
        bool swapped = true;
    }
};