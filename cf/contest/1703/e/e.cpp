/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-07-13 00:04:33
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 105
int a[N][N];
int m[N][N];

void solve() {
  int n;
  string s;

  cin >> n;
  memset(m, 0, sizeof(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%1d", &a[i][j]);

  int ans = 0, tans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (m[i][j])
        continue;
      tans =
          a[i][j] + a[j][n - 1 - i] + a[n - 1 - i][n - 1 - j] + a[n - 1 - j][i];
      m[i][j] = m[j][n - 1 - i] = m[n - 1 - i][n - 1 - j] = m[n - 1 - j][i] = 1;
      if (tans == 3)
        tans = 1;
      else if (tans == 4)
        tans = 0;

      ans += tans;
    }
  }
  cout << ans << endl;
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
