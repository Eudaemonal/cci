#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <assert.h>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}


bool unvisited(int from, int to, std::vector<bool> visited){
	for(int i = from; i <= to; ++i){
		if(visited[i]==true)
			return false;
	}
	return true;
}

// modify water level vector
std::vector<int> fill_water(std::vector<int> v, std::vector<std::pair<int, int>> vl){
	int n = vl.size();
	std::vector<int> wl = v;
	std::vector<bool> visited(n);

	// for every pair
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			int from = std::min(vl[i].first, vl[j].first);
			int to = std::max(vl[i].first, vl[j].first);
			int min_level = std::min(vl[i].second, vl[j].second);

			bool fill = true;
			for(int k=from; k < to; ++k){
				if(v[k] > min_level)
					fill = false;
			}
			if(fill && unvisited(from, to, visited)){
				std::cout << "fill water between " << from << " " << to << " with " << min_level << "\n";
				for(int k=from+1; k < to; ++k){
					wl[k] = min_level;
					visited[k] = true;
				}
			}
		
		}
	}
	return wl;
}


int f(std::vector<int> v){
	int n = v.size();

	std::vector<std::pair<int, int>> vl(n);

	for(int i = 0; i < n; ++i){
		vl[i] = std::make_pair(i, v[i]);
	}

	std::sort(vl.begin(), vl.end(), [](const auto &a, const auto &b){
			return a.second > b.second;
		});

	std::vector<int> wl = fill_water(v, vl);

	std::cout << v;
	std::cout << "water level\n";
	std::cout << wl;
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
