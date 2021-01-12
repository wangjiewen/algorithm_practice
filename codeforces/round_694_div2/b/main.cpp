#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
	int loop;
	int n;
	long long x;

	int stop;
	long long ret, times;
	long long nums[100005];

	freopen("in.txt", "r", stdin);

	scanf("%d", &loop);
	while (loop--) {
		ret = 0;
		scanf("%d %lld", &n, &x);
		for (int i = 0; i < n; i++)
			scanf("%lld", &nums[i]);

		times = 1;
		stop = n;
		while (1) {
			if (stop != n)
				break;
			for (int i = 0; i < n; i++) {
				ret += times * nums[i];
				if(stop == n && nums[i] % x != 0) {
					stop = i;
				}
				nums[i] /= x;
			}
			times *= x;
		}

		for (int i = 0; i < stop; i++)
			ret += times * nums[i];

		printf("%lld\n", ret);
	}
	return 0;
}
