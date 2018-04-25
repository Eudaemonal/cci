#include <iostream>
#include <string>

bool pn(std::string s){
	int i = 0;
	int j = s.length()-1;
	while(i < j){
		if(s.at(i)==s.at(j)){
			i++;
			j--;
		}
		else{
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::string s;
	for(int i=0; i < n; ++i){
		std::cin >> s;
		std::cout << pn(s) << "\n";
	}

	return 0;
}
