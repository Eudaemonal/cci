#include <iostream>
#include <cmath>


struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr) {}
};


int getNumber(ListNode* l){
	ListNode* curr = l;
	int i=0, num = 0;
	while(curr){
		num+=curr->val*pow(10, i);
		i++;
		curr = curr->next;
	}
	return num;
}


ListNode* getList(int n){
	ListNode* a = new ListNode(n%10);
	ListNode* curr = a;
	while(n>10){
		n = (n - n%10)/10;
		curr->next = new ListNode(n%10);
		curr =curr->next;
	}
	return a;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	int a, b;
	a = getNumber(l1);
	b = getNumber(l2);

	return getList(a+b);
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n;
	std::cin >> m;
	ListNode* a = new ListNode(m);
	ListNode* curr = a;
	for(int i=1; i<n; ++i){
		std::cin >> m;
		curr->next = new ListNode(m);
		curr =curr->next;
	}

	std::cin >> n;
	std::cin >> m;
	ListNode* b = new ListNode(m);

	curr = b;
	for(int i=1; i<n; ++i){
		std::cin >> m;
		curr->next = new ListNode(m);
		curr =curr->next;
	}

	std::cout << getNumber(addTwoNumbers(a, b)) << "\n";
	return 0;
}
