#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	int nums[n+5] = {0};

	int a;
	int colors = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums[a] += 1;
		if(nums[a] > colors)
			colors = nums[a];
	}

	cout << colors << endl;
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

