#include <iostream>
#include <chrono>


long fibonacci(unsigned int n){
	if(n < 2) return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	auto start = std::chrono::system_clock::now();
	std::cout << "f(36) = " << fibonacci(36) << "\n";
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> exec_time = end - start;
	std::cout << "elapsed time: " << exec_time.count() << "sec \n";

}
