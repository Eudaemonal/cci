#include <iostream>
#include <vector>

int remove(std::vector<int> v, int elem){
	int cnt = 0;
	for(int i=0; i < v.size(); ++i){
		if(v[i] == elem)
			cnt ++;
		else
			v[i-cnt] = v[i];
	}
	return v.size() -cnt;
}

int main(int argc, char *argv[]){
	int n, elem;
	std::cin >> elem >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}

	std::cout << remove(v, elem) << "\n";
	return 0;
}
