/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-14 23:29:51
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 8

void solve()
{
	int num = 0, x, y;
	string s[N];

	for (int i = 0; i < N; i++)
		cin >> s[i];

	for (int i = 0; i < N; i++) {
		num = 0;
		for (int j = 0; j < N; j++) {
			if (s[i][j] == '#') {
				x = i;
				y = j;
				num++;
			}
		}
		if (num == 1 && x >= 1 && x <= 6 && y >= 1 && y <= 6 &&
				s[x-1][y-1] == '#' && s[x+1][y+1] == '#' &&
				s[x-1][y+1] == '#' && s[x+1][y-1] == '#')
			break;
	}
	cout << x + 1 << ' ' << y + 1 << endl;
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

