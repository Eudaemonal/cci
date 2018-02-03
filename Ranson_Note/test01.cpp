#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>



std::unordered_map<std::string,int>::iterator it;

// Put every word from the magazine in a hash table, check if every word from the ransom is in the hash table
bool ransom_note(std::vector<std::string> magazine, std::vector<std::string> ransom){
    std::unordered_map<std::string, int> map;
    for(int i = 0; i < magazine.size(); i++) {
    	it = map.find(magazine[i]);
    	if(it == map.end()) {
    		map.insert(std::pair<std::string, int>(magazine[i], 1));
    	} else {
    		map[magazine[i]]++;
    	}
    }
    for(int i = 0; i < ransom.size(); i++) {
    	it = map.find(ransom[i]);
    	if(it == map.end()) {
    		return false;
    	} else if(it->second == 0) {
			return false;
    	}
    	map[ransom[i]]--;
    }
    return true;
}

int main(){
    int m;
    int n;
    std::cin >> m >> n;
    std::vector<std::string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       std::cin >> magazine[magazine_i];
    }
    std::vector<std::string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       std::cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    return 0;
}
