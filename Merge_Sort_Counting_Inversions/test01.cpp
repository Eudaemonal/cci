#include <iostream>
#include <vector>

long long count_inversions(std::vector<int> arr){
	long long count = 0;
	for(int i = 0; i < arr.size()-1; ++i){
		for(int j = i + 1; j < arr.size(); ++j){
			if(arr[i] > arr[j]){
				count ++;
			}
		}
	}
	return count; 
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
		std::cout << count_inversions(arr) << "\n";
	}
	return 0;
}
