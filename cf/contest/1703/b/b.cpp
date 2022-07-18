/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-07-12 23:02:49
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  int n, ans = 0;
  char c;
  set<char> a;

  cin >> n;
  while (n--) {
    cin >> c;
    if (a.find(c) == a.end())
      ans += 2;
    else
      ans += 1;
    a.insert(c);
  }
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

