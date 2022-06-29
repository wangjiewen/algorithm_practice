/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-29 00:24:23
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
  int n;
  cin >> n;

  int l, r, m;
  l = 1;
  r = n;
  m = (l + r) / 2;

  while (1) {
    int num, ans = 0;
    cout << "? " << l << " " << m << endl;
    cout.flush();
    for (int i = 0; i < m - l + 1; i++) {
      cin >> num;
      if (num >= l && num <= m)
        ans++;
    }
    if (ans & 1) {
      r = m;
    } else {
      l = m + 1;
    }
    m = (l + r) / 2;
    if (l == r) {
      cout << "! " << l << endl;
      return;
    }
  }
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
