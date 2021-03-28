#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2)
            return 1;
        int i = 2;
        int ret = 1;

        while (i != 1) {
            if (i < n / 2) {
                i = i * 2;
            } else {
                i = 1 - n + 2 * i;
            }
            cout << i << ",";
            ret++;
        }
        cout << endl;
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

