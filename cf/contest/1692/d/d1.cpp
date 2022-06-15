/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-14 23:58:56
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t[16][2] = {
	{0, 0}, {1, 10}, {2, 20}, {3, 30},
	{4, 40}, {5, 50}, {11, 11}, {12, 21},
	{13, 31}, {14, 41}, {15, 51}, {21, 12},
	{22, 22}, {23, 32}, {20, 2}, {10, 1}
};

int ans[16];

void cul_ans()
{
	for (int i = 0; i < 16; i++)
		ans[i] = t[i][0] * 60 + t[i][1];
}

void solve()
{
	int h, m, x;
	int a, ret = 0;
	int b;

	scanf("%d:%d %d", &h, &m, &x);
	a = h * 60 + m;

	for (int i = 0; i < 16; i++) {
		b = ans[i];
		if (b < a)
			b += 1440;
		if ((b-a)%x == 0)
			ret++;
	}

	cout << ret << endl;
}

int main(void)
{
	int loop;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &loop);
	cul_ans();
	while (loop--) {
		solve();
	}

	return 0;
}

