#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

std::priority_queue<int> max_heap_left;
std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_right;

void get_median(double x, double &median){
	// case 1 (left side heap has more elements)
	if(max_heap_left.size() > min_heap_right.size()){
		if(x < median){
			min_heap_right.push(max_heap_left.top());
			max_heap_left.pop();
			max_heap_left.push(x);
		}
		else{
			min_heap_right.push(x);
		}
		median = ((double)max_heap_left.top() + (double)min_heap_right.top())/2.0;
	}
	// case 2 (both heaps are balanced)
	else if(max_heap_left.size()==min_heap_right.size()){
		if(x < median){
			max_heap_left.push(x);
			median = (double)max_heap_left.top();
		}
		else{
			min_heap_right.push(x);
			median = (double)min_heap_right.top();
		}
	}
	// case 3 (right side heap has more elements)
	else{
		if(x > median){
			max_heap_left.push(min_heap_right.top());
			min_heap_right.pop();
			min_heap_right.push(x);
		}
		else{
			max_heap_left.push(x);
		}
		median = ((double)max_heap_left.top() + (double)min_heap_right.top())/2.0;

	}

}

int main(){
	int n, m;
	double median=0;
	std::cin >> n;
	for(int a_i = 0; a_i < n; a_i++){
		std::cin >> m;
		get_median(m, median);
		std::cout << std::setprecision(1) << std::fixed << median << "\n";
	}
	return 0;
}
