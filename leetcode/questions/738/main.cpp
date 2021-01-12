#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution {
	public:
		int monotoneIncreasingDigits(int N) {
			int ret = 0, base = 1;
			int num = 0, last_num = 9; 

			while (N > 0) {
				num = N % 10;
				N /= 10;

				if (num <= last_num) {
					ret = ret + num * base;
					base *= 10;
					last_num = num;
				} else {
					ret = num * base - 1;
					base *= 10;
					last_num = num - 1;
				}
			}
			return ret;
		}
};

int main(void)
{
	Solution s;
	int ret;

	ret = s.monotoneIncreasingDigits(10);
	printf("%d\n", ret);

	return 0;
}
