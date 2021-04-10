#include <bits/stdc++.h>

using namespace std;

bool is_par(string &s, int begin, int end)
{
	while (begin < end) {
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}

void solve()
{
	int n;
	string s;
	string a, b;
	int begin = 0;

	cin >> n >> s;

	if (s[0] != '1') {
		cout << "NO" << endl;
		return;
	}

	for (int i = 1; i < n; i+=2) {
		if (is_par(s, begin, i)) {
			if (i + 1 < n && s[i + 1] != '1')
				continue;
			int mid = begin + (i - begin + 1) / 2;
			int n0 = 0;
			char add;
			for (int j = begin; j < mid; j++) {
				if (s[j] == '1') {
					a += '(';
					b += '(';
					n0 = 0;
				} else {
					if (n0 & 1) {
						a += '(';
						b += ')';
					} else {
						a += ')';
						b += '(';
					}
					n0++;
				}
			}
			n0 = 0;
			for (int j = mid; j <= i; j++) {
				if (s[j] == '1') {
					a += ')';
					b += ')';
					n0 = 0;
				} else {
					if (n0 & 1) {
						a += ')';
						b += '(';
					} else {
						a += '(';
						b += ')';
					}
					n0++;
				}
			}
			begin = i + 1;
		}
	}

	if (begin < n) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	cout << a << endl;
	cout << b << endl;
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

