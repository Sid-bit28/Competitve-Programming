class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int tot = 0;
        string foo;
        for (auto &x : s) {
            foo.push_back(x);
            if (x == '(') {
                tot++;
            } else tot--;
            if (tot == 0) {
                foo.pop_back();
                ans += foo.substr(1);
                foo.clear();
            }
        }
        return ans;
    }
};