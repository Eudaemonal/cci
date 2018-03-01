#include <iostream>

int main(){
	int n, a, result = 0;
	std::cin >> n;
	for(int i = 0; i < n ; ++i){
		std::cin >> a;
		result ^=a;
	}
	std::cout << result << "\n";
	return 0;
}

