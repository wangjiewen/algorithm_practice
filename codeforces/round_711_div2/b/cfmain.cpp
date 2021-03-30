#include <bits/stdc++.h>

using namespace std;

#define N 20

int num[N];

void solve()
{
	int n, w;
	int wid;
	int ret = 0;

	memset(num, sizeof(num), 0);
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; i++) {
		scanf("%d", &wid);
		wid = (int)log2(wid);
		num[wid]++;
	}

	int len, use, tl;
	int i = 0;
	while (i < n) {
		len = w;
		for (int j = N - 1; i < n && j >= 0 && len > 0; j--) {
			if (num[j] != 0) {
				tl = pow(2, j);
				use = min(len / tl, num[j]);
				i += use;
				num[j] -= use;
				len -= use * tl;
			}
		}
		ret++;
	}

	printf("%d\n", ret);
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

