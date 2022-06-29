/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-28 23:25:49
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005
int a[N], b[2];

void four_check(int n) {
  int ans, k;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int z = j + 1; z < n; z++) {
        ans = a[i] + a[j] + a[z];
        for (k = 0; k < n; k++) {
          if (ans == a[k])
            break;
        }
        if (k == n) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
}

void solve() {
  int n, nz = 0;
  cin >> n;
  b[0] = b[1] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 0) {
      if (nz < 2)
        b[nz] = a[i];
      nz++;
    }
  }

  if (n <= 4) {
    four_check(n);
    return;
  }

  if (nz > 2) {
    cout << "NO" << endl;
  } else {
    if (b[0] == 0 || b[1] == 0 || b[0] + b[1] == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
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
