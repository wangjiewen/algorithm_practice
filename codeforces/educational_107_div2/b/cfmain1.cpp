#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int a, b, c;

	cin >> a >> b >> c;

	cout << '1';
	for (int i = 0; i < a - 1; i++)
		cout << '0';
	cout << ' ';

	cout << '1';
	for (int i = 0; i < b - c; i++)
		cout << '1';
	for (int i = 0; i < c - 1; i++)
		cout << '0';
	cout << ' ' << endl;
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

