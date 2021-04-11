#include <bits/stdc++.h>

using namespace std;

string sq[405];

void solve()
{
	int n;
	int x[2] = {0}, y[2] = {0};
	int num = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sq[i];
		for (int j = 0; j < n; j++) {
			if (sq[i][j] == '*') {
				x[num] = i;
				y[num] = j;
				num++;
			}
		}
	}

	int tx, ty;
	if (x[0] == x[1]) {
		tx = (x[0] + 1) % n;
		sq[tx][y[0]] = '*';
		sq[tx][y[1]] = '*';
		goto out;
	}
	if (y[0] == y[1]) {
		ty = (y[0] + 1) % n;
		sq[x[0]][ty] = '*';
		sq[x[1]][ty] = '*';
		goto out;
	}

	sq[x[0]][y[1]] = '*';
	sq[x[1]][y[0]] = '*';

out:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << sq[i][j];
		}
		cout << endl;
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

