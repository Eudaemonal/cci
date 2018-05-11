#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string int2roman(int n){
	std::vector<std::string> M = {"", "M", "MM", "MMM"};
	std::vector<std::string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	std::vector<std::string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	std::vector<std::string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	return M[n/1000] + C[(n%1000)/100] + X[(n%100)/10] + I[n%10];
}

int roman2int(std::string s){
	std::unordered_map<char, int> T ={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

	int n = T[s.back()];
	for(int i = s.length()-2; i>=0; --i){
		if(T[s[i]] < T[s[i+1]]){
			n -= T[s[i]];
		}else{
			n += T[s[i]];
		}
	}
	return n;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	
	std::cout << int2roman(n) << "\n";
	std::cout << roman2int(int2roman(n)) << "\n";

	
	return 0;
}
