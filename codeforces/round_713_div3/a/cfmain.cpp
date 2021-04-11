#include <bits/stdc++.h>

using namespace std;

int nums[105];
void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	if (nums[1] != nums[0]) {
		if (nums[2] == nums[0])
			cout << "2" << endl;
		else
			cout << "1" << endl;
		return;
	}
	if (nums[2] != nums[0]) {
		cout << "3" << endl;
		return;
	}
	for (int i = 3; i < n; i++) {
		if (nums[i] != nums[0]){
			cout << i+1 << endl;
			return;
		}
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

