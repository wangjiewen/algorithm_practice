/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-28 22:42:05
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 128
int a[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << a[0] << endl;
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
