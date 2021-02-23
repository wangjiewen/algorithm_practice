#include <bits/stdc++.h>

using namespace std;

#define N 100005
long long len[N];
long long a[N], b[N];

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> len[i];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	long long ret = 0, cycle = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == b[i]) {
			cycle = len[i] + 1;
		} else if (cycle == 0) {
			cycle = abs(b[i] - a[i]) + len[i] + 1;
		} else {
			cycle = max(cycle - abs(b[i] - a[i]) + len[i] + 1, abs(b[i] - a[i]) + len[i] + 1);
		}
		ret = max(ret, cycle);
	}
	cout << ret << endl;
}

int main(void)
{
	freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}

