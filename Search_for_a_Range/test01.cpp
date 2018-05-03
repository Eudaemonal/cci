#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}

int f(int t, std::vector<int> v, bool left){
	int lo = 0;
	int hi = v.size();

	while(lo < hi){
		int mid = (lo + hi)/2;
		if(v[mid] > t || (left && t == v[mid])){
			hi = mid;
		}else{
			lo = mid + 1;
		}			
	}
	return lo;
}

std::vector<int> searchRange(int t, std::vector<int> v){
	std::vector<int> range = {-1, -1};

	int left_index =  f(t, v, true);
	if (left_index == v.size() || v[left_index] != t){
		return range;
	}

        range[0] = left_index;
        range[1] = f(t, v, false)-1;

	return range;
}

int main(int argc, char *argv[]){
	int t, n;
	std::cin >>t >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	std::vector<int> range = searchRange(t, v);
	std::cout << range;
	return 0;
}
