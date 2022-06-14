/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-12 22:35:39
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int n, m;
	int ans = 0, t;

	cin >> n >> m;
	while (n--) {
		cin >> t;
		ans += t;
	}

	ans -= m;
	cout << (ans > 0 ? ans : 0) << endl;
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

