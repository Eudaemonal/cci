#include <iostream>
#include <string>


bool rem(std::string s, std::string p){
	int n = s.length();
	int m = p.length();
	bool dp[n+1][m+1];
	dp[n][m] = true;
	for(int i = n; i >=0; i--){
		for(int j = m-1; j>=0; j--){
			bool first_match = (i < n && (s.at(i)==p.at(j)||p.at(j)=='.'));
			if(j+1 < m && p.at(j+1)=='*'){
				dp[i][j] = dp[i][j+2] ||( first_match && dp[i+1][j]);
			}
			else{
				dp[i][j] = first_match && dp[i+1][j+1];
			}
		}
	}

	return dp[0][0];
}

int main(int argc, char *argv[]){
	std::string s;
	std::string p;
	std::cin >> s >> p;

	std::cout << rem(s, p) << "\n";
	
	return 0;
}
