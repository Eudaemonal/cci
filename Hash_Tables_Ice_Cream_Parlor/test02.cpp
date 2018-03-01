#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> make_choose(int money, std::vector<int> v){
}

int main(){
	int trip;
	std::cin >> trip;
	for(int t = 0; t < trip; ++t){
		int money, n, elem;
		std::vector<int> v, r;
		std::cin >> money;
		std::cin >> n;
		for(int i = 0; i < n; ++i){
			std::cin >> elem;
			v.push_back(elem);
		}
		r = make_choose(money, v);
		for(int i = 0; i < 2; ++i){
			std::cout << r[i] << " ";
		}
		std::cout << "\n";
	}
}

