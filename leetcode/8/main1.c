#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char * str){
	int i = 0;
	int ret = 0;
	int neg = 0;
	int temp;

	while(str[i] == ' ')
		i++;

	if (str[i] == '-') {
		neg = 1;
		i++;
	} else if (str[i] == '+') {
		i++;
	}

	while (isdigit(str[i])) {
		temp = str[i] - '0';

		if (neg) {
			if (ret < INT_MIN/10) {
				return INT_MIN;
			} else if (ret == INT_MIN/10 && temp >= 8) {
				return INT_MIN;
			} else {
				ret = ret * 10 - temp;
			}
		} else {
			if (ret > INT_MAX/10) {
				return INT_MAX;
			} else if (ret == INT_MAX/10 && temp >= 7) {
				return INT_MAX;
			} else {
				ret = ret * 10 + temp;
			}
		}
		i++;
	}

	return ret;
}

int main(void)
{
	char *s = "-2147483648";
	int x;

	x = myAtoi(s);
	printf("%d\n", x);

	return 0;
}
