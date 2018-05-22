#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(size_t i=0; i < v.size(); ++i){
		for(auto it: v[i])
			os << it << " ";
		os << "\n";
	}
	return os;
}



std::vector<std::vector<int>> four_sum(std::vector<int> v, int target){
	int n = v.size();
	std::sort(v.begin(), v.end());
	std::vector<std::vector<int>> res;
	for(int i = 0; i < n-3; ++i){
		int result = target - v[i];
		int index = i + 1;
		while(index < n-2){
			int start = index + 1;
			int end = n - 1;
			
			while(start < end){
				int sum = v[index] + v[start] + v[end];
				if(sum < result){
					start++;
				}else if(sum > result){
					end--;
				}else{
					res.push_back(std::vector<int>{v[i], v[index], v[start], v[end]});
					do{start++;}while(v[start]==v[start-1]&&start<end);
					do{end--;}while(v[end]==v[end+1]&&start<end);
				}
			}
			
			index++;
		}
		
	}
	return res;
}

int main(int argc, char *argv[]){
	int n, t;
	std::cin >> t;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	std::cout << four_sum(v, t);
	return 0;
}
