#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

class Graph{
public:
	Graph(int n)
		: num_nodes{n}
	{
		adjacency_list.resize(n);
		//std::cout << "num nodes: " << num_nodes << "\n";
	}


	void add_edge(int u, int v){
		u--;
		v--;
		adjacency_list[u].insert(v);
		adjacency_list[v].insert(u);

		//std::cout << "Add Edge: " << u << ", " << v << "\n";
	}

	std::vector<int> shortest_reach(int start){
		start--;

		std::vector<int> v;
		bool visited[num_nodes];
		int distance[num_nodes];
		for(int i = 0; i<num_nodes;++i){
			visited[i] = false;
			distance[i] = 0;
		}

		std::list<int> queue;
		
		queue.push_back(start);

		visited[start] = true;

		while(!queue.empty()){
			int node = queue.front();
			for(auto pos = adjacency_list[node].begin(); pos!=adjacency_list[node].end();++pos){
				if(!visited[*pos]){
					queue.push_back(*pos);
					distance[*pos] += (distance[node] + 6);
					visited[*pos] = true;
				}
			}
			queue.pop_front();
		}

		for(int i = 0; i < num_nodes; i++) {
			//std::cout << i << " dis: "<<distance[i] << "\n";
            if(i != start) {
                if(distance[i] == 0) {
                    v.push_back(-1);
                } else {
                    v.push_back(distance[i]);
                }
            }
        }
        return v;
	}

private:
	std::vector<std::set<int>> adjacency_list;
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
			
			graph.add_edge(u,v);
		}
		int startId;
		std::cin >> startId;

		std::vector<int> distances = graph.shortest_reach(startId);

		for(int i = 0;i< distances.size(); ++i){
				std::cout << distances[i] << " ";
		}
		std::cout << "\n";
		
	}
	return 0;

}
