#include <bits/stdc++.h>

using namespace std;

#define N 100005
int re[N], im[N];
int a[2*N];

void solve()
{
	int n, m;
	int point;
	int num_re = 0, num_im = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> point;
		if (point == 1) {
			re[num_re++] = a[i];
		} else {
			im[num_im++] = a[i];
		}
	}

	sort(re, re+num_re, greater<int>());
	sort(im, im+num_im, greater<int>());
	point = 0;
	mem = 0;
	int rei = 0, imi = 0;
	while (mem < k) {
		if (re[rei] >= im[imi]) {
			mem += re[rei++];
			point += 1;
		} else if (rei + 1 < num_re) {
			if (re[rei] + re[rei+1] >= im[imi]) {
				mem += re[rei++];
				point += 1;
			} else {
				mem += im[imi++];
				point += 2;
			}
		} else

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

