#include <iostream>
#include <vector>


class Graph{
public:
	Graph(int n)
		: num_nodes{n};


	void add_edge(int u, int v){
		auto p = std::make_pair(u,v);
		list.push_back(p);
	}

	std::vector<int> shortest_reach(int start){
		int i = 0;
		while(i < num_nodes){
			
			
		}
	}
private:
	std::vector<std::pair<int, int>> list;
	int num_nodes;
};

int main(){
	int queries;
	std::cin >> queries;

	for(int t = 0; t < queries; ++t){
		int n, m;
		
		std::cin >> n;
		Graph graph(n);

		std::cin >> m;

		for(int i = 0; i < m; ++i){
			int u, v;
			std::cin >> u >> v;
			u--; v--;
			graph.add_edge(u,v);
		}
		int startId;
		std::cin >> startId;
		startId--;

		std::vector<int> distances = graph.shortest_reach(startId);

		for(int i = 0;i< distances.size(); ++i){
			if(i!=startId){
				std::cout << distancs[i] << " ";
			}
		}
		std::cout << "\n";
		
	}
	return 0;

}
