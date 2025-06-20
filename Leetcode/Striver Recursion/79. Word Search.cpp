#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
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

// Code here...
class Solution {
public:
	bool exist(vector<vector<char>> &board, string word) {
		int n = sz(board);
		int m = sz(board[0]);

		int dx[4] = { -1, 1, 0, 0};
		int dy[4] = {0, 0, -1, 1};

		vector<vector<int>> vis;

		auto check = [&](int i, int j)->bool{
			if (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false) {
				return true;
			}
			return false;
		};

		auto rec = [&](auto && rec, int pos, int i, int j)->bool{
			if (pos == sz(word)) {
				return true;
			}

			vis[i][j] = true;
			bool ans = false;
			rep(dir, 0, 4) {
				int ni = i + dx[dir];
				int nj = j + dy[dir];
				if (check(ni, nj) && word[pos] == board[ni][nj]) {
					ans |= rec(rec, pos + 1, ni, nj);
				}
			}
			vis[i][j] = false;
			return ans;
		};

		rep(i, 0, n) {
			rep(j, 0, m) {
				if (board[i][j] == word[0]) {
					vis = vector<vector<int>> (n, vector<int>(m, false));
					if (rec(rec, 1, i, j)) {
						return true;
					}
				}
			}
		}
		return false;
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	// cout << s.exist({{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCESEEEFS") << endl;
	return 0;
}
#endif