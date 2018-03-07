#include <iostream>
#include <string>
#include <vector>

char isSame(std::string str){
	for(int i = str.length() -1; i > 0; i--){
		if(str.at(i)!=str.at(i-1)) return false;
	}
	return true;
}

int reduction(std::string s){
	if(isSame(s)) return s.length();
	std::vector<int> count(3);
	for(int i = s.length()-1; i>=0; i--){
		char c = s.at(i);
		count[c-'a']++;
	}
	if(s.length()%2==0){
		for(int i= 0; i < 3; ++i){
			if(count[i]%2!=0) return 1;
		}
		return 2;
	}else{
		for(int i = 0; i < 3; ++i){
			if(count[i]%2==0) return 1;
		}
		return 2;
	}
}

int main(){
	int n;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::string s;
		std::cin >> s;
		std::cout << reduction(s) << "\n";
	}
}
