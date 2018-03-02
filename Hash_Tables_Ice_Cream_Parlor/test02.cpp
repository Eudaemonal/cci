#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


int main(){
	int trip;
	std::cin >> trip;
	for(int t = 0; t < trip; ++t){
		int money, n, elem;
		std::vector<int> v, r;
		std::cin >> money;
		std::cin >> n;

		std::map<int, std::vector<int>> price;
		for(int i = 0; i < n; ++i){
			int flavor;
			std::cin >> flavor;
			if(flavor >= money){
				continue;
			}
			if(price.count(flavor) == 0){
				price[flavor] = std::vector<int>(1,i);
			}
			else{
				price[flavor].push_back(i);
			}
		}
		int half = money / 2;
		auto middle = price.lower_bound(half);
		auto bottom = price.begin();
		auto top = price.upper_bound(half);
		int one;
		int two;
		if(2*half == money && middle->first == half && middle->second.size() >=2)
		{
			one = middle->second[0];
			two = middle->second[1];
		}else{
			while(bottom!=middle && top!=price.end()){
				bottom = price.lower_bound(money - top->first);
				if(bottom->first + top->first == money)
					break;
				else if(bottom!=price.begin())
					bottom--;

				top = price.lower_bound(money - bottom->first);
				if(bottom->first + top->first == money)
					break;
			}
			one = bottom->second[0];
			two = top->second[0];
		}

		one++;
		two++;
		if(one < two){
			std::cout << one << " " << two << "\n";
		}else{
			std::cout << two << " " << one << "\n";
		}


	}
}

