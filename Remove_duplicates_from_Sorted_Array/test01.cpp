#include <iostream>
#include <vector>

int rd(std::vector<int> v){
	int n = v.size();
	if(n==0) return 0;
	int i = 0;
	for(int j=1; j < n; ++j){
		if(v[j]!=v[i]){
			i++;
			v[i] = v[j];
		}
	}
	return i + 1;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}

	std::cout << rd(v) << "\n";
	
	return 0;
}
