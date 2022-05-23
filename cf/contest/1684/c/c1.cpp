/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-05-19 23:24:30
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
int a[N], b[N];

void solve()
{
	int n, m;
	int x, y, ans;
	x = y = ans = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[j];
			b[j] = a[j];
		}
		if (ans)
			continue;
		if (x != y) {
			swap(a[x - 1], a[y - 1]);
			for (int j = 1; j < m; j++) {
				if (a[j] < a[j-1]) {
					ans = 1;
					break;
				}
			}
		} else {
			sort(a, a + m);
			for (int j = 0; j < m; j++) {
				if (a[j] != b[j]) {
					if (!x)
						x = j + 1;
					else if (!y)
						y = j + 1;
					else {
						ans = 1;
						break;
					}
				}
			}
		}
	}

	if (ans) {
		cout << -1 << endl;
		return;
	}

	if (!x)
		x = y = 1;

	cout << x << ' ' << y << endl;
}

int main(void)
{
	int loop;
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}

