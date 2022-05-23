/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-05-19 22:37:27
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll a, ans = 10, ta;
	cin >> a;

	if (a < 100) {
		cout << a % 10 << endl;
		return;
	}
	while (a) {
		ta = a % 10;
		ans = ta < ans ? ta : ans;
		a /= 10;
	}

	cout << ans << endl;
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

