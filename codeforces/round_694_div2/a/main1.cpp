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
	long long now;

	freopen("in.txt", "r", stdin);

	scanf("%d", &loop);
	while (loop--) {
		maxb = minb = 0;

		scanf("%lld %lld", &n, &x);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &now);
			maxb += updiv(now, x);
			minb += now;
		}
		minb = updiv(minb, x);

		printf("%lld %lld\n", minb, maxb);
	}
	return 0;
}
