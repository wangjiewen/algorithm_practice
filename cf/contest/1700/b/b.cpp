/*
 * No hard feelings.
 * Author: shengmaiyin
 * Time: 2022-06-19 17:20:00
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// a-b
void _solve(string &a, string &b, int len) {
  char ans[len + 1];
  int i = len, c = 0;
  //cout << "a=" << a<< ",b="<< b <<",len="<< len;
  ans[i] = '\0';
  i--;
  while (i >= 0) {
    if (a[i] + c >= b[i]) {
      ans[i] = a[i] + c - b[i]+'0';
      c = 0;
    } else {
      ans[i] = a[i] + 10 + c - b[i]+'0';
      c = -1;
    }
    //cout << "ans["<<i<<"]="<< ans[i]<< endl;
    i--;
  }
  cout << ans << endl;
}

void make_target1(string &t, int len) {
  for (int i = 0; i < len; i++)
    t.push_back('1');
  t.push_back('\0');
}

void make_target2(string &t, int len) {
  for (int i = 0; i < len; i++)
    t.push_back('6');
  t.push_back('\0');
}

void solve() {
  int len;
  string s, target;
  cin >> len >> s;
  if (s[0] < '5') {
    make_target2(target, len);
  } else {
    make_target1(target, len + 1);
  }
  _solve(target, s, len);
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
