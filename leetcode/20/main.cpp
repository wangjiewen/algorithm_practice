#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> s_stack;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				s_stack.push(s[i]);
			} else {
				if (s_stack.empty())
					return false;
				if (s[i] == ')' && s_stack.top() == '(' || s[i] == ']' && s_stack.top() == '[' || s[i] == '}' && s_stack.top() == '{' ) {
					s_stack.pop();
				} else {
					return false;
				}
			}
		}

		if (s_stack.empty())
			return true;
		else
			return false;
	}
};

int main(void) {
	string str("(])");

	Solution s;
	bool ret = s.isValid(str);
	cout << ret << endl;

	return 0;
}
