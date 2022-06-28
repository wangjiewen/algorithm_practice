/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-19 17:09:54
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, m;
  cin >> n >> m;
  cout << (m * (m + 1)) / 2 + m * (n * (n + 1) / 2) - m << endl;
}

int main(void) {
#if 1
  int loop;
  scanf("%d", &loop);
  while (loop--) {
    solve();
  }
#else
  solve();
#endif

  return 0;
}
