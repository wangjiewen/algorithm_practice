/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-07-12 22:39:48
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  string s;
  cin >> s;
  if (s[0] != 'Y' && s[0] != 'y') {
    cout << "NO" << endl;
    return;
  }
  if (s[1] != 'E' && s[1] != 'e') {
    cout << "NO" << endl;
    return;
  }
  if (s[2] != 'S' && s[2] != 's') {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
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

