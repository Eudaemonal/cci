#include <iostream>
#include <vector>
#include <string>

template <typename T>
std::ostream& operator<<(std::ostream &os, std::vector<std::vector<T>> v){
    for(int i=0; i < v.size(); ++i){
        os << "[ ";
        for(int j=0; j < v[0].size(); ++j){
            os << v[i][j] << " ";
        }
        os << "]\n";
    }
    return os;
}


std::vector<std::vector<std::string>> solver(int n){
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> board = {"....", "....","....","...."};
    

    for(int i=0; i < n; ++i){

    }


    ans.push_back(board);
    
    return ans;
}


int main(int argc, char *argv[]){
	int n;
	
	std::cin >> n;

    std::cout << solver(n);

	return 0;
}
