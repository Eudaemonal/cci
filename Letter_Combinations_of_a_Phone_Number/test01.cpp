#include <iostream>
#include <vector>
#include <string>
#include <map>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	for(auto it: v)
		os << it << " ";
	os << "\n";
	return os;
}


std::vector<std::string> combination(std::string str){
	std::vector<std::string> result;
	result.push_back("");
	if(str.empty()) return result;
	static const std::vector<std::string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	for(int i=0; i < str.length(); ++i){
		int num = str.at(i)-'0';
		if(num < 0 || num > 9) break;
		std::string candidate = v[num];
		if(candidate.empty()) continue;
		std::vector<std::string> tmp;
		for(int j=0; j < candidate.length(); ++j){
			for(int k=0; k < result.size(); ++k){
				tmp.push_back(result[k] + candidate[j]);
			}
		}
		result.swap(tmp);
	}
	return result;
}


int main(int argc, char *argv[]){
	std::string number;
	std::cin >> number;
	
	std::cout << combination(number);
	return 0;
}
