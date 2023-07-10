#pragma once
#include "common.h"

class SimpleCalculator {
public:
	int calculate(string s) {
		stack<char> operator_stack;
		stack<int> num_stack;
		char last_char = 'a';
		int sign = +1;
		for (auto i : s) {
			if (isdigit(i))
				num_stack.push((i - '0') * sign), sign = +1;
			else if (_is_parenthesis(i)) {
				if (i == '(')
					operator_stack.push(i);
				else {
					while (operator_stack.top() != '(') {
						_cal(operator_stack, num_stack);
					} 
					operator_stack.pop();
				}
			}
			else { // is operator
				while(
					!(operator_stack.empty() || operator_stack.top() == '(')
					&& _level(operator_stack.top()) >= _level(i)
					){
					_cal(operator_stack, num_stack);
				}
				if (last_char == '(') 
					sign = i == '-'? -1 : +1;
				else operator_stack.push(i);
			}
			last_char = i;
		}

		while (!operator_stack.empty()) {
			_cal(operator_stack, num_stack);
		}

		return num_stack.top();
	}

	void _cal(stack<char>& op, stack<int>& operands) {
		auto b = operands.top();
		operands.pop();
		auto a = operands.top();
		operands.pop();
		int val;
		switch (op.top()) {
		case '+':
			val = a + b;
			break;
		case '-':
			val = a - b;
			break;
		case '*':
			val = a * b;
			break;
		case '/':
			val = a / b;
			break;
		}
		operands.push(val);
		op.pop();
	}

	int _level(char c) {
		if (c == '+' || c == '-')
			return 1;
		if (c == '*' || c == '/')
			return 2;
		return 0;
	}

	bool _is_parenthesis(const char c) {
		return c == '(' or c == ')';
	}

	int solve(string s) {
		return calculate(s);
	}
};