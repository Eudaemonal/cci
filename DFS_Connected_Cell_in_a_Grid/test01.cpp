#include <iostream>

int get_biggest_region(std::vector<std::vector<int>> grid){

}

int main(){
	int n, m;
	std::cin >> n;
	std::cin >> m;

	std::vector<std::vector<int>> grid(n, std::vector<int>(m));

	for(int grid_i = 0; grid_i < n; ++grid_i){
		for(int grid_j =0; grid_j < m; ++grid_j){
			std::cin >> grid[grid_i][grid_j];
		}
	}

	std::cout << get_biggest_region(grid) << "\n";
	return 0;
}
