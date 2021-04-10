#include <bits/stdc++.h>

using namespace std;

int len;

void pr_ok(string &s, int pos)
{
	printf("YES\n");
	for (int i = 0; i < pos; i++)
		printf("%c", s[i]);
	printf("a");
	for (int i = pos; i < len; i++)
		printf("%c", s[i]);
	printf("\n");
}

void solve()
{
	string s;
	cin >> s;
	len = s.size();

	int l = 0, r = len - 1;

	while (l <= r) {
		if (s[l] != s[r]) {
			pr_ok(s, l + 1);
			return;
		} else {
			if (s[l] != 'a') {
				pr_ok(s, r + 1);
				return;
			} else if (s[r] != 'a') {
				pr_ok(s, l);
				return;
			}
		}
		l++;
		r--;
	}
	printf("NO\n");
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

