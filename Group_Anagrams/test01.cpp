#include <iostream>
#include <vector>
#include <string>
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
	std::vector<bool> visited(n);
	
	std::vector<std::vector<std::string>> out;
	for(int i = 0; i < n; ++i){
		std::vector<std::string> anagram;
		
		if(!visited[i]){
			anagram.push_back(v[i]);
			for(int j = i+1; j < n; ++j){
				if(!visited[i] && !visited[j]){
					if(anagrams(v[i], v[j])){
						visited[j] = true;
						anagram.push_back(v[j]);
					}
				}
			}
			visited[i] = true;
			out.push_back(anagram);

		}
	}

	for(int i=0; i < out.size(); ++i){
		for(auto it: out[i]){
			std::cout << it <<", ";
		}
		std::cout << "\n";
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
