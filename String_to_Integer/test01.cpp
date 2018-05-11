#include <iostream>
#include <string>
#include <algorithm>

int atoi(std::string str){
	int indicator = 1;
	long num;
	// remove whitespace
	remove_if(str.begin(), str.end(), isspace);
	
	// check first character and convert
	int i = 0;
	if(str[i] == '-' || str[i] == '+'){
		indicator = (str[i++] == '-')? -1 : 1;
	}
	if(str[i]<'0'||str[i]>'9')
		return 0;

	num = int(str[i]-'0');
	i++;
	while(str[i]>='0'&& str[i]<='9'){
		num = num*10 + int(str[i]-'0');
		if(num*indicator >= INT32_MAX) return INT32_MAX;
		if(num*indicator <= INT32_MIN) return INT32_MIN;
		i++;
	}
	return int(num*indicator);
}

int main(int argc, char *argv[]){
	std::string s;

	std::cin >> s;
	
	std::cout << atoi(s) << "\n";
	return 0;
}
