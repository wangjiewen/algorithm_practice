/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-14 23:25:32
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int a, b, ans = 0;
	int n = 3;

	cin >> a;
	while (n--) {
		cin >> b;
		if (b > a)
			ans++;
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

