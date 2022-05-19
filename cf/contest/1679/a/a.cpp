/*
 * No hard feelings.
 * Author: sinfonia
 * Time: 2022-05-14 17:55:22
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll a;
	ll low, high;

	cin >> a;
	if (a < 4 || a & 1) {
		cout << "-1" << endl;
		return;
	}

	cout << (a + 5)/6 << " " << a/4 << endl;
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

