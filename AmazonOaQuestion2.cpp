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

lli findMinPrice(vector<int> cost, int pairCost, int k) {
    int n = cost.size();
    vector<vector<vector<lli>>> dp(n, vector<vector<lli>>(k + 1, vector<lli>(2, -1)));
    auto rec = [&](auto && rec, int side, int idx, int turns)->lli{
        if (side == 0 && idx >= n - 1 - turns) {
            if (idx == n - 1 - turns) {
                return cost[idx];
            }
            return 0;
        }
        if (side == 1 && idx <= turns) {
            if (idx == turns) {
                return cost[idx];
            }
            return 0;
        }
        if (dp[idx][turns][side] != -1) {
            return dp[idx][turns][side];
        }
        lli ans = 1e17;
        if (side == 0) {
            ans = min(ans, cost[idx] + rec(rec, side, idx + 1, turns));
            if (turns < k) {
                ans = min(ans, pairCost + rec(rec, side, idx + 1, turns + 1));
            }
        }
        if (side == 1) {
            ans = min(ans, cost[idx] + rec(rec, side, idx - 1, turns));
            if (turns < k) {
                ans = min(ans, pairCost + rec(rec, side, idx - 1, turns + 1));
            }
        }
        return dp[idx][turns][side] = ans;
    };
    lli ans = min(rec(rec, 0, 0, 0), rec(rec, 1, n - 1, 0));
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int pairCost;
    cin >> pairCost;
    int k;
    cin >> k;
    cout << findMinPrice(arr, pairCost, k) << endl;
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