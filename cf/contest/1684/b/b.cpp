/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-05-19 23:07:06
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll a[3];

	for (int i = 0; i < 3; i++)
		cin >> a[i];

	cout << a[0] + a[1] + a[2] << ' ';
	cout << a[1] + a[2] << ' ';
	cout << a[2] << endl;
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

