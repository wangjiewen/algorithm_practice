#include <bits/stdc++.h>

#define N 100005

using namespace std;

int a[N];
int d[N];

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = INT_MAX;
	}

	sort(a, a+n);
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] < d[i - 1])
			d[i] = a[i] - a[i - 1];
		else
			d[i] = d[i - 1];
	}

	int ans = n;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > d[i]) {
			ans--;
		} else {
			cout << ans << endl;
			break;
		}
	}
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

