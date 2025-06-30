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
	long long subArrayRanges(vector<int>& nums) {
		int n = nums.size();
		vector<int> nextBigger(n, -1);
		vector<int> st;
		for (int i = 0; i < n; i++) {
			if (st.empty()) {
				st.push_back(i);
			} else {
				while (!st.empty() && nums[st.back()] < nums[i]) {
					nextBigger[st.back()] = i;
					st.pop_back();
				}
				st.push_back(i);
			}
		}
		vector<int> nextSmaller(n, -1);
		st.clear();
		for (int i = 0; i < n; i++) {
			if (st.empty()) {
				st.push_back(i);
			} else {
				while (!st.empty() && nums[st.back()] > nums[i]) {
					nextSmaller[st.back()] = i;
					st.pop_back();
				}
				st.push_back(i);
			}
		}
		vector<int> prevBigger(n, -1);
		st.clear();
		for (int i = n - 1; i >= 0 ; i--) {
			if (st.empty()) {
				st.push_back(i);
			} else {
				while (!st.empty() && nums[st.back()] <= nums[i]) {
					prevBigger[st.back()] = i;
					st.pop_back();
				}
				st.push_back(i);
			}
		}
		vector<int> prevSmaller(n, -1);
		st.clear();
		for (int i = n - 1; i >=  0; i--) {
			if (st.empty()) {
				st.push_back(i);
			} else {
				while (!st.empty() && nums[st.back()] >= nums[i]) {
					prevSmaller[st.back()] = i;
					st.pop_back();
				}
				st.push_back(i);
			}
		}
		lli ans = 0;
		for (int i = 0; i < n; i++) {
			lli leftMin = i - prevSmaller[i];
			lli rightMin = (nextSmaller[i] == -1 ? n : nextSmaller[i]) - i;
			lli leftMax = i - prevBigger[i];
			lli rightMax = (nextBigger[i] == -1 ? n : nextBigger[i]) - i;

			ans += nums[i] * (leftMax * rightMax - leftMin * rightMin);
		}
		return ans;
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	// cout << s.subArrayRanges({1, 2, 3}) << endl;
	return 0;
}
#endif