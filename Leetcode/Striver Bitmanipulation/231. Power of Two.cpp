class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!n) {
            return false;
        }
        long long nn = n;
        return !(nn & (nn - 1));
    }
};