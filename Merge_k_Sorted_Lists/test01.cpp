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
	


	friend List<T>& merge(const List<T>& lhs, const List<T>& rhs){
		Node<T> *curr1, *curr2;
		curr1 = lhs.head;
		curr2 = rhs.head;
		List<T> *l = new List<T>();
		
		while(curr1!=nullptr || curr2!=nullptr){
			if(curr1!=nullptr && curr2==nullptr){
				l->insert(curr1->val);			
				curr1 = curr1->next;
			}else if(curr1==nullptr && curr2!=nullptr){
				l->insert(curr2->val);		
				curr2 = curr2->next;
			}else if(curr1->val < curr2->val){
				l->insert(curr1->val);		
				curr1 = curr1->next;
			}else if(curr1->val >= curr2->val){
				l->insert(curr2->val);		
				curr2 = curr2->next;
			}
		}
		return *l;
	}

	template <class... Args>
	friend List<T>& merge(const List<T>& lhs, const List<T>& rhs, Args... args){
		return merge(merge(lhs, rhs), args...);
	}


	
	friend std::ostream& operator<<(std::ostream& os, const List<T>& l){
		Node<T> *curr = l.head;
		while(curr){
			os << curr->val << " ";
			curr = curr->next;
		}
		os << "\n";
		return os;
	}
private:
	Node<T> *head;
};



int main(int argc, char *argv[]){
	List<int> l1;
	List<int> l2;
	List<int> l3;

	int n, e;
	std::cin >> n;
	for(int i=0; i < n; ++i){
		std::cin >> e;
		l1.insert(e);
	}
	std::cin >> n;
	for(int i=0; i < n; ++i){
		std::cin >> e;
		l2.insert(e);
	}
	std::cin >> n;
	for(int i=0; i < n; ++i){
		std::cin >> e;
		l3.insert(e);
	}


	List<int> l = merge(l1, l2, l3);
	std::cout << l;

	return 0;
}

