#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}

int f(std::vector<int> v){
	int n = v.size();
	std::vector<int> dp(n);
	std::fill(dp.begin(), dp.end(), 0x7fffffff);
	for(int i = 0; i < n; ++i){
		if(i==0)
			dp[i] = 0;
		else{
			for(int j = 0; j < i; ++j){
				if(i <= j + v[j] && dp[i] > dp[j] + 1){
					dp[i] = dp[j] + 1;
				}
			}
		}
	}

	
	return dp.back()!=0x7fffffff;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	std::cout << f(v) << "\n";
	return 0;
}
