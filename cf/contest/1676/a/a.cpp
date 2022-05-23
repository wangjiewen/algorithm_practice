/*
 * No hard feelings.
 * Author: sinfonia
 * Time: 2022-05-14 16:56:48
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int a;
	int high = 0, low = 0;

	cin >> a;
	for (int i = 0; i < 3; i++) {
		low += a % 10;
		a/= 10;
	}
	for (int i = 0; i < 3; i++) {
		high += a % 10;
		a/= 10;
	}

	if (high == low)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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

