#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
		int nums[26] = {0};
		int i, j;
		int ret = 0;

		for (i = 0; s[i] != '\0'; i++) {
			nums[s[i] - 'a']++;
		}

		sort(nums, nums+26, greater<int>());
		for (i = 0; i < 26; i++) {
			for (j = i + 1; j < 26; j++) {
				if (nums[i] != 0 && nums[j] != 0 && nums[i] == nums[j]) {
					nums[j]--;
					ret++;
				}
			}
		}

		return ret;
    }
};

int main(void)
{
	Solution s;
	string str;
	int ret;

	cin >> str;
	ret = s.minDeletions(str);
	printf("%d\n", ret);

	return 0;
}
