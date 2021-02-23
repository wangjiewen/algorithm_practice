#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

bool cmp(const int &a, const int &b) {
	return a > b;
}

#define N 1005
#define MOD 1000000007

long long comb[N][N];

void init_comb()
{
	for (int i = 0; i < N; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
			comb[i][j] %= MOD;
		}
	}
}

int main(void)
{
	freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	init_comb();
	while (loop--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int a[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		long long cn = 0, cm, num;
		sort(a, a+n, cmp);
		num = a[k - 1];
		for (int i = k - 1; i >= 0 && a[i] == num; i--) {
			cn += 1;
		}
		cm = cn;
		for (int i = k; i < n && a[i] == num; i++)
			cn += 1;

		printf("%lld\n", comb[cn][cm]);
	}

	return 0;
}

