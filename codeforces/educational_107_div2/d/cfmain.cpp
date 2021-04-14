#include <bits/stdc++.h>

using namespace std;

void pa(int x)
{
	char c = 'a' + x;
	cout << c;
}

void solve()
{
	int n, k;
	char c;

	cin >> n >> k;

	int i = 0, j = 0;
	while (n > 0) {
		pa(i);
		n--;
		if (n == 0)
			return;
		if (i < k - 1) {
			pa(j);
			n--;
			i = (i + 1) % k;
		} else {
			j = (j + 1) % k;
			i = j;
		}
	}
}

int main(void)
{
	freopen("in", "r", stdin);

	solve();
	cout << endl;

	return 0;
}

