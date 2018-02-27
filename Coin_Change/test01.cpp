#include <iostream>
#include <vector>


int make_change(std::vector<int> coins, int m, int n){
	std::vector<int> table(n+1);
	table[0] = 1;
	for(int i = 0; i< m; ++i){
		for(int j = coins[i]; j<=n; ++j){
			table[j] +=table[j - coins[i]];
		}
	}
	return table[n];
}

int main(){
	int n,m;
	std::cin >> n >> m;
	std::vector<int> coins(m);
	for(int coins_i = 0; coins_i < m; coins_i++){
		std::cin >> coins[coins_i];
	}
	std::cout << make_change(coins,m, n) << "\n";
	return 0;
}
