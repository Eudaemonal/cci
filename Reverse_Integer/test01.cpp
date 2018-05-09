#include <iostream>

int reverse(int x){
	int res = 0;
	while(x) {
		res = res*10 + x%10;
		x /= 10;
	}
	return (res<INT32_MIN || res>INT32_MAX) ? 0 : res;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	
	std::cout << reverse(n) << "\n";
	
	return 0;
}
