#include <iostream>



int staircase(int stair){
	if(stair <=0){
		return 0;
	}else if(stair==1){
		return 1;
	}else if(stair==2){
		return 2;
	}else if(stair==3){
		return 4;
	}else{
		return staircase(stair-1) + staircase(stair-2) + staircase(stair-3);
	}
}

int main(){
	int n, elem;
	std::cin >> n;
	for(int i = 0; i < n ; ++i){
		std::cin >> elem;
		std::cout << staircase(elem) << "\n";
	}	
}
