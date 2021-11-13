#include <bits/stdc++.h>

using namespace std;

#define N 200005

int a[N];
int mark[N];

void find_next_num(int &i, int n)
{
	i++;
	for (; i <= n; i++) {
		if (!mark[i])
			break;
	}
}

void solve()
{
	int n;
	cin >> n;
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mark[a[i]] = 1;
	}

	set<int> have;
	int ins = 0, ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (have.find(a[i]) != have.end()) {
			find_next_num(ins, n);
			a[i] = ins;
		} else {
			have.insert(a[i]);
			ans++;
		}
	}

	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
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


