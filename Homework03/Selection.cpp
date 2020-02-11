//selection sort

std::vector<int> SelectionSort(std::vector<int>& vec)
{
	int n = vec.size();
	while (n > 0) {
		for (int i{ 0 }; i < n; i++) {
			auto minEl = std::min_element(vec.begin(), vec.begin() + n);
			if (vec.at(i) == *minEl) {
				vec.emplace_back(*minEl);
				vec.erase(vec.begin() + i);
				n--;
			}
		}
	}
	return vec;
}