/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-12 22:46:38
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
ll p[N];
int main(void)
{
	ll n, q;
	ll x, y;

	cin >> n >> q;
	for (ll i = 0; i < n; i++) {
		cin >> p[i];
	}

	sort(p, p + n, greater<int>());

	for (ll i = 1; i < n; i++)
		p[i] += p[i - 1];

	while (q--) {
		cin >> x >> y;
		if (x == y)
			cout << p[x - 1] << endl;
		else
			cout << p[x - 1] - p[x - y - 1] << endl;
	}

	return 0;
}

