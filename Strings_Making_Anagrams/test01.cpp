#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int anagrams(std::string s1, std::string s2){
	int num = 0;
	std::vector<int> freq1(26);
	std::vector<int> freq2(26);
	for(int i = 0; i< s1.length(); ++i){
		freq1[(int)s1.at(i) - 'a'] +=1;
	}
	for(int i = 0; i< s2.length(); ++i){
		freq2[(int)s2.at(i) - 'a'] +=1;
	}
	for(int i = 0; i < 26; ++i){
		num += std::abs(freq1[i] - freq2[i]);
	}

	return num;
}


int main(){
	std::string s1, s2;
	std::cin >> s1;
	std::cin >> s2;

	std::cout << anagrams(s1, s2) << "\n";
	return 0;
}
