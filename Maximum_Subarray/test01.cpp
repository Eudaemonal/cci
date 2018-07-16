#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	for(auto it: v){
		os << it << " ";
	}
	os << "\n";
	return os;
}

std::vector<int> max_subarr(std::vector<int> v){
	int start, end;
	int sum = 0;
	int sum_so_far = 0;
	for(int i = 0; i < v.size(); ++i){
		sum = v[i] + sum;
		if(sum < 0){
			sum = 0;
			start = i + 1;
		}

		if(sum > sum_so_far){
			sum_so_far = sum;
			end = i + 1;
		}
	}
	std::cout << sum_so_far << "\n";
	std::vector<int>::const_iterator first = v.begin() + start;
	std::vector<int>::const_iterator last = v.begin() + end;
	std::vector<int> vec(first, last);
	return vec;
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;

	std::vector<int> v(n);

	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}

	std::cout << max_subarr(v);
	return 0;
}
