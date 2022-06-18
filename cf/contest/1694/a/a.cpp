/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-16 22:41:18
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  int a, b;
  cin >> a >> b;
  while (a != 0 && b != 0) {
    cout << "10";
    a--;
    b--;
  }
  while (a--)
    cout << '0';
  while (b--)
    cout << '1';
  cout << endl;
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

