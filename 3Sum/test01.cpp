#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> v){
	for(auto it1: v){
		for(auto it2: it1){
			os << it2 << " ";
		}
		os << "\n";
	}
	return os;
}


std::vector<std::vector<int>> threeSum(std::vector<int> v){
	std::vector<std::vector<int>> res;
	std::sort(v.begin(), v.end());

	for(int i=0; i < v.size(); ++i){
		int target = -v[i];
		int front = i + 1;
		int back = v.size() - 1;
		
		while(front < back){
			int sum = v[front] + v[back];
			if(sum < target)
				front ++;
			else if(sum > target)
				back--;
			else{
				std::vector<int> triplet(3);
				triplet[0] = v[i];
				triplet[1] = v[front];
				triplet[2] = v[back];
				res.push_back(triplet);

				while (front < back && v[front] == triplet[1]) front++;
				while (front < back && v[back] == triplet[2]) back--;
			}
		}
		while(i+1 < v.size() && v[i+1] == v[i])
			i++;
	}
	return res;
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);

	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}

	std::cout << threeSum(v);

	
	return 0;
}
