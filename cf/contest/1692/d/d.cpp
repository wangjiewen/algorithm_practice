/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-14 23:58:56
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isp(int h, int m)
{
	int h1, h2, m1, m2;
	//cout << h <<':'<<m<< endl;
	h1 = h % 10;
	h2 = h / 10;
	m1 = m % 10;
	m2 = m / 10;
	return h1 == m2 && m1 == h2;
}

void solve()
{
	int h, m, x;
	int nh, nm;
	int c;
	int ans = 0;

	scanf("%d:%d %d", &h, &m, &x);

	nh = h;
	nm = m;
	do {
		c = 0;
		nm += x % 60;
		if (nm > 60) {
			nm -= 60;
			c = 1;
		}
		nh += x / 60 + c;
		if (nh > 24) {
			nh -= 24;
		}

		if (isp(nh, nm))
			ans++;
	} while (nh != h || nm != m);
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

