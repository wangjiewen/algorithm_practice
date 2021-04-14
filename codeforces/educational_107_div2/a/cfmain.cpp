#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	int v = 0, r;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r;
		if (r == 1 || r == 3) {
			v++;
		}
	}
	cout << v << endl;
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

