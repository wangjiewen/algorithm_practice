/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-05-23 22:50:55
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
int a[N];

void solve()
{
	int n, m;
	int b, ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b;
		ans = (ans + b) % n;
	}

	cout << a[ans] << endl;
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

