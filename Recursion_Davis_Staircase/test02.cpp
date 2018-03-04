#include <iostream>



int staircase(int stair){
	int prev3 = 0;
	int prev2 = 1;
	int prev1 = 1;

	for(int i = 0; i < stair-1; ++i){
		int current  = prev3 + prev2 + prev1;
		prev3 = prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return prev1;
}

int main(){
	int n, elem;
	std::cin >> n;
	for(int i = 0; i < n ; ++i){
		std::cin >> elem;
		std::cout << staircase(elem) << "\n";
	}	
}
