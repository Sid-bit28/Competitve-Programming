class Solution {
public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        auto rec = [&](auto && rec, int pos, int tot)->bool{
            if (tot > k) {
                return false;
            }
            if (pos == n) {
                if (tot == k) {
                    return true;
                }
                return false;
            }

            if (dp[pos][tot] != -1) {
                return dp[pos][tot];
            }

            bool ans = rec(rec, pos + 1, tot);
            ans |= rec(rec, pos + 1, tot + arr[pos]);
            return dp[pos][tot] = ans;
        };
        bool ans = rec(rec, 0, 0);
        return ans;
    }
};