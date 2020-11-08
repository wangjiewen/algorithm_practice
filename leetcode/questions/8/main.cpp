#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <limits.h>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int i = 0, flag = 1;
		long long ret = 0;

		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			flag = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;

		while (str[i] != '\0' && isdigit(str[i])) {
			ret = ret * 10 + (str[i] - '0');
			if (ret >= INT_MAX && flag == 1)
				return INT_MAX;
			if (ret > INT_MAX && flag == -1)
				return INT_MIN;
			i++;
		}

		return flag * ret;
	}
};

int main(void)
{
	Solution s;
	string str("  -134");
	int ret;

	ret = s.myAtoi(str);
	printf("%d\n", ret);
	
	return 0;
}
