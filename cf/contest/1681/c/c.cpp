/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-05-23 23:25:23
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[101], b[101];
int sa[101], sb[101];
int mina[101], na;
int ans[10004][2], nans;

void aget_min(int begin)
{
	int num = sa[begin];

	na = 0;

	for (int i = begin; i < n; i++) {
		if (a[i] == num) {
			mina[na] = i;
			na++;
		}
	}
}

bool bcheck_min(int begin)
{
	int num = sb[begin];
	int pos;

	for (int i = 0; i < na; i++) {
		pos = mina[i];
		if (b[pos] == num) {
			if (pos == begin)
				return true;
			swap(b[pos], b[begin]);
			swap(a[pos], a[begin]);
			ans[nans][0] = pos;
			ans[nans][1] = begin;
			nans++;
			return true;
		}
	}

	return false;
}

void solve()
{
	nans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sa[i] = a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sb[i] = b[i];
	}

	sort(sa, sa+n);
	sort(sb, sb+n);

	for (int i = 0; i < n; i++) {
		aget_min(i);
		if (!bcheck_min(i)) {
			cout << "-1" << endl;
			return;
		}
	}

	cout << nans << endl;
	for (int i= 0; i < nans; i++)
		cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << endl;
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

