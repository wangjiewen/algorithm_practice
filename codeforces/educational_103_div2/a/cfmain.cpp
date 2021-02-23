#include <bits/stdc++.h>

using namespace std;

long long updiv(long long a, long long b)
{
	return (a + b - 1) / b;
}

void solve()
{
	long long n, k;
	cin >> n >> k;
	cout << updiv(updiv(n, k)*k, n) << endl;
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

