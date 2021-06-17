#include <bits/stdc++.h>

#define N 105

using namespace std;


void solve()
{
	int n, temp;
	int a[N] = {0};

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[temp]++;
	}

	for (int i = 0; i < N; i++) {
		if (a[i] != 0) {
			cout << n - a[i] << endl;
			break;
		}
	}
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

