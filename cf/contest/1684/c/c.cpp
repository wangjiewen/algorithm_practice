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
	int x1, y1, x2 = 0, y2 = 0, ans = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[j];
			b[j] = a[j];
		}
		if (ans)
			continue;

		sort(a, a + m);
		x1 = y1 = 0;
		cout << "wjw a:" << endl;
		for (int j = 0; j < m; j++)
			cout << a[j] << ' ';
		cout << endl;
		cout << "wjw b:" << endl;
		for (int j = 0; j < m; j++)
			cout << b[j] << ' ';
		cout << endl;
		for (int j = 0; j < m; j++) {
			if (a[j] != b[j]) {
				if (!x1)
					x1 = j + 1;
				else if (!y1)
					y1 = j + 1;
				else {
					ans = 1;
					break;
				}
			}
		}
		cout << "x1 = " << x1 << "y1 =" << y1 << endl;
		cout << "x2 = " << x2 << "y2 =" << y2 << endl;
		cout << "ans=" << ans << endl;

		if (ans)
			continue;

		if (x2 == y2) {
			x2 = x1;
			y2 = y1;
		} else if (x1 == y1) {
			continue;
		} else {
			if (x1 != x2 || y1 != y2) {
				ans = 1;
			}
		}
	}

	if (ans) {
		cout << -1 << endl;
		return;
	}

	if (!x1)
		x1 = y1 = 1;

	cout << x1 << ' ' << y1 << endl;
	cout << endl;
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

