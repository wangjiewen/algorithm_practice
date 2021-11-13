#include <bits/stdc++.h>

using namespace std;

int ans[22][22];

void solve()
{
	int h, w;

	memset(ans, 0, sizeof(ans));
	cin >> h >> w;

	for (int i = 0; i < w; i+=2) {
		ans[0][i] = 1;
		ans[h-1][i] = 1;
	}

	for (int i = 1; i < h - 1; i++) {
		if (!ans[i - 1][0] && !ans[i - 1][1] &&
				!ans[i + 1][0] && !ans[i + 1][1])
			ans[i][0] = 1;
		if (!ans[i - 1][w - 1] && !ans[i - 1][w - 2] &&
				!ans[i + 1][w - 1] && !ans[i + 1][w - 2])
			ans[i][w - 1] = 1;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	cout << endl;
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

