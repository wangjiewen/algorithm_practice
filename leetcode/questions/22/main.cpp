#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> list;

        void dfs(int left, int right, string s) {
            if (!left && !right) {
                list.push_back(s);
                return;
            }
            if (left) {
                dfs(left - 1, right, s + '(');
            }
            if (right > left) {
                dfs(left, right - 1, s + ')');
            }
        }

        vector<string> generateParenthesis(int n) {
            string s;
            dfs(n, n, s);
            return list;
        }
};

int main(void)
{
    Solution solve;
    vector<string> array = solve.generateParenthesis(3);
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
    }
    return 0;
}
