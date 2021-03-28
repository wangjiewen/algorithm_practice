#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> nums;
        for (int i = 0; i < word.size(); i++) {
            if (isdigit(word[i])) {
                string num;
                while (isdigit(word[i])) {
                    if (!num.empty() || word[i] != '0')
                        num += word[i];
                    i++;
                }
                nums.insert(num);
            }
        }
        return nums.size();
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

