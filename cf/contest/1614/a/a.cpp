/*
 * No hard feelings.
 * Author: sinfonia
 * Time: 2021-12-04 20:19:50
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int n, l, r, k;
	cin >> n >> l >> r >> k;

	vector<int> price(n);
	for (int i = 0; i < n; i++)
		cin >> price[i];

	sort(price.begin(), price.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (price[i] >= l && price[i] <= r && k - price[i] >= 0) {
			ans++;
			k -= price[i];
		}

		if (price[i] > r || k - price[i] < 0)
			break;
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

