#include<bits/stdc++.h>
using namespace std;
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

int const MOD = 1000000007;

// Code here...
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		vector<int> nextSmaller(n, -1);
		vector<int> st;
		for (int i = 0; i < n; i++) {
			if (st.empty()) {
				st.push_back(i);
			} else {
				while (!st.empty() && heights[st.back()] > heights[i]) {
					nextSmaller[st.back()] = i;
					st.pop_back();
				}
				st.push_back(i);
			}
		}
		st.clear();
		vector<int> prevSmaller(n, -1);
		for (int i = n - 1; i >= 0; i--) {
			if (st.empty()) {
				st.push_back(i);
			} else {
				while (!st.empty() && heights[st.back()] > heights[i]) {
					prevSmaller[st.back()] = i;
					st.pop_back();
				}
				st.push_back(i);
			}
		}
		lli ans = 0;
		for (int i = 0; i < n; i++) {
			lli val = 0;
			if (nextSmaller[i] == -1 && prevSmaller[i] == -1) {
				val += heights[i] * n;
			} else if (nextSmaller[i] != -1 && prevSmaller[i] == -1) {
				val += heights[i] * nextSmaller[i];
			} else if (nextSmaller[i] == -1 && prevSmaller[i] != -1) {
				val += heights[i] * (n - prevSmaller[i] - 1);
			} else {
				val += heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
			}
			ans = max(ans, val);
		}
		return ans;
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	// cout << s.largestRectangleArea({2, 1, 5, 6, 2, 3}) << endl;
	// cout << s.largestRectangleArea({2, 4}) << endl;
	return 0;
}
#endif