#include <bits/stdc++.h>

using namespace std;

#define N 1005

int volume;
int size;
int cost[N];
int worth[N];
int mark[N];

void init(void)
{
	scanf("%d %d", &volume, &size);
	for(int i = 0; i < size; i++)
		scanf("%d", &cost[i]);
	for(int i = 0; i < size; i++)
		scanf("%d", &worth[i]);
	for(int i = 0; i < size; i++)
		scanf("%d", &mark[i]);
}

void zero_one_pack(int *f, int Cost, int Worth)
{
	for (int v = volume; v >= Cost; v--) {
		f[v] = max(f[v - Cost] + Worth, f[v]);
	}
}


void complete_pack(int *f, int Cost, int Worth)
{
	for (int v = Cost; v <= volume; v++) {
		f[v] = max(f[v - Cost] + Worth, f[v]);
	}
}

void multiple_pack(int *f, int Cost, int Worth, int Mark)
{
	if (Cost * Mark >= volume) {
		complete_pack(f, Cost, Worth);
	}

	int k = 1;
	while (k < Mark) {
		zero_one_pack(f, k * Cost, k * Worth);
		Mark = Mark - k;
		k *= 2;
	}
	zero_one_pack(f, Mark * Cost, Mark * Worth);
}

void solve(void)
{
	int f[volume + 1] = {0};

	for (int i = 1; i <= size; i++) {
		multiple_pack(f, cost[i], worth[i], mark[i]);
	}

	cout << f[volume] << endl;
}

int main(void)
{
	freopen("in", "r", stdin);

	init();
	solve();

	return 0;
}

