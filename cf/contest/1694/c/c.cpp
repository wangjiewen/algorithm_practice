/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-16 23:52:54
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
ll a[N];

void solve()
{
  int n;
  cin >> n;
  ll ans = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int i = n - 1;
  while (i >= 0 && a[i] == 0)
    i--;
  if (i < 0) {
    cout << "Yes" << endl;
    return;
  }

  for (; i >= 0; i--) {
    ans += a[i];
    if (ans >= 0 && i!=0) {
      ans++;
      break;
    }
  }
  cout << ((ans != 0) ? "No" : "Yes") << endl;
}

int main(void)
{
#if 1
  int loop;
  //freopen("in1.txt", "r", stdin);
  scanf("%d", &loop);
  while (loop--) {
    solve();
  }
#else
  solve();
#endif

  return 0;
}

