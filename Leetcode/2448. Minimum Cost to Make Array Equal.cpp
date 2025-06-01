class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        auto calc = [&](long long mid)->long long{
            long long tot = 0;
            for (int i = 0; i < n; i++) {
                tot += (long long)abs(mid - nums[i]) * (long long)cost[i];
            }
            return tot;
        };

        long long low = *min_element(nums.begin(), nums.end());
        long long high = *max_element(nums.begin(), nums.end());
        long long ans = INT_MAX;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long cost1 = calc(mid);
            long long cost2 = calc(mid + 1);
            ans = min(cost1, cost2);
            if (cost2 > cost1) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};