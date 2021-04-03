#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	freopen("in", "r", stdin);

	int x;
	cin >> x;
	if (x < 9)
		cout << x << endl;
	else
		cout << x / 9 << endl;
	return 0;
}

