class Solution {
public:
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans;
        int sum = 0;
        auto rec = [&](auto && rec, int pos)->void{
            if (pos == n) {
                ans.push_back(sum);
                return;
            }
            rec(rec, pos + 1);
            sum += arr[pos];
            rec(rec, pos + 1);
            sum -= arr[pos];
            return;
        };
        rec(rec, 0);
        return ans;
    }
};