#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);

	if (n & (1 << (m - 1)))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}

int main(void)
{
	freopen("in", "r", stdin);

	solve();

	return 0;
}

