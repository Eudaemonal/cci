#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}

// true if s1 and s2 are anagrams
bool anagrams(std::string s1, std::string s2){
	if(s1.length()!=s2.length())
		return false;

	std::map<char, int> m;
	for(int i=0; i < s1.length(); ++i){
		m[s1.at(i)] +=1;
		m[s2.at(i)] -=1;
	}

	for(auto it : m){
		if(it.second!=0)
			return false;
	}

	return true;
	
}


void f(std::vector<std::string> v){
	int n = v.size();
	
	std::map<int, std::vector<std::string>> m;
	for(int i = 0; i < n; ++i){
		int key = 0;
		for(int j=0; j < v[i].length(); ++j){
			key |= 1 << (v[i].at(j)-'a');
		}
		m[key].push_back(v[i]);

	}
	// print result
	for(auto it=m.begin(); it!=m.end(); ++it){
		std::cout << it->second;
	}

}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	f(v);
	return 0;
}


