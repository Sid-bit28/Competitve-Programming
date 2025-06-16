class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        auto check = [&](int mid)->bool{
            int tot = 0;
            for (int i = 0; i < n; i++) {
                if (piles[i] % mid == 0) {
                    tot += piles[i] / mid;
                } else tot += piles[i] / mid + 1;
                if (tot > h) {
                    return false;
                }
            }
            return tot <= h;
        };
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};