// User function Template for C++

class Solution {
public:
    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        string temp;
        auto rec = [&](auto && rec, int pos, char l)->void{
            if (pos == num) {
                ans.push_back(temp);
                return;
            }
            if (l == '0') {
                temp.push_back('0');
                rec(rec, pos + 1, '0');
                temp.pop_back();
                temp.push_back('1');
                rec(rec, pos + 1, '1');
                temp.pop_back();
            } else {
                temp.push_back('0');
                rec(rec, pos + 1, '0');
                temp.pop_back();
            }
            return;
        };
        temp.push_back('0');
        rec(rec, 1, '0');
        temp.pop_back();
        temp.push_back('1');
        rec(rec, 1, '1');
        temp.pop_back();
        return ans;
    }
};