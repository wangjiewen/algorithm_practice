#include <bits/stdc++.h>

using namespace std;

#define N 200005

int a[N];
int b[N];
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
	scanf("%d", &n);

	int ans = 0;
	memset(mark, 0, sizeof(int)*(n+5));
	memset(isc, 0, sizeof(int)*(n+5));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (mark[a[i]])
			isc[i] = 1;
		mark[a[i]] = 1;
	}

	int ins = 0;
	for (int i = 0; i < n; i++) {
		if (isc[i]) {
			ins++;
			find_next_num(ins, n);
			if (ins == i + 1) {
				int j = b[a[i]];
				a[j] = ins;
				b[a[j]] = j;
			} else {
				a[i] = ins;
			}
		} else {
			ans++;
		}
		b[a[i]] = i;
	}

	printf("%d\n", ans);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
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

