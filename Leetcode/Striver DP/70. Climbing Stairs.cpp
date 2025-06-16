class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        auto rec = [&](auto && rec, int pos)->int{
            if (pos == n) {
                return 1;
            }
            if (pos > n) {
                return 0;
            }
            if (dp[pos] != -1) {
                return dp[pos];
            }
            int ans = rec(rec, pos + 1) + rec(rec, pos + 2);
            return dp[pos] = ans;
        };
        int ans = rec(rec, 0);
        return ans;
    }
};