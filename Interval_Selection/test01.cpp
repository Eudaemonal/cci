#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int intervalSelect(std::vector<std::pair<int, int>> v, std::vector<int> x, std::vector<bool> flag){
	std::sort(x.begin(), x.end());

	std::sort(v.begin(), v.end(), [](auto &a, auto &b){
		return a.second < b.second;		
	});

	for(int i = 0; i < v.size(); ++i){
		int count = 0;
		for(int j = 0; j < v.size(); ++j){
			if(flag[j]){
				if(v[j].first <= x[i] && v[j].second >= x[i]){
					count++;
					if(count > 2){
						flag[j] = 0;
					}
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < v.size(); ++i){
		ans+=flag[i];
	}
	return ans;
}




int main(){
	int n_sets, n, a, b;
	std::vector<std::pair<int, int>> list;
	std::vector<int> sec;
	std::vector<bool> flag;
	std::cin >> n_sets;
	for(int s = 0; s < n_sets; ++s){
		std::cin >> n;
		for(int i =0 ; i < n; ++i){	
			std::cin >> a;
			std::cin >> b;
			list.push_back(std::make_pair(a,b));
			sec.push_back(b);
			flag.push_back(1);
		}
		std::cout << intervalSelect(list, sec, flag) << "\n";
		list.clear();
		sec.clear();
		flag.clear();
	}
}
