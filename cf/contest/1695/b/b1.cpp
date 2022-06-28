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

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (n & 1) {
    cout << "Mike" << endl;
    return;
  }
  int lmin = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < a[lmin])
      lmin = i;
  }
  if (lmin & 1)
    cout <<"Mike" <<endl;
  else
    cout <<"Joe"<<endl;
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
