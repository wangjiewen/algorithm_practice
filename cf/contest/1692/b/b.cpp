/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-14 23:43:54
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	set<int> s;
	int n, a;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}

	a = s.size();
	if ((n - a) & 1)
		a--;

	cout << a << endl;
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

