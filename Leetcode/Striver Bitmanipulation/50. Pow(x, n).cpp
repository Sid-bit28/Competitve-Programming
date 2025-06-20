class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int nn = n;
        while (n) {
            if (n & 1) {
                ans *= x;
            }
            x = x * x;
            n /= 2;
        }
        if (nn < 0) {
            return 1.0 / ans;
        }
        return ans;
    }
};