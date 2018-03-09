#include <iostream>
#include <vector>
#include <stack>
#include <climits>


class Graph{
public:
	Graph(int _n,int _k)
		:n(_n), k(_k)
	{
		direction.resize(n);
		marked.resize(n);
		pathLength.resize(n);
		s.resize(n);
		objectArray.resize(n);
		for(int i = 0; i < n; ++i){
			direction[i].resize(n);
			pathLength[i].resize(n);
		}
	}

	void add(int a, int b){
		direction[a-1][b-1]=1;
		direction[b-1][a-1]=1;
	}

	int getMax(){
		getMaxPathLength();
		int max, pos, counter=0;
		int objectSize = 0;
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j){
				if(pathLength[i][j]>k){
					objectSize+=2;
					objectArray[i]++;
					objectArray[j]++;
					s[i].push(j);
					s[j].push(i);
				}
			}
		}


		while(objectSize > 0){
			max = -1;
			pos = 0;
			for(int i=0; i < n; ++i){
				if(objectArray[i] > max){
					max = objectArray[i];
					pos = i;
				}
			}
			counter++;
			while(!s[pos].empty()){
				int val = s[pos].top();
				s[pos].pop();
				objectArray[val]--;
			}
			objectSize = objectSize - 2*objectArray[pos];
			objectArray[pos] = 0;
		}
		return counter;
	}

	void getMaxPathLength(){
		int maxPathLength;
		for(int i = 0; i < marked.size(); ++i){
			marked[i] = true;
			for(int j=i+1; j < marked.size(); ++j){
				maxPathLength = getMaxPathLength(i,j);
				if(maxPathLength < 0){
					maxPathLength = 0;
				}
				pathLength[i][j] = maxPathLength;
				pathLength[j][i] = maxPathLength;
			}
			marked[i] = false;
		}
	}

	int getMaxPathLength(int start, int end){
		if(direction[start][end]!=0){
			return 1;
		}
		int max, ans = INT_MIN;
		for(int i =0; i < marked.size(); ++i){
			if(!marked[i]){
				if(direction[start][i] > 0){
					marked[i] = true;
					max = getMaxPathLength(i, end);
					marked[i] = false;
					if(max > ans){
						ans = max;
					}
				}
			}
		}
		return ans + 1;
	}

private:
	std::vector<std::vector<int>> direction;
	std::vector<bool> marked;
	std::vector<std::vector<int>> pathLength;
	std::vector<std::stack<int>> s;
	std::vector<int> objectArray;
	int n, k;
};


int main(){
	int N, K;
	std::cin >> N >> K;
	Graph g(N, K);
	for(int i = 0; i < N-1; ++i){
		int a, b;
		std::cin >> a >> b;
		g.add(a, b);
	}
	std::cout << g.getMax() << "\n";
}
