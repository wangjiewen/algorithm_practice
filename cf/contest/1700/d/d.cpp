/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-19 18:50:16
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
ll v[N];
void solve() {
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++)
    cin >> v[i];
  ll q;
  cin >> q;
  while (q--) {
    ll s, ans = 0, c = 0;
    cin >> s;
    for (ll i = 0; i < n; i++) {
      if (c + s < v[i]) {
        ans = -1;
        break;
      }
      if (c < v[i]) {
        ans++;
        c = c + s - v[i];
      } else {
        c -= v[i];
      }
    }
    cout << ans << endl;
  }
}

int main(void) {
#if 0
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
