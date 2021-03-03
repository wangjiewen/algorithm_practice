#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ret = {0};
		int i = 1, up = 0, bit_max = 1;
		while (i <= num) {
			ret.push_back(ret[up] + 1);
			if (ret[up] + 1 == bit_max) {
				bit_max++;
				up = 0;
			} else {
				up++;
			}
			i++;
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<int> ret = s.countBits(9);
	for (auto i : ret)
		cout << i << ", ";
	cout << endl;

	return 0;
}

