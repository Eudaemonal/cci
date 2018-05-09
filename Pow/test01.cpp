#include <iostream>
#include <iomanip>

double pow(double x, int n){
	if(n==0)
		return 1;
	if(n < 0){
		n = -n;
		x = 1/x;
	}
	return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
}

int main(int argc, char *argv[]){
	double x;
	int n;
	std::cin >> x;
	std::cin >> n;

	std::cout << std::fixed << std::setprecision(5) <<pow(x, n) << "\n";
	return 0;
}
