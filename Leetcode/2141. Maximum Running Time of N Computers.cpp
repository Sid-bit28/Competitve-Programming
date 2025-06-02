#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define all(x) std::begin(x), std::end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define endl '\n'
#define debarr(a, n) cerr << #a << " : ";for(int i = 0; i < n; i++) cerr << a[i] << " "; cerr << endl;
#define debmat(mat, row, col) cerr << #mat << " :\n";for(int i = 0; i < row; i++) {for(int j = 0; j < col; j++) cerr << mat[i][j] << " ";cerr << endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

typedef long long big;
typedef pair<big, big> ii;    typedef vector<big> vi;
typedef vector<ii> vii;       typedef vector<vi> graph;
bool ckmax(auto &a, auto const& b) {return b > a ? a = b, 1 : 0;}
bool ckmin(auto &a, auto const& b) {return b < a ? a = b, 1 : 0;}

int const MOD = 1000000007;

class Solution {
public:
	long long maxRunTime(int n, vector<int> batteries) {
		int nn = sz(batteries);

		auto check = [&](big mid)->bool{
			big tot = 0;
			rep(i, 0, nn) {
				tot += min(mid, 1LL * batteries[i]);
				if (tot >= (n * 1LL * mid)) {
					return true;
				}
			}
			return false;
		};

		big low = 0;
		big high = 1e15;
		big ans = low;
		while (low <= high) {
			big mid = low + (high - low) / 2;
			if (check(mid)) {
				ans = mid;
				low = mid + 1;
			} else high = mid - 1;
		}
		return ans;
	}
};

// #ifdef LOCAL
int main() {
	Solution s;
	cout << s.maxRunTime(2, {3, 3, 3}) << endl;
	cout << s.maxRunTime(2, {1, 1, 1, 1}) << endl;
	return 0;
}
// #endif