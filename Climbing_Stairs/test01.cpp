#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream& os, const std::vector<T> &v){
	for(auto it: v){
		os << it << " ";
	}
	os<< "\n";
	return os;
}


int f1(int i, int n){
	if(i>n)
		return 0;
	if(i==n)
		return 1;
	
	return f1(i+1, n) + f1(i+2, n);
}

int f2(int n){
	std::vector<int> dp(n+1);
	for(int i=0; i <= n; ++i){
		if(i==1)
			dp[i] = 1;
		if(i==2)
			dp[i] = 2;
		if(i>2)
			dp[i] = dp[i-1] + dp[i-2];
	}
	return dp.back();
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;

	std::cout << f2( n)<<"\n";
	return 0;
}
