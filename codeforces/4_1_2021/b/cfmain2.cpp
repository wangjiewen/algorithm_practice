#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	freopen("in", "r", stdin);

	int x, ret = 0;
	cin >> x;
	while (x > 0) {
		ret += x % 10;
		x /= 10;
	}
	cout << ret % 10 << endl;
	return 0;
}

