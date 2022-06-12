/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-12 21:17:41
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int n;
	int a, b, c;

	cin >> n;

	b = (n + 5) / 3;
	a = (n - b) / 2 + 1;
	c = n - a - b;
	cout << a << ' ' << b << ' ' << c << endl;
}

int main(void)
{
	int loop;
	freopen("in1.txt", "r", stdin);
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}

