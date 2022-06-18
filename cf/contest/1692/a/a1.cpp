/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-16 13:17:46
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (a < b) + (a < c) + (a < d) << endl;
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

