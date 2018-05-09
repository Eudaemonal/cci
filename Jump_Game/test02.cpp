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

int f(std::vector<int> v){
	int n = v.size();
	int lastPos = n-1;
	for(int i=n; i >=0; --i){
		if(i + v[i] >= lastPos)
			lastPos = i;
	}
	return lastPos==0;
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

