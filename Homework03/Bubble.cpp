//bubble Sort
void bubbleSort(std::vector<int> nums) {

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i{ 0 }; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				std::swap(nums[i], nums[i + 1]);
				flag = true;
			}
		}
	}

	for (auto it : nums) {
		std::cout << it << " ";
	}
}