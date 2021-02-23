#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	long long k;
	cin >> n >> k;
	long long p[n];
	for (int i = 0 ; i < n; i++) {
		cin >> p[i];
	}

	long long inc = 0, sum = p[0], now;
	for (int i = 1; i < n; i++) {
		now = (p[i] * 100 + k - 1) / k;
		if (now > sum) {
			inc += now - sum;
			sum = now;
		}
		sum += p[i];
	}

	cout << inc << endl;
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

