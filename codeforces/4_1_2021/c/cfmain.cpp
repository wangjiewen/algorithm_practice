#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int a, b, t;
	string str;
	cin >> str;
	int n = str.size();

	if (str.size() < 2) {
		cout << "YES" << endl;
		return;
	}

	a = str[0] - 'A';
	b = str[1] - 'A';
	for (int i = 2; i < n; i++) {
		t = str[i] - 'A';
		if (t != (a + b) % 26) {
			cout << "NO" << endl;
			return;
		}
		a = b;
		b = t;
	}

	cout << "YES" << endl;
}

int main(void)
{
	freopen("in", "r", stdin);

	solve();

	return 0;
}

