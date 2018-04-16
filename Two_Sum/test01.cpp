#include <iostream>
#include <vector>
#include <map>

// brute force approach O(n^2)
std::vector<int> twoSum1(int s, std::vector<int> v){
	std::vector<int> result;
	for(int i=0; i<v.size(); ++i){
		for(int j=i+1; j<v.size(); ++j){
			if(v[j] == s - v[i]){
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
	return result;
}

// two pass hash table approach O(n)
std::vector<int> twoSum2(int s, std::vector<int> v){
	std::map<int, int> m;
	std::vector<int> result;
	for(int i=0; i<v.size();++i){
		m.emplace(v[i], i);
	}

	for(int i=0; i< v.size(); ++i){
		int complement = s - v[i];
		if(m.at(complement) && m.at(complement)!=i){
			result.push_back(i);
			result.push_back(m.at(complement));
			return result;
		}
	}
	return result;
}

// one pass hash table approach O(n)
std::vector<int> twoSum3(int s, std::vector<int> v){
	std::map<int, int> m;
	std::vector<int> result;
	for(int i=0; i< v.size(); ++i){
		int complement = s - v[i];
		if(m.at(complement)){
			result.push_back(i);
			result.push_back(m.at(complement));
			return result;
		}
		m.emplace(v[i], i);
	}
	return result;
}



int main(int argc, char *argv[]){
	int s, n;
	std::cin >> s >> n;
	std::vector<int> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}
	std::vector<int> r;
	r= twoSum2(s, v);
	for(auto it: r)
		std::cout << it << " ";
	std::cout << "\n";
	
	return 0;
}
