#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ret = 0;
		while (n > 0) {
			ret += n & 1;
			n = n >> 1;
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	//int ret = s.hammingWeight(3);
	int ret = s.hammingWeight(31);
	cout << ret << endl;

	return 0;
}

