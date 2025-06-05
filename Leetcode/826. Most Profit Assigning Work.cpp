class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        int m = profit.size();
        sort(worker.begin(), worker.end());

        vector<pair<int, int>> arr;
        for (int i = 0; i < m; i++) {
            arr.emplace_back(difficulty[i], profit[i]);
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        int idx = 0;
        int foo = 0;
        for (int i = 0; i < n; i++) {
            while (idx < m && arr[idx].first <= worker[i]) {
                ans = max(ans, arr[idx].second);
                idx++;
            }
            foo += ans;
        }
        return foo;
    }
};