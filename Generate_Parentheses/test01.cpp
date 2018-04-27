#include <iostream>
#include <vector>
#include <string>

void backtrack(std::vector<std::string> &v, std::string cur, int open, int close, int max){
	if(cur.length() == max*2){
		v.push_back(cur);
		return;
	}
	if(open < max)
		backtrack(v, cur+"(", open+1, close, max);
	if(close < open)
		backtrack(v, cur+")", open, close+1, max);
}


std::vector<std::string> gp(int n){
	std::vector<std::string> v;
	backtrack(v, "", 0, 0, n);
	return v;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	os << "[\n";
	for(auto it: v){
		os << "  "<< it << ",\n";
	}
	os << "]\n";
	return os;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::cout << gp(n);
		
	return 0;
}
