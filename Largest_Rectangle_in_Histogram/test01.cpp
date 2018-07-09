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

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(size_t i=0; i < v.size(); ++i){
		for(size_t j=0; j < v[0].size(); ++j){
			os << v[i][j] << " ";
		}
		os << "\n";
	}
	os << "\n";
	return os;
}


int min_elem(int start, int end, std::vector<int> v){
	int min = 0x7fffffff;
	for(int i=start; i < end; ++i){
		if(v[i] < min)
			min = v[i];
	}
	return min;
}

int f(std::vector<int> v){
	int n = v.size();
	int max_area = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j <= n; ++j){
			int h = min_elem(i, j, v);
			if((j-i) * h > max_area)
				max_area = (j-i) * h;
		}
	}
	return max_area;
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
