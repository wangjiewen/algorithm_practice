/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-05-23 22:40:59
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int n, m, num;
	int ma = 0, mb = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		ma = max(num, ma);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		mb = max(num, mb);
	}

	if (ma == mb) {
		cout << "Alice" << endl << "Bob" << endl;
	} else if (ma < mb) {
		cout << "Bob" << endl << "Bob" << endl;
	} else {
		cout << "Alice" << endl << "Alice" << endl;
	}
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

