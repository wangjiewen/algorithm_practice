/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-19 18:07:07
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
ll a[N];
void solve() {
  ll n;
  ll mn, ans = 0, c = 0, num;

  cin >> n;
  for (ll i = 0; i < n; i++)
    cin >> a[i];

  mn = a[0];
  for (ll i = 1; i < n; i++) {
    num = a[i] + c;
    if (num < mn) {
      ans += mn - num;
      mn = num;
    } else if (num > mn) {
      ans += num - mn;
      c -= num - mn;
    }
  }
  ans += abs(0 - mn);
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
