#include <iostream>
#include <vector>


int swap(int &a, int &b){
	static int times = 0;
	int tmp = a;
	a = b;
	b = tmp;
	times++;
	return times;
}


void bubble(std::vector<int> v){
	int times = 0;
	for(int i = 0 ; i < v.size(); ++i){
		for(int j = 0; j < v.size()-1; j++){
			if(v[j] > v[j + 1]){
				times = swap(v[j], v[j + 1]);
			}
		}
	}
	
	std::cout <<"Array is sorted in " << times << " swaps.\n";
	std::cout << "First Element: " << v[0]<< "\n";
	std::cout << "Last Element: " << v[v.size()-1] << "\n";
}



int main(){
	int n;
	std::cin >> n;
	std::vector <int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	bubble(a);
	return 0;
}
