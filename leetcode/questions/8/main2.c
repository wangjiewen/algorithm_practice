#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char *str) {
	int is_neg = 0;
	int i = 0;
	long long ret = 0;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-')
		is_neg = 1;

	if (str[i] == '-' || str[i] == '+')
		i++;

	while (str[i] != '\0' && isdigit(str[i])) {
		ret = ret * 10 + (str[i] - '0');
		if (ret >= INT_MAX && !is_neg)
			return INT_MAX;
		if (ret > INT_MAX && is_neg)
			return INT_MIN;
		i++;
	}

	return is_neg ? -ret : ret;
}

int main(void)
{
	char *s = "    -2147483648";
	int ret;

	ret = myAtoi(s);
	printf("%d\n", ret);

	return 0;
}
