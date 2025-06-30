#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif

typedef long long lli;
template<class T> bool ckmax(T &a, const T& b) {return b > a ? a = b, 1 : 0;}
template<class T> bool ckmin(T &a, const T& b) {return b < a ? a = b, 1 : 0;}

int const MOD = 1000000007;

vector<int> predictAnswer(vector<int> stockData, vector<int> queries) {
	int n = stockData.size();
	int m = queries.size();
	vector<int> st;
	vector<int> right(n, -1);
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			st.push_back(i);
		} else {
			while (!st.empty() && stockData[st.back()] > stockData[i]) {
				right[st.back()] = i;
				st.pop_back();
			}
			st.push_back(i);
		}
	}

	st.clear();
	vector<int> left(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) {
			st.push_back(i);
		} else {
			while (!st.empty() && stockData[st.back()] > stockData[i]) {
				left[st.back()] = i;
				st.pop_back();
			}
			st.push_back(i);
		}
	}

	vector<int> ans(m, -1);
	for (int i = 0; i < m; i++) {
		int leftt = left[queries[i] - 1];
		int rightt = right[queries[i] - 1];
		if (leftt == -1 && rightt == -1) {
			ans[i] = -1;
		}
		if (leftt != -1 && rightt == -1) {
			ans[i] = leftt + 1;
		}
		if (leftt == -1 && rightt != -1) {
			ans[i] = rightt + 1;
		}
		if (leftt != -1 && rightt != -1) {
			ans[i] = leftt + 1;
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	vector<int> queries(k);
	for (int i = 0; i < k; i++) {
		cin >> queries[i];
	}
	vector<int> ans = predictAnswer(arr, queries);
	for (auto &x : ans) {
		cout << x << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}