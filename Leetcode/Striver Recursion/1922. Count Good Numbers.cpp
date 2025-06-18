class Solution {
public:
    using lli = long long;
    int MOD = 1e9 + 7;

    lli binpow(lli a, lli b) {
        lli ans = 1;
        while (b) {
            if (b & 1) {
                ans *= a;
                ans %= MOD;
            }
            a = a * a;
            a %= MOD;
            b /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        lli odd = n / 2;
        lli even = n - odd;
        lli ans = binpow(5, even) * binpow(4, odd) % MOD;
        return (int)ans;
    }
};