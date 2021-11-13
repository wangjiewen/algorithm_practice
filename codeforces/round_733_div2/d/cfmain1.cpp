#include <bits/stdc++.h>

using namespace std;

#define N 200005

int a[N];
int mark[N];

void find_next_num(int &i, int n)
{
	for (; i <= n; i++) {
		if (!mark[i])
			break;
	}
}

void solve()
{
	int n;
	cin >> n;

	set<int> have;
	int ans = 0;
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mark[a[i]] = 1;
		ans++;
		if (have.find(a[i]) != have.end()) {
			a[i] = 0;
			ans--;
		} else {
			have.insert(a[i]);
		}
	}

	cout << ans << endl;

	int ins = 0;
	for (int i = 0; i < n; i++) {
		if (!a[i]) {
			ins++;
			find_next_num(ins, n);
			cout << ins << ' ';
		} else {
			cout << a[i] << ' ';
		}
	}

	cout << endl;
}

int main(void)
{
	//freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}


