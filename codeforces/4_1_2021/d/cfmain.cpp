#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	int one;
	scanf("%d%d", &n, &m);

	while (n > 0) {
		one = n % 10;
		n /= 10;
		if (one >= m) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(void)
{
	freopen("in", "r", stdin);

	solve();

	return 0;
}

