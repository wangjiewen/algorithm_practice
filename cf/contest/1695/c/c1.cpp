/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-18 23:42:11
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 1005
int n, m;
int a[N][N];
int ans[N][N];
set<int> diff[N][N];

bool search(int i, int j) {
  int ni, nj;
  if (i == n - 1 && j == m - 1) {
    if (ans[i][j] == 0)
      return true;
    return false;
  } else if (i >= n || j >= m)
    return false;

  ni = i;
  nj = j + 1;
  ans[ni][nj] = ans[i][j] + a[ni][nj];
  if (diff[ni][nj].find(ans[ni][nj]) == diff[ni][nj].end()) {
    diff[ni][nj].insert(ans[ni][nj]);
    if (search(ni, nj))
      return true;
  }

  ni = i + 1;
  nj = j;
  ans[ni][nj] = ans[i][j] + a[ni][nj];
  if (diff[ni][nj].find(ans[ni][nj]) == diff[ni][nj].end()) {
    diff[ni][nj].insert(ans[ni][nj]);
    if (search(ni, nj))
      return true;
  }
  return false;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      diff[i][j].clear();
    }
  if ((n + m - 1) & 1) {
    cout << "NO" << endl;
    return;
  }
  ans[0][0] = a[0][0];
  cout << (search(0, 0) ? "YES" : "NO") << endl;
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
