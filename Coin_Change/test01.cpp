#include <iostream>
#include <vector>


int make_change(std::vector<int> coins, int m){
	std::vector<int> table(m+1);
	table[0] = 1;
	for(int i = 0; i< coins.size(); ++i){
		for(int j = coins[i]; j<=m; ++j){
			table[j] +=table[j - coins[i]];
		}
	}
	return table[m];
}

int main(){
	int n,m;
	std::cin >> m >> n;
	std::vector<int> coins(n);
	for(int i = 0; i < n; i++){
		std::cin >> coins[i];
	}
	std::cout << make_change(coins, m) << "\n";
	return 0;
}
