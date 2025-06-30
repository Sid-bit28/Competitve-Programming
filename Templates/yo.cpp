// Problem: A. Colorful Stones (Simplified Edition)
// Contest: Codeforces - Codeforces Round 162 (Div. 2)
// URL: https://codeforces.com/contest/265/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (long long i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using lli = long long;
using ii = pair<lli, lli>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s, t;
  cin >> s >> t;

  int i = 0, j = 0;
  while (i < sz(s) && j < sz(t)) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }
  cout << i + 1 << endl;
}