/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-12 23:38:13
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int n;
	string s, t;
	bool ans = true;

	cin >> n >> s >> t;

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == t[i])
			continue;
		if (s[i] > t[i]) {
			ans = false;
			break;
		}

		if (s[i] == 'a') {
			if (t[i] == 'c' || s[i+1] != 'b') {
				ans = false;
				break;
			}
			s[i] = 'b';
			s[i+1] = 'a';
		} else if (s[i] == 'b') {
			if (s[i+1] != 'c') {
				ans = false;
				break;
			}
			s[i] = 'c';
			s[i+1] = 'b';
		}
	}
	if (s[n - 1] != t[n - 1])
		ans = false;

	cout << (ans ? "YES" : "NO") << endl;
}

int main(void)
{
	int loop;
	freopen("in1.txt", "r", stdin);
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}

