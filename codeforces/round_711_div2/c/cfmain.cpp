#include <bits/stdc++.h>

using namespace std;

#define N 1005
#define P 1000000007

int dp[N][N] = {1};

void init()
{
	dp[0][0] = 0;
	for (int k = 1; k < N; k++) {
		dp[0][k] = 1;
	}
	dp[1][1] = 1;
	for (int k = 2; k < N; k++) {
		dp[1][k] = 2;
	}
	for (int n = 0; n < N; n++) {
		dp[n][1] = 1;
	}

	for (int k = 2; k < N; k++) {
		for (int n = 2; n < N; n++) {
			dp[n][k] = 1;
			for (int q = 0; q < n; q++) {
				dp[n][k] = (dp[n][k] + dp[q][k - 1]) % P;
			}
		}
	}
/*
	for (int k = 2; k < N; k++) {
		for (int n = 2; n < N; n++) {
			dp[n][k] = dp[n-1][k] + dp[n-1][k-1];
		}
	}
*/
}

void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", dp[n][k]);
}

int main(void)
{
	freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	init();
	while (loop--) {
		solve();
	}

	return 0;
}

