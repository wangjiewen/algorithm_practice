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
	for (int i = 1; i <= size; i++)
		scanf("%d", &cost[i]);
	for (int i = 1; i <= size; i++)
		scanf("%d", &worth[i]);
}

/*
 * f(i, v): 前i种物品放在容量为v的背包中可获得的最大价值，一种物品有多件
 * f(i, v) = max(f(i-1, v), f(i,v-ci)+wi)
 * 时间复杂度: O(VN)
 * 空间复杂度: O(VN)
 */
void solve1(void)
{
	int f[size+1][volume+1] = {0}; // 尽量装满

	for (int i = 1; i <= size; i++) {
		for (int v = cost[i]; v <= volume; v++) {
			f[i][v] = max(f[i-1][v], f[i][v-cost[i]] + worth[i]);
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
		for (int v = cost[i]; v <= volume; v++) {
			f[v] = max(f[v], f[v-cost[i]] + worth[i]);
		}
	}

	cout << f[volume] << endl;
}

/*
 * 抽象: 增加一种费用为 Cost，价值 Worth 的物品，更新不同容量最大价值
 * 理解：不选则是 f[i-1][v], 选择的情况此前可以已经选过
 */
void complete_pack(int *f, int Cost, int Worth)
{
	for (int v = Cost; v <= volume; v++) {
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
		complete_pack(f, cost[i], worth[i]);
	}

	cout << f[volume] << endl;
}

/*
 * simple performance: 去掉cost[i] >= cost[j] && worth[i] <= worth[j] 的物品i
 */

int main(void)
{
	freopen("in", "r", stdin);

	init();
	solve3();

	return 0;
}

