/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-12 23:17:17
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int n;
	string s, t;
	int ns = 0, nt = 0;
	int as[3] = {0}, at[3] = {0};
	int ts, tt, multi = 1;

	cin >> n >> s >> t;
	for (int i = n - 1;  i >= 0; i--) {
		ts = s[i] - 'a';
		as[ts]++;
		ns += (ts + 1) * multi;

		tt = t[i] - 'a';
		at[tt]++;
		nt += (tt + 1) * multi;

		multi *= 10;
	}

	if (as[0] != at[0] || as[1] != at[1] || as[2] != at[2]) {
		cout << "NO" << endl;
		return;
	}

	if (ns > nt)
		cout << "NO" << endl;
	else if (ns != nt) {
		if (as[1] == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	} else
		cout << "YES" << endl;
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

