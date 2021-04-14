#include <bits/stdc++.h>

using namespace std;

int a[300005];
int q[300005];
void solve()
{
	int n, q, num;
	vector<int> loc(55, INT_MAX);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> num;
		loc[num] = min(loc[num], i + 1);
	}

	for (int i = 0; i < q; i++) {
		cin >> num;
		cout << loc[num] << " ";
		for (int j = 0; j < 55; j++) {
			if (loc[j] < loc[num])
				loc[j]++;
		}
		loc[num] = 1;
	}
	cout << endl;
}

int main(void)
{
	freopen("in", "r", stdin);

	solve();

	return 0;
}

