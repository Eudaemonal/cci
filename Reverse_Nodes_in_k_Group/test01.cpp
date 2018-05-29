#include <iostream>
#include <stack>

template <class T> class Node;
template <class T> class List;

template <class T>
class Node{
public:
	Node(T v)
		:val(v), next(nullptr)
	{}

	friend class List<T>;


	template <class U>
	Node<U>* reverseKGroup(Node<U> *head, int k);

	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const List<U>& l);

private:
	T val;
	Node<T> *next;
};

template <class T>
class List{
public:
	List()
		:head(nullptr)
	{}

	void insert(T v){
		if(head == nullptr){
			Node<T> *n = new Node<T>(v);
			head = n;
		}else{
			Node<T> *curr = head;
			while(curr->next)
				curr = curr->next;
			curr->next = new Node<T>(v);
		}
	}
	
	void reverseKGroup(int k){
		if(!head) return;
		std::stack<Node<T>*> s;
		int m = k;
		int num = 0;
		Node<T> *p = head;
		Node<T> dummy(0);
		Node<T> *prev = &dummy;
		while(p){
			++num;
			p = p->next;
		}
		p = head;
		while(num >=k){
			m = k;
			while(m--){
				s.push(p);
				p = p->next;
			}
			m = k;
			while(m--){
				prev->next = s.top();
				s.pop();
				prev =prev->next;
				prev->next = nullptr;
			}
			num-=k;
		}
		if(p) prev->next = p;
		head = dummy.next;
	}
	
	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const List<U>& l);
	

private:
	Node<T> *head;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l){
	Node<T> *curr = l.head;
	while(curr){
		os << curr->val << " ";
		curr = curr->next;
	}
	os << "\n";
	return os;
}



int main(int argc, char *argv[]){
	List<int> l;

	int n, e, k;
	std::cin >> k;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::cin >> e;
		l.insert(e);
	}
	
	l.reverseKGroup(k);

	std::cout << l;

	return 0;
}


