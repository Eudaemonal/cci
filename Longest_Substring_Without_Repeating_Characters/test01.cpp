#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s){
	std::unordered_set<char> set;
	int ans = 0, i=0, j=0;
	while(i < s.length() && j < s.length()){
		if(!set.count(s.at(j))){
			set.emplace(s.at(j++));
			ans = std::max(ans, j-i);
		}else{
			set.erase(s.at(i++));
		}
	}
	return ans;
}

int main(int argc, char *argv[]){
	std::string s;
	std::cin >> s;
	
	std::cout << lengthOfLongestSubstring(s) << "\n";

	return 0;
}
