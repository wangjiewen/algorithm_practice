/*
 * No hard feelings.
 * Author: sinfonia
 * Time: 2021-12-04 20:55:58
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int a;
	int idx;
} node[200005];
int ans[200005];

bool cmp(const struct node &a, const struct node &b) {
	return a.a > b.a;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> node[i].a;
		node[i].idx = i;
	}

	sort(node + 1, node + n + 1, cmp);

	long long dis = 0, tmp = 1;

	ans[0] = 0;
	for (int i = 1; i <= n; i++) {
		ans[node[i].idx] = tmp;
		if (tmp > 0) {
			dis += 2 * tmp * node[i].a;
			tmp = -tmp;
		} else {
			dis += 2 * (-tmp) * node[i].a;
			tmp = 1 - tmp;
		}
	}

	cout << dis << endl;
	for (int i = 0; i <= n; i++)
		cout << ans[i] << " ";

	cout << endl;
}

int main(void)
{
	int loop;
	scanf("%d", &loop);
	while (loop--) {
		solve();
	}

	return 0;
}

