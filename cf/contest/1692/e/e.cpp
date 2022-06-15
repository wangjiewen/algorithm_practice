/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-15 00:12:51
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
int a[N];

void solve()
{
	int n, s;
	int l, r;
	int ans = 0;

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	r = n / 2;
	l = (n - 1) / 2;

	if (l == r)
		ans = a[l];
	else
		ans = a[l] + a[r];
	l--;
	r++;
	while (l >= 0) {
		if (ans >= s)
			break;
		ans += a[l] + a[r];
		l--;
		r++;
	}
	if (ans == s)
		cout << l + 1 << endl;
	else
		cout << -1 << endl;
}

int main(void)
{
	int loop;
	//freopen("in1.txt", "r", stdin);
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}

