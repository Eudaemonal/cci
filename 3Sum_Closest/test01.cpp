#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v){
	for(auto it: v){
		os << it << " ";
	}
	os << "\n";
	
	return os;
}


std::vector<int> threeSumClosest(std::vector<int> v, int target){
	std::vector<std::vector<int>> res;
	std::sort(v.begin(), v.end());
	std::vector<int> triplet(3);
	int closest = 0x7fffffff;
	for(int i=0; i < v.size(); ++i){
		int front = i + 1;
		int back = v.size() - 1;

		while(front < back){
			int sum = v[i] + v[front] + v[back];
			if(sum == target){
				triplet[0] = v[i];
				triplet[1] = v[front];
				triplet[2] = v[back];
				return triplet;
			}
			if(abs(sum - target) < abs(closest - target)){
				triplet[0] = v[i];
				triplet[1] = v[front];
				triplet[2] = v[back];
				closest = sum;
			}
			if(sum > target){
				--back;
			}else{
				++front;
			}
		}
	}
	return triplet;
}


int main(int argc, char *argv[]){
	int n, t;
	std::cin >> t;
	std::cin >> n;
	std::vector<int> v(n);

	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}

	std::cout << threeSumClosest(v, t);

	
	return 0;
}

