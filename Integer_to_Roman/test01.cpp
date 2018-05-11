#include <iostream>
#include <vector>
#include <string>

std::string convert(int n){
	std::vector<std::string> M = {"", "M", "MM", "MMM"};
	std::vector<std::string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	std::vector<std::string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	std::vector<std::string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	return M[n/1000] + C[(n%1000)/100] + X[(n%100)/10] + I[n%10];
}



int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	
	std::cout << convert(n) << "\n";

	return 0;
}
