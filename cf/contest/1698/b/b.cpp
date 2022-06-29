/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-28 22:53:57
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
int a[N];
void solve() {
  int n, k;
  int ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (k == 1) {
    cout << (n - 1) / 2 << endl;
    return;
  }
  for (int i = 1; i < n - 1; i++) {
    if (a[i - 1] + a[i + 1] < a[i])
      ans++;
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
