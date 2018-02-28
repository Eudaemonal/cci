#include <iostream>
#include <vector>


int visit(std::vector<std::vector<int>> &grid, int i, int j, int n, int m){
	if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
		return 0;
        }
	static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	grid[i][j] = 0;
	int size = 1;
	for(int k = 0; k < 8; ++k){
		size += visit(grid, i + rowNbr[k], j + colNbr[k], n,m);
	}
	return size;
}

int get_biggest_region(std::vector<std::vector<int>> grid, int n, int m){
		
	int maxSize = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(grid[i][j]){
				int size = visit(grid, i, j, n, m);
				if(size > maxSize){
					maxSize = size;
				}
			}
		}
	}
	
	return maxSize;
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

	std::cout << get_biggest_region(grid, n, m) << "\n";
	return 0;
}
