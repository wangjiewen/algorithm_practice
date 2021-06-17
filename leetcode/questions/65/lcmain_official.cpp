#include <bits/stdc++.h>

using namespace std;

// 状态机，包含当前状态，输入，输出
class Solution {
public:
	enum State {
		STAT_INITIAL,
		STAT_INT_SIGN,
		STAT_INTERGER,
		STAT_POINT,
		STAT_POINT_ONLY,
		STAT_FRACTION,
		STAT_EXP,
		STAT_EXP_SIGN,
		STAT_EXP_NUMBER,
		STAT_END
	};

	enum CharType {
		CHAR_NUMBER,
		CHAR_EXP,
		CHAR_POINT,
		CHAR_SIGN,
		CHAR_ILLEGAL
	};

	CharType toCharType(char c) {
		if (isdigit(c))
			return CHAR_NUMBER;
		else if (c == 'e' || c == 'E')
			return CHAR_EXP;
		else if (c == '.')
			return CHAR_POINT;
		else if (c == '+' || c == '-')
			return CHAR_SIGN;
		else
			return CHAR_ILLEGAL;
	}

	bool isNumber(string s) {
		unordered_map<State, unordered_map<CharType, State>> trans {
			{
				STAT_INITIAL, {
					{CHAR_NUMBER, STAT_INTERGER},
					{CHAR_POINT, STAT_POINT_ONLY},
					{CHAR_SIGN, STAT_INT_SIGN},
				}
			}, {
				STAT_INT_SIGN, {
					{CHAR_NUMBER, STAT_INTERGER},
					{CHAR_POINT, STAT_POINT_ONLY},
				}
			}, {
				STAT_INTERGER, {
					{CHAR_NUMBER, STAT_INTERGER},
					{CHAR_POINT, STAT_POINT},
					{CHAR_EXP, STAT_EXP},
				}
			}, {
				STAT_POINT, {
					{CHAR_EXP, STAT_EXP},
					{CHAR_NUMBER, STAT_FRACTION},
				}
			}, {
				STAT_POINT_ONLY, {
					{CHAR_NUMBER, STAT_FRACTION},
				}
			}, {
				STAT_FRACTION, {
					{CHAR_NUMBER, STAT_FRACTION},
					{CHAR_EXP, STAT_EXP},
				}
			}, {
				STAT_EXP, {
					{CHAR_SIGN, STAT_EXP_SIGN},
					{CHAR_NUMBER, STAT_EXP_NUMBER},
				}
			}, {
				STAT_EXP_SIGN, {
					{CHAR_NUMBER, STAT_EXP_NUMBER},
				}
			}, {
				STAT_EXP_NUMBER, {
					{CHAR_NUMBER, STAT_EXP_NUMBER},
				}
			}
		};

		State st = STAT_INITIAL;

		for (auto c : s) {
			CharType ct = toCharType(c);
			if (trans[st].find(ct) == trans[st].end()) {
				return false;
			} else {
				st = trans[st][ct];
			}
		}

		return st == STAT_INTERGER || st == STAT_FRACTION || st == STAT_EXP_NUMBER || st == STAT_POINT;
	}
};

int main(void)
{
	Solution s;

	return 0;
}

