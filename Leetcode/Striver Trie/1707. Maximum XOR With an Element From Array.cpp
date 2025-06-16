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
	struct trieNode {
		trieNode* left;
		trieNode* right;
	};

	trieNode* getNode() {
		trieNode* temp = new trieNode;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	void insert(int num, trieNode* root) {
		trieNode* temp = root;
		for (int bit = 31; bit >= 0; bit--) {
			if ((num >> bit) & 1) {
				if (temp->right == NULL) {
					temp->right = getNode();
				}
				temp = temp->right;
			} else {
				if (temp->left == NULL) {
					temp->left = getNode();
				}
				temp = temp->left;
			}
		}
	}
	vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
		int n = sz(nums);
		int m = sz(queries);
		rep(i, 0, m) {
			queries[i].push_back(i);
		}

		auto cmp = [&](vector<int> a, vector<int> b)->bool{
			return a[1] < b[1];
		};
		sort(all(queries), cmp);
		sort(all(nums));

		trieNode* root = getNode();

		vector<int> foo(m);
		int idx = -1;
		rep(i, 0, m) {
			int ans = 0;
			trieNode* temp = root;
			while (idx + 1 < n && nums[idx + 1] <= queries[i][1]) {
				insert(nums[idx + 1], root);
				idx++;
			}
			if (idx == -1) {
				foo[queries[i][2]] = -1;
				continue;
			}
			for (int bit = 31; bit >= 0; bit--) {
				if (queries[i][0] >> bit & 1) {
					if (temp->left != NULL) {
						ans += (1 << bit);
						temp = temp->left;
					} else temp = temp->right;
				} else {
					if (temp->right != NULL) {
						ans += (1 << bit);
						temp = temp->right;
					} else temp = temp->right;
				}
			}
			foo[queries[i][2]] = ans;
		}
		return foo;
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	return 0;
}
#endif