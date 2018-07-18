#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(size_t i=0; i < v.size(); ++i){
		for(size_t j=0; j < v[0].size(); ++j){
			os << v[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
		os << v[i] << " ";
	}
	os << "\n";

	return os;
}


std::vector<int> f(std::vector<std::vector<int>> v){
	int n = v.size();
	int m = v[0].size();

	std::vector<int> list;
	int dir = 0;

	int i = 0, j = 0;
	int left = 0, right = n-1;
	int upper = 1, down = m-1;
	for(int k = 0; k < n * m; ++k){
		list.push_back(v[i][j]);
		if(dir==0){
			++j;
			if(j==right){
				dir = (dir+1) % 4;
				right--;
			}
		}else if(dir==1){
			++i;
			if(i==down){
				dir = (dir+1) % 4;
				down--;
			}
		}else if(dir==2){
			--j;
			if(j==left){
				dir = (dir+1) % 4;
				left++;
			}
		}else if(dir==3){
			--i;
			if(i==upper){
				dir = (dir+1) % 4;
				upper++;
			}
		}
	}

	return list;
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	
	std::cout << f(v);
	return 0;
}
