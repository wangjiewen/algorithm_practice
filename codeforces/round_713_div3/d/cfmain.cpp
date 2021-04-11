#include <bits/stdc++.h>

using namespace std;

long long nums[200005];
void solve()
{
	long long n, ans = 0;
	multiset<long long> nf;

	cin >> n;
	for (long long i = 0; i < n + 2; i++) {
		cin >> nums[i];
		nf.insert(nums[i]);
		ans += nums[i];
	}

	for (long long i = 0; i < n + 2; i++) {
		long long tans = ans - nums[i];
		if ((tans % 2) == 0 && nf.find(tans/2) != nf.end()) {
			int tn = nums[i];
			nums[i] = -1;
			long long k;
			for (k = 0; k < n + 2; k++) {
				if (nums[k] == tans/2) {
					nums[k] = -1;
					break;
				}
			}
			if (k >= n + 2) {
				nums[i] = tn;
				continue;
			}
			for (k = 0; k < n + 2; k++) {
				if (nums[k] != -1)
					cout << nums[k] << " ";
			}
			cout << endl;
			return;
		}
	}

	cout << "-1" << endl;
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

