class Solution {
public:
    long long shadowPairs(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }

        long long result = 0;
        for (int i = 0; i < n; i++) {
            result += ans[i] - i;

            auto& t = mp[arr[i]];
            auto j = lower_bound(t.begin(), t.end(), ans[i]) - t.begin();

            auto k = lower_bound(t.begin(), t.end(), i) - t.begin();
            result -= (j - k);
        }

        return result;
    }
};