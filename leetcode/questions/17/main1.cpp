#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

	map<char, string> nums = {
	    {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
	    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
	    {'8', "tuv"}, {'9', "wxyz"},
	};
	vector<string> ret;
	string current;

	void DFS(int index, string digits) {
		if (index == digits.size()) {
			ret.push_back(current);
			return;
		}
		for (int i = 0; i < nums[digits[index]].size(); i++) {
			current.push_back(nums[digits[index]][i]);
			DFS(index + 1, digits);
			current.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) {
			return ret;
		}
		DFS(0, digits);
		return ret;
	}

int main(void)
{
	string digits("23");
	vector<string> r = letterCombinations(digits);
	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << ", ";
	}
	cout << endl;
	return 0;
}
