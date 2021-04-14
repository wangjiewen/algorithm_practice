#include <bits/stdc++.h>

using namespace std;

vector<int> la = {5, 13, 103, 1013, 10009, 100019, 1000033, 10000079, 100000037};
vector<int> lb = {3, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};
void solve()
{
	int a, b, c, pc;

	cin >> a >> b >> c;

	pc = pow(10, c - 1);
	cout << la[a - c] * pc << " " << lb[b - c] * pc << endl;
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

