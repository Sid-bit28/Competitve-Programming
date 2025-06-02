#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define all(x) std::begin(x), std::end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (long long i = a; i < (b); ++i)
#define endl '\n'
#define debarr(a, n)                               \
  cerr << #a << " : ";                             \
  for (int i = 0; i < n; i++) cerr << a[i] << " "; \
  cerr << endl;
#define debmat(mat, row, col)                               \
  cerr << #mat << " :\n";                                   \
  for (int i = 0; i < row; i++) {                           \
    for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; \
    cerr << endl;                                           \
  }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const unordered_set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const unordered_map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}

typedef long long lli;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;
typedef vector<vi> graph;
bool ckmax(auto& a, auto const& b) { return b > a ? a = b, 1 : 0; }
bool ckmin(auto& a, auto const& b) { return b < a ? a = b, 1 : 0; }

int const MOD = 1000000007;

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();

    int low = 1;
    int high = n - 2;
    while (low <= high) {
      int mid = (low + high) / 2;
      int val = arr[mid];
      int val_left = arr[mid - 1];
      int val_right = arr[mid + 1];
      if (val > val_left && val > val_right) {
        return mid;
      } else if (val > val_left && val < val_right) {
        low = mid + 1;
      } else
        high = mid - 1;
    }
    return 0;
  }
};

#ifdef LOCAL
int main() {
  Solution s;
  // cout << s.peakIndexInMountainArray({0, 1, 0}) << endl;
  // cout << s.peakIndexInMountainArray({0, 2, 1, 0}) << endl;
  // cout << s.peakIndexInMountainArray({0, 10, 5, 2}) << endl;
  // cout << s.peakIndexInMountainArray({0, 15, 16, 2}) << endl;
  return 0;
}
#endif