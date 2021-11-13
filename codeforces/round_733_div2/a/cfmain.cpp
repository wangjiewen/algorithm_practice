#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	int ans = 1;

	cin >> n;
	while (n > 0) {
		ans = max(n % 10, ans);
		n /= 10;
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

