#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}


int f(std::vector<int> v){
	int n = v.size();
	std::vector<int> wl_right(n);
	std::vector<int> wl_left(n);
	std::vector<int> wl(n);

	int max = 0;
	for(int i=0; i < n; ++i){
		max = std::max(v[i], max);
		wl_right[i] = max;
	}
	max = 0;
	for(int i=n-1; i >=0; --i){
		max = std::max(v[i], max);
		wl_left[i] = max;
	}
	for(int i=0; i < n; ++i){
		wl[i] = std::min(wl_right[i], wl_left[i]);
	}
	int sum = 0;
	for(int i=0; i < n; ++i){
		assert(wl[i]-v[i]>=0);
		sum += wl[i] - v[i];
	}

	return sum;
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	std::cout << f(v) << "\n";
	return 0;
}
