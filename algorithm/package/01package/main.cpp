#include <bits/stdc++.h>

using namespace std;

#define N 1005

int volume;
int size;
int cost[N];
int worth[N];

void init(void)
{
	scanf("%d %d", &volume, &size);
	for (int i = 1; i < size; i++)
		scanf("%d", &cost[i]);
	for (int i = 1; i < size; i++)
		scanf("%d", &worth[i]);
}

/*
 * f(i, v): 前i件物品放在容量为v的背包中可获得的最大价值
 * f(i, v) = max(f(i-1, v), f(i-1,v-ci)+wi)
 * 时间复杂度: O(VN)
 * 空间复杂度: O(VN)
 */
void solve1(void)
{
	int f[size+1][volume+1] = {0}; // 尽量装满

	for (int i = 1; i <= size; i++) {
		for (int v = cost[i]; v <= volume; v++) {
			f[i][v] = max(f[i-1][v], f[i-1][v-cost[i]] + worth[i]);
		}
	}

	cout << f[size][volume] << endl;
}

/*
 * f(v) = max(f(v), f(v-ci)+wi)
 * 优化空间复杂度: O(V)
 */
void solve2(void)
{
	int f[volume+1] = {0}; // 尽量装满

	for (int i = 1; i <= size; i++) {
		for (int v = volume; v >= cost[i]; v--) {
			f[v] = max(f[v], f[v-cost[i]] + worth[i]);
		}
	}

	cout << f[volume] << endl;
}

/*
 * 抽象: 增加一件费用为 Cost，价值 Worth 的物品，更新不同容量最大价值
 */
void zero_one_pack(int *f, int Cost, int Worth)
{
	for (int v = volume; v >= Cost; v--) {
		f[v] = max(f[v], f[v-Cost] + Worth);
	}
}

void solve3(void)
{
	int f[volume+1] = {0}; // 尽量装满
	// 恰好装满
	/*
	for (int i = 1; i <= volume; i++)
		f[i] = INT_MIN;
	*/

	for (int i = 1; i <= size; i++) {
		zero_one_pack(f, cost[i], worth[i]);
	}

	cout << f[volume] << endl;
}

int main(void)
{
	freopen("in", "r", stdin);

	init();
	solve3();

	return 0;
}

