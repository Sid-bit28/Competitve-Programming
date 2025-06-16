class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto check = [&](int mid)->bool{
            int tot = 0;
            for (int i = 0; i < nums.size(); i++) {
                tot += (nums[i] + mid - 1) / mid;
            }
            return tot <= threshold;
        };
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};