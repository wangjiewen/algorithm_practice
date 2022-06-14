/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-12 23:38:13
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve_swap(string &s, int i)
{
	bool ans = false;

	for (int j = i - 1; j >= 0; j--) {
		if (s[j] == (s[i] - 1)) {
			swap(s[j], s[i]);
			ans = true;
			break;
		}
	}

	return ans;
}

void solve()
{
	int n;
	string s, t;
	bool ans = true, fans;
	char find;

	cin >> n >> s >> t;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == t[i])
			continue;
		if (s[i] < t[i]) {
			ans = false;
			break;
		}

		fans = solve_swap(s, i);
		if (!fans) {
			ans = false;
			break;
		}
		if (s[i] == t[i])
			continue;
		fans = solve_swap(s, i);
		if (!fans) {
			ans = false;
			break;
		}
	}

	cout << (ans ? "YES" : "NO") << endl;
}

int main(void)
{
	int loop;
	//freopen("in1.txt", "r", stdin);
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}

