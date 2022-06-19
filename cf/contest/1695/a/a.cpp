/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-18 22:44:59
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 45
int a[N][N];
void solve() {
  int n, m;
  int tmax = INT_MIN, ti, tj;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] > tmax) {
        tmax = a[i][j];
        ti = i;
        tj = j;
      }
    }
  }
  int l, r;
  l = max(n - ti, ti + 1);
  r = max(m - tj, tj + 1);
  cout << l * r << endl;
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
