// Problem: C. Hamburgers
// Contest: Codeforces - Codeforces Round 218 (Div. 2)
// URL: https://codeforces.com/problemset/problem/371/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define EB emplace_back
#define all(x) std::begin(x), std::end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (long long i = a; i < (b); ++i)
#define endl '\n'

#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)

template <typename T>
void debarr(const T* arr, int n, const string& name = "Array") {
  cerr << name << " = [";
  for (int i = 0; i < n; ++i) {
    cerr << arr[i];
    if (i < n - 1)
      cerr << ", ";
  }
  cerr << "]" << endl;
}

template <typename T>
void debmat(const vector<vector<T>>& mat, const string& name = "Matrix") {
  cerr << name << " = [" << endl;
  for (const auto& row : mat) {
    cerr << "  [";
    for (size_t j = 0; j < row.size(); ++j) {
      cerr << row[j];
      if (j < row.size() - 1)
        cerr << ", ";
    }
    cerr << "]" << endl;
  }
  cerr << "]" << endl;
}

template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p)
    os << it << " ";
  return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, const unordered_set<T>& p) {
  os << "[ ";
  for (auto& it : p)
    os << it << " ";
  return os << "]";
}

template <class S, class T>
ostream& operator<<(ostream& os, const unordered_map<S, T>& p) {
  os << "[ ";
  for (auto& it : p)
    os << it << " ";
  return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p)
    os << it << " ";
  return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, const multiset<T>& p) {
  os << "[ ";
  for (auto& it : p)
    os << it << " ";
  return os << "]";
}

template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p)
    os << it << " ";
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
    if (i != a)
      cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}

typedef long long lli;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;
typedef vector<vi> graph;

template <class T>
bool ckmax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}

template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}

int const MOD = 1000000007;

void pre() {}

void solve() {
  string s;
  cin >> s;
  vector<int> arr(3);
  rep(i, 0, 3) {
    cin >> arr[i];
  }

  vector<int> brr(3);
  rep(i, 0, 3) {
    cin >> brr[i];
  }

  int r;
  cin >> r;

  map<char, int> mp;
  for (auto& x : s) {
    mp[x]++;
  }

  auto check = [&](lli mid) -> bool {
    lli tot = 0;
    for (auto& x : mp) {
    }
  };

  lli low = 0;
  lli high = 1e12;
  lli ans = low;
  while (low <= high) {
    lli mid = low + (high - low) / 2;
    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pre();
  int t = 1;
  cin >> t;
  rep(i, 0, t) solve();
}
