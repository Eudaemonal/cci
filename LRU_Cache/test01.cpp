#include <iostream>
#include <vector>
#include <utility>

class LRUCache{
public:
	LRUCache(int c)
		:capacity(c)
	{}


	int get(int key){
		int ret = -1;
		for(int i=0; i < cache.size(); ++i){
			if(cache[i].first==key){
				int k = cache[i].first;
				ret = cache[i].second;
				// record useage
				cache.erase(cache.begin() + i);
				cache.push_back(std::make_pair(k, ret));
			}
		}
		return ret;
	}

	void put(int key, int value){
		if(cache.size()<capacity){
			cache.push_back(std::make_pair(key, value));
		}
		else if(cache.size()==capacity){
			// always remove first value
			cache.erase(cache.begin());
			cache.push_back(std::make_pair(key, value));
		}
	}

private:
	// <key, value>, old - recent
	std::vector<std::pair<int, int>> cache;
	int capacity;
};

int main(int argc, char *argv[]){
	LRUCache c(2);

	c.put(1, 1);
	c.put(2, 2);
	std::cout << c.get(1) << "\n";       // returns 1
	c.put(3, 3);    // evicts key 2
	std::cout << c.get(2) << "\n";       // returns -1 (not found)
	c.put(4, 4);    // evicts key 1
	std::cout << c.get(1) << "\n";       // returns -1 (not found)
	std::cout << c.get(3) << "\n";       // returns 3
	std::cout << c.get(4) << "\n";       // returns 4
	return 0;
}
