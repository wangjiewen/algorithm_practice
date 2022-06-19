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

bool search(int i, int j) {
  if (i == n - 1 && j == m - 1) {
    if (ans[i][j] == 0)
      return true;
    return false;
  } else if (i >= n || j >= m)
    return false;

  ans[i][j + 1] = ans[i][j] + a[i][j + 1];
  if (search(i, j + 1))
    return true;
  ans[i + 1][j] = ans[i][j] + a[i + 1][j];
  if (search(i + 1, j))
    return true;
  return false;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
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
