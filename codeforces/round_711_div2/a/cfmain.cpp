#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

long long getsum(long long a) {
	long long ret = 0;
	while (a != 0) {
		ret += a % 10;
		a /= 10;
	}
	return ret;
}

void solve()
{
	long long n;
	scanf("%lld", &n);

	while (gcd(n, getsum(n)) == 1) {
		n++;
	}
	printf("%lld\n", n);
}

int main(void)
{
	freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}

