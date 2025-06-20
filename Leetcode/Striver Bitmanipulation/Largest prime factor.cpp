class Solution {
public:
    int largestPrimeFactor(int n) {
        int ans = 0;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                ans = max(ans, i);
            }
        }
        if (n > 1) {
            ans = n;
        }
        return ans;
    }
};