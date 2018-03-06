#include <iostream>
#include <vector>

static long count = 0;

std::vector<int> merge(std::vector<int> left, std::vector<int> right){
	int totalLength = left.size() + right.size();
	std::vector<int> result(totalLength);
	int currentIndex = 0;
	int leftIndex = 0;
	int rightIndex = 0;

	while(leftIndex < left.size() && rightIndex < right.size()){
		if(right[rightIndex] < left[leftIndex]){
			result[currentIndex] = right[rightIndex];
			count += left.size() - leftIndex;
			rightIndex++;
		}else{
			result[currentIndex] = left[leftIndex];
			leftIndex++;
		}
		currentIndex++;
	}
	while(leftIndex < left.size()){
		result[currentIndex] = left[leftIndex];
		leftIndex ++;
		currentIndex++;
	}
	while(rightIndex < right.size()){
		result[currentIndex] = right[rightIndex];
		rightIndex++;
		currentIndex++;
	}
	return result;
}



std::vector<int> merge_sort(std::vector<int> arr){
	if(arr.size()==0 || arr.size()==1){
		return arr;
	}
	int half = arr.size()/2;

	std::vector<int> leftSide(half);
	std::vector<int> rightSide(arr.size() - half);

	for(int i = 0; i < half; ++i){
		leftSide[i] = arr[i];
	}
	for(int i = half; i < arr.size(); ++i){
		rightSide[i-half] = arr[i];
	}
	leftSide = merge_sort(leftSide);
	rightSide = merge_sort(rightSide);
	std::vector<int> result = merge(leftSide, rightSide);

	return result;
}


int main(){
	int t;
	std::cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		std::cin >> n;
		std::vector<int> arr(n);
		for(int i = 0; i < n; ++i){
			std::cin >> arr[i];
		}
		merge_sort(arr);
		std::cout << count << "\n";
		count = 0;
	}
	return 0;
}
