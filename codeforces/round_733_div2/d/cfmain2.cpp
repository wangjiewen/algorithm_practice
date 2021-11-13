#include <bits/stdc++.h>

using namespace std;

#define N 200005

int a[N];
int isc[N];
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
	memset(isc, 0, sizeof(mark));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mark[a[i]] = 1;
		if (have.find(a[i]) != have.end()) {
			isc[i] = 1;
		}
		have.insert(a[i]);
	}

	int ins = 0;
	for (int i = 0; i < n; i++) {
		if (isc[i]) {
			ins++;
			find_next_num(ins, n);
			if (ins == i + 1) {
				for (int j = 0; j < i; j++) {
					if (a[i] == a[j]) {
						a[j] = ins;
						break;
					}
				}
			} else {
				a[i] = ins;
			}
		} else {
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
	//freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}


