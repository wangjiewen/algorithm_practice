#include <bits/stdc++.h>

using namespace std;

// 26 进制转换，注意没有0，从1-26对应a-z，所以初始减1
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        int num;

        while (columnNumber > 0) {
            columnNumber--;
            num = columnNumber % 26;
            ret = (char)('A' + num) + ret;
            columnNumber /= 26;
        }
        return ret;
    }
};

int main(void)
{
	Solution s;

	return 0;
}

