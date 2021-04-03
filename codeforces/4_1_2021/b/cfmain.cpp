#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	freopen("in", "r", stdin);

	int x;
	cin >> x;
	while (x > 10) {
		x /= 9;
	}
	cout << x << endl;
	return 0;
}

