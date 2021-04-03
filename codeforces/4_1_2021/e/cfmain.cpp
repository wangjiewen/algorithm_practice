#include <bits/stdc++.h>

using namespace std;

char d[8][8];
int h, w;

void init()
{
	string str;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < w; j++) {
			d[i][j] = str[i];
		}
	}
}

int diff_r(int x, int y)
{
	while (x) {

	}
}

void solve() {
	int x = 0, y = 0;

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

