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

typedef long long lli;
typedef pair<lli, lli> ii;    typedef vector<lli> vi;
typedef vector<ii> vii;       typedef vector<vi> graph;
bool ckmax(auto &a, auto const& b) {return b > a ? a = b, 1 : 0;}
bool ckmin(auto &a, auto const& b) {return b < a ? a = b, 1 : 0;}

int const MOD = 1000000007;

class Solution {
public:
	int lastestDayToCross(int row, int col, vector<vector<int>> cells) {
		vector<vi> arr(row, vi(col, 0));

		int dx[4] = { -1, 1, 0, 0};
		int dy[4] = {0, 0, -1, 1};

		auto check_again = [&](int i, int j)->bool{
			if (i >= 0 && i < row && j >= 0 && j < col && arr[i][j] == 0) {
				return true;
			}
			return false;
		};

		auto dfs = [&](auto && dfs, int i, int j)->bool{
			if (i == row - 1) {
				return true;
			}
			arr[i][j] = 1;
			bool ans = false;
			for (int dir = 0; dir < 4; dir++) {
				int ii = i + dx[dir];
				int jj = j + dy[dir];
				if (check_again(ii, jj)) {
					ans |= dfs(dfs, ii, jj);
				}
			}
			return ans;
		};

		auto check = [&](int mid)->bool{
			for (int i = 0; i < mid; i++) {
				arr[cells[i][0] - 1][cells[i][1] - 1] = 1;
			}
			bool ans = false;
			for (int i = 0; i < col; i++) {
				if (check_again(0, i) && dfs(dfs, 0, i)) {
					ans = true;
					break;
				}
			}
			rep(i, 0, row) {
				rep(j, 0, col) {
					arr[i][j] = 0;
				}
			}
			return ans;
		};

		int low = 1;
		int high = row * col;
		int ans = 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (check(mid)) {
				ans = mid;
				low = mid + 1;
			} else high = mid - 1;
		}
		return ans;
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	// cout << s.lastestDayToCross(2, 2, {{1, 1}, {2, 1}, {1, 2}, {2, 2}}) << endl;
	// cout << s.lastestDayToCross(2, 2, {{1, 1}, {1, 2}, {2, 1}, {2, 2}}) << endl;
	// cout << s.lastestDayToCross(3, 3, {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}}) << endl;
	return 0;
}
#endif