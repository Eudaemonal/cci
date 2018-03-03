#include <iostream>
#include <algorithm>
#include <vector>

struct Node{
	int data;
	struct Node* next;	
};


void push(struct Node** head_ref, int new_data){
	struct Node * new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


bool has_cycle(Node* h){
	Node* curr1 = h;
	Node* curr2 = h;
	while(true){
		// increment first iterator
		if(curr1->next!=NULL) curr1 = curr1->next;
		else return false;

		// increment second iterator at twice fast
		if(curr2->next!=NULL) curr2 = curr2->next;
		else return false;
		if(curr2->next!=NULL) curr2 = curr2->next;
		else return false;

		// two iterators reach same place, has cycle
		if(curr1 == curr2) return true;
	}
}


int main(){
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	int n, elem;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::cin >> elem;
		push(&head1, elem);
		push(&head2, elem);
	}
	
	struct Node* curr = head1;
	for(int i = 0; i < n-1; ++i){
		curr = curr ->next;
	}
	
	curr->next = head1;

	
	std::cout << has_cycle(head1) << "\n";
	std::cout << has_cycle(head2) << "\n";

}

