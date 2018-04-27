#include <iostream>
#include <string>
#include <vector>

std::string lcp(std::vector<std::string> v){
	int n = v.size();
	int idx = 0;
	char a;
	int i = 0;
	while(1){
		if(i==0)
			a = v[i].at(idx);
		if(v[i].at(idx)==a){
			if(i==n-1){
				idx++;
				i = -1;
			}
		}else{
			break;
		}
		++i;
	}

	return v[0].substr(0, idx);
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}

	std::cout << lcp(v) << "\n";
	
	return 0;
}
