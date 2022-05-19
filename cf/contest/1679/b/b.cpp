/*
 * No hard feelings.
 * Author: sinfonia
 * Time: 2022-05-14 18:27:27
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sn, g = 0;
ll n, q;
ll a[200005];
ll gen[200005];
ll ans = 0;

void _solve()
{
	ll t;
	ll i, x;

	cin >> t;

	if (t == 1) {
		cin >> i >> x;
		i -= 1;

		if (gen[i] == g) {
			ans = ans - a[i] + x;
		} else {
			ans = ans - sn + x;
		}
		a[i] = x;
		gen[i] = g;
	} else {
		cin >> x;
		ans = x * n;
		sn = x;
		g += 1;
	}

	cout << ans << endl;
}

void solve()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
		gen[i] = 0;
	}

	while (q--)
		_solve();

}

int main(void)
{
	int loop;
	solve();

	return 0;
}

