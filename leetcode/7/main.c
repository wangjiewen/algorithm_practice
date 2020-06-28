#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x){
	int ret = 0;
	int temp;

	while (x != 0) {
		temp = x % 10;
		if (ret > INT_MAX/10 || (ret == INT_MAX/10 && temp > 7)) {
			return 0;
		}
		if (ret < INT_MIN/10 || (ret == INT_MAX/10 && temp < -8)) {
			return 0;
		}
		ret = ret * 10 + temp;
		x /= 10;
	}

	return ret;
}

int main(void)
{
	int x = -1536469;
	int ret;

	ret = reverse(x);
	printf("%d\n", ret);

	return 0;
}
