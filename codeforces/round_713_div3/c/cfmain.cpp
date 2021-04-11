#include <bits/stdc++.h>

using namespace std;

bool new_ab(int &a, int &b, string &s, int i)
{
	//cout << "a=" << a << "b=" << b << "s=" << s << "i=" << i << endl;
	if (s[i] == '0')
		a--;
	else
		b--;

	if (a < 0 || b < 0) {
		cout << "-1" << endl;
		return false;
	}
	return true;
}

void solve()
{
	int a, b, len;
	string s;

	cin >> a >> b;
	cin >> s;

	len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] != '?' && !new_ab(a, b, s, i))
			return;
	}

	int head = 0, end = len - 1;
	while (head < end) {
		if (s[head] == '?' && s[end] != '?') {
			s[head] = s[end];
			if (!new_ab(a, b, s, head))
				return;
		} else if (s[head] != '?' && s[end] == '?') {
			s[end] = s[head];
			if (!new_ab(a, b, s, end))
				return;
		} else if (s[head] != '?' && s[end] != '?') {
			if (s[head] != s[end]) {
				cout << "-1" << endl;
				return;
			}
		}
		head++;
		end--;
	}

	if (a + b == 0) {
		cout << s << endl;
		return;
	}

	head = 0;
	end = len - 1;
	while (head < end) {
		if (s[head] == '?') {
			if (a >= 2) {
				s[head] = s[end] = '0';
			} else if (b >= 2) {
				s[head] = s[end] = '1';
			} else {
				cout << "-1" << endl;
				return;
			}
			new_ab(a, b, s, head);
			new_ab(a, b, s, end);
		}
		head++;
		end--;
	}
	if (a + b > 0) {
		if(a) {
			s[head] = '0';
		} else {
			s[head] = '1';
		}
	}
	cout << s << endl;
	return;
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

