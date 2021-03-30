#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int con = 0;
        int ret = 0, tret = 0;
        int l = 0, r = 0;

        int i = 0;
        while (i < s.size() && s[i] == ')')
            i++;
        while (i < s.size()) {
            l = r = 0;
            while (i < s.size() && s[i] == '(') {
                l++;
                i++;
            }
            while (i < s.size() && s[i] == ')') {
                r++;
                i++;
            }
            ret = max(ret, tret);
            if (l == r) {
                con++;
                tret += 2 * min(l, r);
                ret = max(ret, tret);
            } else if (l > r) {
                con = 1;
                tret = 2 * min(l, r);
                ret = max(ret, tret);
            } else {
                tret += 2 * min(l, r);
                ret = max(ret, tret);
                con = 0;
                tret = 0;
            }
        }
        return ret;
    }
};
class Solution {
public:

};

int main(void)
{
	Solution s;

	return 0;
}

