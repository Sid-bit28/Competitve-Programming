class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        int tot = 0;
        auto rec = [&](auto && rec, int pos)->void{
            if (tot < 0) return;
            if (pos == 2 * n) {
                if (tot == 0) ans.push_back(temp);
                return;
            }
            temp.push_back('(');
            tot++;
            rec(rec, pos + 1);
            tot--;
            temp.pop_back();
            temp.push_back(')');
            tot--;
            rec(rec, pos + 1);
            tot++;
            temp.pop_back();
            return;
        };
        rec(rec, 0);
        return ans;
    }
};