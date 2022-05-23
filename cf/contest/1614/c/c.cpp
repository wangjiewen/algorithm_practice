/*
 * No hard feelings.
 * Author: sinfonia
 * Time: 2021-12-05 23:32:22
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

void solve()
{
	int n, m;
	cin >> n >> m;

	ll l, r, x;
	ll ans = 0;
	while(m--) {
		cin >> l >> r >> x;
		ans |= x;
	}

	ans %= mod;
	n--;
	while (n--)
		ans = (ans * 2) % mod;

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

