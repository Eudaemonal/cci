#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

class LRUCache{
public:
	LRUCache(int c)
		:capacity(c)
	{}


	int get(int key){
		int ret = -1;
		if(hash.find(key)!=hash.end()){
			ret = hash[key]->first;
			cache.erase(hash[key]);
			hash.erase(key);
						
			cache.push_front(std::make_pair(key, ret));
			hash.emplace(key, cache.begin());
		}
		return ret;
	}

	void put(int key, int value){
		if(cache.size()<capacity){
			cache.push_front(std::make_pair(key, value));
			hash.emplace(key, cache.begin());
		}
		else if(cache.size()==capacity){
			int k = cache.back().first;
			cache.pop_back();
			hash.erase(k);

			cache.push_front(std::make_pair(key, value));
			hash.emplace(key, cache.begin());
		}
	}

private:
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash;
	std::list<std::pair<int, int>> cache;
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

