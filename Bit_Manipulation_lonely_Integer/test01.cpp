#include <iostream>
#include <vector>
#include <algorithm>


int lonely_integer(std::vector<int> v){
	std::vector<int> hash;
	for(int i = 0; i < v.size(); ++i){
		if(hash.size()==0){
			hash.push_back(v[i]);
			continue;
		}

		auto p = std::find(hash.begin(), hash.end(), v[i]);
		if(p==hash.end()) { // not found existing, then push
			hash.push_back(v[i]);
		}
		else{ // has pair, remove
			hash.erase(std::remove(hash.begin(), hash.end(), *p), hash.end());
		}
	}
	return hash[0];	
}

int main(){
	int n, a;
	std::vector<int> arr;
	std::cin >> n;
	for(int i = 0; i < n ; ++i){
		std::cin >> a;
		arr.push_back(a);
	}
	std::cout << lonely_integer(arr) << "\n";
	return 0;
}
