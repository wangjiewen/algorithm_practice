#include <bits/stdc++.h>

using namespace std;

bool check_pos(string &a, string &b, int begin, int end)
{
	for (int i = begin; i <= end; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool check(string &a, string &b, int begin, int end)
{
	if (check_pos(a, b, begin, end))
		return true;
	for (int i = begin; i <= end; i++) {
		if (a[i] == b[i]) {
			return false;
		}
	}
	return true;
}

void solve()
{
	int len;
	string a, b;
	cin >> len >> a >> b;

	int begin = 0;
	int na0 = 0, na1 = 0;

	for (int i = 0; i < len; i++) {
		if (a[i] == '0')
			na0++;
		else
			na1++;

		if (na0 == na1) {
			if (!check(a, b, begin, i)) {
				cout << "NO" << endl;
				return;
			}
			na0 = na1 = 0;
			begin = i + 1;
		}
	}

	if (na0 != na1) {
		if (!check_pos(a, b, begin, len - 1)) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
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

