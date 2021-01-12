#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long updiv(long long a, long long b)
{
	return (a + b - 1) / b;
}

int main(void)
{
	int loop;
	long long n, x;
	long long maxb, minb;
	long long prev, now;
	long long updiv_prev, updiv_now;

	freopen("in.txt", "r", stdin);

	scanf("%d", &loop);
	while (loop--) {
		maxb = minb = 0;
		prev = now = 0;
		updiv_prev = 0;

		scanf("%lld %lld", &n, &x);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &now);
			updiv_now = updiv(now, x);

			maxb += updiv_now;

			if (updiv_now + updiv_prev > updiv(now+prev, x)) {
				minb = minb - updiv_prev + updiv(now+prev, x);
				updiv_prev = prev = 0;
			} else {
				minb += updiv_now;
				updiv_prev = updiv_now;
				prev = now;
			}
		}

		printf("%lld %lld\n", minb, maxb);
	}
	return 0;
}
