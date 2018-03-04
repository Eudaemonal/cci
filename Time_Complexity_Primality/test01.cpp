#include <iostream>
#include <cmath>

bool is_prime(int elem){
	if(elem<2){
		return false;
	}else if(elem==2){
		return true;
	}else{
		for(int i = 2; i <= sqrt(elem); ++i){
			if(elem % i==0) return false;
		}
		return true;
	}
}


int main(){
	int n, elem;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::cin >> elem;
		if(is_prime(elem)){
			std::cout << "Prime\n";
		}else{
			std::cout << "Not prime\n";
		}
	}
	return 0;
}
