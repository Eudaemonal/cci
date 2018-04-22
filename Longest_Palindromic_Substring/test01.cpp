#include <iostream>
#include <string>


int expendAroundCenter(std::string s, int left, int right){
	int l = left;
	int r = right;
	while(l >=0 && r <s.length() && s.at(l)==s.at(r)){
		l--;
		r++;
	}
	return r - l - 1;
}


std::string lps(std::string s){
	int start =0, end = 0, mlen;
	for(int i=0; i < s.length(); ++i){
		int len1 = expendAroundCenter(s, i, i);
		int len2 = expendAroundCenter(s, i, i+1);
		int len = std::max(len1, len2);
		if(len > end - start){
			start = i - (len -1)/2;
			end = i + len/2;
			mlen = len;
		}
	}
	return s.substr(start, mlen);
}

int main(int argc, char *argv[]){
	std::string s;
	std::cin >> s;
	
	std::cout << lps(s) << "\n";
	return 0;
}
