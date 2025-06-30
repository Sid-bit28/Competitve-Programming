vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push_back(i);
        } else {
            while (!st.empty() && arr[st.back()] > arr[i]) {
                ans[st.back()] = arr[i];
                st.pop_back();
            }
            st.push_back(i);
        }
    }
    return ans;
}