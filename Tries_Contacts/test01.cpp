#include <iostream>
#include <list>
#include <string>


class Node{
public:
	Node* next[26];
	bool leaf;
	int total;
	
	// constructor
	Node(){
		for(int i=0; i<26; ++i){
			next[i] = NULL;
		}
		leaf = false;
		total = 0;	
	}
};

Node* head = new Node();

void add(std::string contact){
	int n = contact.size(), i= 0;

	Node* curr = head;

	while(i < n){
		int a = contact[i] - 97;
		if(curr->next[a]==NULL){
			Node* temp = new Node();
			curr -> next[a] = temp;
		}
		curr = curr->next[a];
		curr -> total = curr->total + 1;
		curr->leaf = true;

		i++;
	}
}


int find(std::string contact){
	int n = contact.size(), i=0;
	Node* curr = head;

	while(i < n){
		int a = contact[i] - 97;
		if(curr->next[a] == NULL){
			return 0;
		}
		curr = curr -> next[a];
		i++;
	}
	if(curr == NULL){
		return 0;
	}
	return curr -> total;
}

int main(){
	int n;
	std::cin >> n;
	for(int a0 = 0; a0 < n; a0++){
		std::string op;
		std::string contact;
		std::cin >> op >> contact;
		if(op == "add"){
			add(contact);
		}
		else if(op == "find"){
			std::cout << find(contact) << "\n";
		}
	}
	return 0;
}
