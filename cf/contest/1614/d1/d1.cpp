/*
 * No hard feelings.
 * Author: sinfonia
 * Time: 2021-12-04 21:37:58
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
	if (b)
		return gcd(b, a % b);
	else
		return a;
}

int main(void)
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0 ;i < n; i++)
		cin >> a[i];

	//sort(a.begin(), a.end(), greater<int>());

	int ans = 0, prev = a[0];
	for (int i = 0; i < n; i++) {
		prev = gcd(prev, a[i]);
		cout << "prev=" << prev;
		ans += prev;
		cout << "ans=" << ans << endl;
	}
	cout << ans << endl;

	return 0;
}

