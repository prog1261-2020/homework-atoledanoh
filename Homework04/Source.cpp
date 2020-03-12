/*
* @author  <Alejandro Toledano>
* @version <1.0>
*

* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
*
* @section DESCRIPTION
*  < Object Orientated Programming in C++ homework 04 quicksort function >
*
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2020
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

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
