#include <iostream>
#include <stack>
#include <cassert>
#include <cstdlib>
#include <cstring>

// Function to find precedence of
// // operators.
int precedence(char op){
	if(op == '+'||op == '-')
        	return 1;
        if(op == '*'||op == '/')
                return 2;
        return 0;
}
                      
// Function to perform arithmetic operations.
int applyOp(int a, int b, char op){
	switch(op){
		case '+': 
			return a + b;
		break;
        	case '-': 
			  return a - b;
        	break;
		case '*': 
			  return a * b;
        	break;
		case '/': 
			  return a / b;
		break;
        }
	std::exit(0);
	return 0;
}
                                                               
int evaluate(std::string tokens){
	int i;
	std::stack <int> values;
	std::stack <char> ops;
                                                                                                  
        for(i = 0; i < tokens.length(); i++){
        	if(tokens[i] == ' ')
        		continue;
		else if(tokens[i] == '('){
			ops.push(tokens[i]);
		}
		else if(isdigit(tokens[i])){
			int val = 0;
			while(i < tokens.length() && isdigit(tokens[i])){
				val = (val*10) + (tokens[i]-'0');
				++i;
			}
			values.push(val);
			--i;
		}
        	else if(tokens[i] == ')'){
			while(!ops.empty() && ops.top() != '('){
				int val2 = values.top();
				values.pop();
				int val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(applyOp(val1, val2, op));
			}
			if(!ops.empty())
			ops.pop();
		}
		else{
			while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
				int val2 = values.top();
				values.pop();
				int val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(applyOp(val1, val2, op));
			}
			ops.push(tokens[i]);
		}
	}
	while(!ops.empty()){
		int val2 = values.top();
		values.pop();
		int val1 = values.top();
		values.pop();
		char op = ops.top();
		ops.pop();
		values.push(applyOp(val1, val2, op));
	}
	return values.top();
}

int main(){
	std::cout << evaluate("10") << std::endl;

	return 0;
}
