#include <iostream>
#include <stack>
#include<string>


bool isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')') return true;
	else if (character1 == '{' && character2 == '}') return true;
	else if (character1 == '[' && character2 == ']') return true;
	else return false;
}


bool areParenthesisBalanced(std::string exp){
	int i = 0;
	char c;
	std::stack<char> s;
	while (i < exp.length())
   	{
		/*If the exp[i] is a starting parenthesis then push it*/
		if (exp.at(i) == '{' || exp.at(i) == '(' || exp.at(i) == '[')
			s.push(exp[i]);
 
		/* If exp[i] is an ending parenthesis then pop from stack and 
		check if the popped parenthesis is a matching pair*/
		if (exp.at(i) == '}' || exp.at(i) == ')' || exp.at(i) == ']'){
			/*If we see an ending parenthesis without a pair then return false*/
			if (s.size() == 0) return false; 
 
			/* Pop the top element from stack, if it is not a pair 
			parenthesis of character then there is a mismatch.
			This happens for expressions like {(}) */
			else{
				c = s.top();
				s.pop();
				if ( !isMatchingPair(c, exp.at(i))) return false;
			}
		}
		i++;
	}
	if (s.size()==0) return true; /*balanced*/
	else return false;  /*not balanced*/
}


int main(){
	std::string exp = "{()}[]";
	if (areParenthesisBalanced(exp)) std::cout << "Balanced\n";
	else std::cout << "Not Balanced\n";

	return 0;
}
