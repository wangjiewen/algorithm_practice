#include <bits/stdc++.h>

using namespace std;

#define N 1005
int s[N][N], t[N][N];

void flip_row(int row, int n)
{
	for (int i = 0; i < n; i++)
		s[row][i] ^= 1;
}

void flip_column(int column, int n)
{
	for (int i = 0; i < n; i++)
		s[i][column] ^= 1;
}

void solve()
{
	int n;
	cin >> n;

	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < n; j++) {
			s[i][j] = temp[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < n; j++) {
			t[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[i][0] != t[i][0]) {
			flip_row(i, n);
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[0][i] != t[0][i]) {
			flip_column(i, n);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] != t[i][j]) {
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
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

