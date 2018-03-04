#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Player{
	std::string name;
	int score;
};


std::vector<Player> comparator(std::vector<Player> players){
	std::sort(players.begin(), players.end(), [](const Player &a, const Player &b){
		return a.name < b.name;
	});
	std::stable_sort(players.begin(), players.end(), [](const Player &a, const Player &b){		return a.score > b.score;
	});
	return players;
}


int main(){
	int n;
	std::cin >> n;
	std::vector<Player> players;
	std::string name;
	int score;

	for(int i = 0; i < n; ++i){
		std::cin >> name >> score;
		Player p1;
		p1.name = name;
		p1.score = score;
		players.push_back(p1);
	}

	std::vector<Player> answer = comparator(players);
	for(int i = 0; i < answer.size(); ++i){
		std::cout << answer[i].name << " " << answer[i].score << "\n";
	}
	return 0;
}
