/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-18 23:03:18
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 55
int a[N];
void solve() {
  int n;
  int m = INT_MAX, j = INT_MAX;
  int lm, lj;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (n & 1) {
    cout << "Mike" << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      if (a[i] < j) {
        j = a[i];
        lj = i;
      }
    } else {
      if (a[i] < m) {
        m = a[i];
        lm = i;
      }
    }
  }
  //cout << 'm' << m << ',' << lm << 'j' << j << ',' << lj << endl;
  if (m > j)
    cout << "Mike" << endl;
  else if (m == j) {
    if (lj < lm)
      cout << "Mike" << endl;
    else
      cout << "Joe" << endl;
  } else
    cout << "Joe" << endl;
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
