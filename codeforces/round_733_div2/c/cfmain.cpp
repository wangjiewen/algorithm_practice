#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, suma = 0, sumb = 0;
	priority_queue<int, vector<int>, greater<int>> a, b;
	priority_queue<int> tb;

	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push(num);
		suma += num;
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		b.push(num);
		sumb += num;
	}
	for (int i = 0; i < n; i++) {
		if ((i + 1) % 4 == 0) {
			suma -= a.top();
			a.pop();
			sumb -= b.top();
			tb.push(b.top());
			b.pop();
		}
	}

	int ans = 0;
	while (suma < sumb) {
		ans++;
		a.push(100);
		suma += 100;
		if ((n + ans) % 4 == 0) {
			suma -= a.top();
			a.pop();
		} else if (!tb.empty()) {
			sumb += tb.top();
			tb.pop();
		}
	}

	cout << ans << endl;
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

