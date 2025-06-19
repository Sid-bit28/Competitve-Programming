class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        auto rec = [&](auto && rec, int pos)->void{
            if (pos == n) {
                ans.push_back(temp);
                return;
            }
            rec(rec, pos + 1);
            temp.push_back(nums[pos]);
            rec(rec, pos + 1);
            temp.pop_back();
            return;
        };
        rec(rec, 0);
        return ans;
    }
};