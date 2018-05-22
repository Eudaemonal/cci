#include <iostream>

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
	~List(){
		Node<T> *curr = head;
		Node<T> *prev;
		while(curr->next){
			prev = curr;
			delete prev;
			curr = curr->next;
		}
	}

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

	void rm_node_from_end(int n){
		Node<T> *curr = head;
		Node<T> *cdel = head;
		Node<T> *pdel;
		int count = 0;
		while(curr){
			if(count == n){
				cdel = head;
			}
			count++;
			pdel = cdel;
			cdel = cdel->next;
			curr = curr->next;
		}
		pdel->next = cdel->next;
		delete cdel;
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

	int n, e;
	int target;
	std::cin >> target;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::cin >> e;
		l.insert(e);
	}

	l.rm_node_from_end(target);
	
	std::cout << l;

	return 0;
}


