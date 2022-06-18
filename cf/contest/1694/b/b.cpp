/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-16 23:06:21
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  int n;
  string s;
  ll ans = 0;

  cin >> n >> s;
  for (int i = n - 1; i >= 1; i--) {
    if (s[i] == '1' && s[i-1] == '0')
      ans += i + 1;
    else if (s[i] == '0' && s[i-1] == '1')
      ans += i + 1;
    else
      ans += 1;
  }
  ans += 1;
  cout << ans << endl;
}

int main(void)
{
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

