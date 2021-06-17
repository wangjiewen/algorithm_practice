#include <bits/stdc++.h>

#define N 100005

using namespace std;

int n;
int l[N], r[N], a[N];

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	memset(a, 0, sizeof(a));

	int u, v;
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		u--;
		v--;
		if (a[u] == 0 && a[v] == 0) {
			if (abs(l[u] - r[v]) > abs(l[v] - r[u])) {
				a[u] = l[u];
				a[v] = r[v];
				ans += abs(l[u] - r[v]);
			} else {
				a[u] = r[u];
				a[v] = l[v];
				ans += abs(l[v] - r[u]);
			}
		} else if (a[u] == 0 && a[v] != 0) {
			if (abs(l[u] - a[v]) > abs(r[u] - a[v])) {
				a[u] = l[u];
				ans += abs(l[u] - a[v]);
			} else {
				a[u] = r[u];
				ans += abs(r[u] - a[v]);
			}
		} else if (a[u] != 0 && a[v] == 0) {
			if (abs(l[v] - a[u]) > abs(r[v] - a[u])) {
				a[v] = l[v];
				ans += abs(l[v] - a[u]);
			} else {
				a[v] = r[v];
				ans += abs(r[v] - a[u]);
			}
		} else {
			ans += abs(a[v] - a[u]);
		}
	}
	cout << ans << endl;
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

