/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-07-12 23:12:48
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int wheels[105];

void each_one(int local) {
  int n, ans = 0;
  char c;

  cin >> n;

  while (n--) {
    cin >> c;
    if (c == 'U')
      ans--;
    else
      ans++;
  }
  ans = (ans + wheels[local] + 20) % 10;
  cout << ans << ' ';
}

void solve() {
  int n;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> wheels[i];

  for (int i = 0; i < n; i++)
    each_one(i);

  cout << endl;
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
