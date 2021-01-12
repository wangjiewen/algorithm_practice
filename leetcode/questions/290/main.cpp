#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
	int begin;
	string s_split(string s) {
		if (begin > s.size()) return "";
		int temp_begin = begin;
		int end;
		for (end = begin + 1; s[end] != ' ' && s[end] != '\0'; end++);
		begin = end + 1;
		return s.substr(temp_begin, end - temp_begin);
	}
public:
	bool wordPattern(string pattern, string s) {
		unordered_map<char, string> c2s;
		unordered_map<string, char> s2c;
		int len = pattern.length();

		begin = 0;
		for (int i = 0; i < pattern.length(); i++) {
			char c = pattern[i];
			string str = s_split(s);
			if (str.empty()) return false;

			cout << c << " " << str << endl;
			if (c2s.find(c) != c2s.end() && c2s[c] != str)
				return false;
			if (s2c.find(str) != s2c.end() && s2c[str] != c)
				return false;

			c2s[c] = str;
			s2c[str] = c;
		}
		if (s.size() != begin - 1) return false;
		return true;
	}
};

int main(void)
{
	Solution s;
	string pattern = "aaaaaa";
	string str = "dog dog dog dog";
	bool ret;

	ret = s.wordPattern(pattern, str);
	cout << ret << endl;

	return 0;
}
