#include <bits/stdc++.h>

using namespace std;

bool is_pa(string &s)
{
	int l = 0, r = s.size() - 1;

	while (l < r) {
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}
	return true;
}

void solve()
{
	string s;
	cin >> s;
	int pos = 0;
	int end = s.size();

	while (pos <= end) {
		string ans = s.substr(0, pos) + 'a' + s.substr(pos, end - pos);
		if (!is_pa(ans)) {
			cout << "YES" << endl;
			cout << ans << endl;
			return;
		}
		pos++;
	}

	cout << "NO" << endl;
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

