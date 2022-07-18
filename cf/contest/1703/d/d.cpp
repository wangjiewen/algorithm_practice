/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-07-12 23:34:33
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100005

string all[N];

void solve() {
  int n;
  set<string> s;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> all[i];

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      s.insert(all[i]+all[j]);
      s.insert(all[j]+all[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    if (s.find(all[i]) == s.end())
      cout << '0';
    else
      cout << '1';
  }
  cout << endl;
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
