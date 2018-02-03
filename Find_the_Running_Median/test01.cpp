#include <iostream>
#include <iomanip>
#include <vector>

// O(n)^2


std::vector<int> a;

void insert(int num){
	if(a.size() == 0){
		a.push_back(num);
	}
	else{
		
		int i =0;
		auto it = a.cbegin();
		while(num > *it && it!=a.cend())
			++it;
		a.emplace(it, num);
		
	}
}

void get_median(){
	std::cout << std::setprecision(1) << std::fixed;
	if(a.size() == 0)
		return;
	else if(a.size()%2==1){

		std::cout << (double)a.at(a.size()/2) << "\n";
	}
	else{
		std::cout << (double)(a.at(a.size()/2-1) + a.at(a.size()/2))/2 << "\n";
	}
	
}

int main(){
	int n, m;
	std::cin >> n;
	for(int a_i = 0; a_i < n; a_i++){
		std::cin >> m;
		insert(m);
		get_median();
	}
	return 0;
}
