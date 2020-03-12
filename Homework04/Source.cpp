#include <vector>

//quick sort function

int partition(std::vector<int>& vec, int low, int high) {

	int pivot = vec.at(high);								//pivot
	int start = low;										//index - smaller element
	for (int i = low; i < high; i++) {
		if (vec.at(i) <= pivot) {							//if current element is smaller than or equal to pivot
			start++;										//increment smaller element
			std::swap(vec.at(i), vec.at(start));
		}
	}
	std::swap(vec.at(start), vec.at(high));					//swap the piv with element at partition index
	return start;
}

void quickSort(std::vector<int>& vec, int low, int high) {
	if (low < high) {
		int loc = partition(vec, low, high);				//calling partition function
		quickSort(vec, low, loc - 1);						//actual sorting
		quickSort(vec, loc + 1, high);
	}
}
