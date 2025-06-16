#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define all(x) std::begin(x), std::end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
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
	long long maxGCDScore(vector<int> &nums, int k) {
		big n = sz(nums);

		vector<big> f(n, 0);
		rep(i, 0, n) {
			int temp = nums[i];
			int count = 0;
			while (temp % 2 == 0) {
				count++;
				temp /= 2;
			}
			f[i] = count;
		}

		big ans = 0;
		rep(i, 0, n) {
			big gcd = nums[i];
			map<int, int> mp;
			rep(j, i, n) {
				gcd = __gcd(gcd, 1LL * nums[j]);
				mp[f[j]]++;
				auto it = mp.begin();
				if ((*it).S <= k) {
					ckmax(ans, (j - i + 1) * gcd * 2);
				} else ckmax(ans, (j - i + 1) * gcd);
			}
		}
		return ans;
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	// cout << s.maxGCDScore({2, 4}, 1) << endl;
	// cout << s.maxGCDScore({3, 5, 7}, 2) << endl;
	// cout << s.maxGCDScore({4, 8, 32, 4, 16}, 2) << endl;
	// cout << s.maxGCDScore({5, 5, 5}, 1) << endl;
	return 0;
}
#endif