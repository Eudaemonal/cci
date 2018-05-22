#include <iostream>
#include <string>
#include <stack>

bool isleft(char lhs){
	if(lhs=='(' || lhs=='[' || lhs=='{')
		return true;
	return false;
}

bool isright(char rhs){
	if(rhs==')' || rhs==']' || rhs=='}')
		return true;
	return false;
}

bool ismatch(char lhs, char rhs){
	if(lhs=='(' && rhs==')')
		return true;
	if(lhs=='[' && rhs==']')
		return true;
	if(lhs=='{' && rhs=='}')
		return true;
	return false;
}

bool valid(std::string str){
	std::stack<char> opt;
	for(int i=0; i < str.length(); ++i){
		if(isleft(str[i])){
			opt.push(str[i]);
		}else if(isright(str[i])){
			char lhs = opt.top();
			opt.pop();
			if(!ismatch(lhs, str[i]))
				return false;
		}else{
			return false;
		}
	}
	if(!opt.empty())
		return false;
	
	return true;
}

int main(int argc, char *argv[]){
	int n;
	std::string str;
	std::cin >> n;
	for(int i=0; i < n; ++i){
		std::cin >> str;
		std::cout << valid(str) << '\n';
	}
	return 0;
}
