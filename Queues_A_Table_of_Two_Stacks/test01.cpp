#include <iostream>
#include <stack>


class Queue{
public:
	Queue()=default;
	
	void push(int elem){
		in.push(elem);
	}

	void pop(){
		if(out.size()==0){

			while(in.size()!=0){
				out.push(in.top());
				in.pop();
			}
		}
		out.pop();		
	}

	int front(){
		if(out.size()==0){
			while(in.size()!=0){
				out.push(in.top());
				in.pop();
			}
		}
		return out.top();
	}


private:
	std::stack<int> in;
	std::stack<int> out;
	
};



int main(){
	Queue q1;
	int q, type, x;
	std::cin >> q;
	for(int i = 0; i < q; ++i){
		std::cin >> type;
		if(type == 1){
			std::cin >> x;
			q1.push(x);
		}
		else if(type==2){
			q1.pop();
		}
		else{
			std::cout << q1.front() << "\n";
		}
	}

}
