#include <iostream>
#include <vector>



int merge(std::vector<int> arr, std::vector<int> temp, int start, int mid, int end){
	int count  =0;
	for(int i = start; i <=end; ++i){
		temp[i] = arr[i];
	}
	int curr = start;
	int left = start;
	int right = mid + 1;
	while(left <= mid && right <=end){
		if(temp[left]<=temp[right]){
			arr[curr++] = temp[left++];
		}else{
			count += mid - left + 1;
			arr[curr++] = temp[right++];
		}
	}
	while(left <= mid){
		arr[curr++] =temp[left++];
	}
	return count;
}



int merge_sort(std::vector<int> arr, std::vector<int> temp, int start, int end){
	int mid, count = 0;

	if(end > start){
		mid = (start+ end)/2;
		count = merge_sort(arr, temp, start, mid);
		count += merge_sort(arr, temp, mid+1, end);
		count += merge(arr, temp, start, mid, end);
	}

	return count;
}



int count_inversions(std::vector<int> arr){
	std::vector<int> temp(arr.size());
	return merge_sort(arr, temp, 0, arr.size()-1);
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
