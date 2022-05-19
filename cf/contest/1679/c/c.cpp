/*
 * No hard feelings.
 * Author: sinfonia
 * Time: 2022-05-14 19:14:05
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 100005
int a[N][N];

void solve_add()
{
	int x, y;
	cin >> x >> y;
	a[x][y] = 1;
}

void solve_del()
{
	int x, y;
	cin >> x >> y;
	a[x][y] = 0;
}

void solve()
{
	int x, y, m, n;
	int ans = 0;

	cin >> x >> y >> m >> n;
	for (int i = x; i <= y; i++) {
		for (int j = m; j <= n; j++) {
			if (a[i][j]) {
				ans = 1;
				break;
			}
		}
	}

	if (ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main(void)
{
	int n, q, t;

	//freopen("in1.txt", "r", stdin);
	cin >> n >> q;
	while (q--) {
		cin >> t;
		if (t == 1)
			solve_add();
		else if (t == 2)
			solve_del();
		else
			solve();
	}
	return 0;
}

