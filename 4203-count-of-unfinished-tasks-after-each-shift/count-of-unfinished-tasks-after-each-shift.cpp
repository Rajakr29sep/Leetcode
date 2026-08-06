class Solution {
public:
    int solve(vector<long long>& prefix, int i, long long target) {
        auto idx = upper_bound(prefix.begin() + i, prefix.end(), target);
        if (idx == prefix.end())
            return -1;

        return idx - prefix.begin();
    }
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> prefix(n);
        prefix[0] = tasks[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + tasks[i];
        }
        int m = shifts.size();
        vector<int> ans;
        int j = 0;
        long long rem = 0;
        for (int i = 0; i < m; i++) {
            long long elem = (j - 1 >= 0 ? prefix[j - 1] : 0) + 1LL*shifts[i] + 1LL*rem;
            int k = solve(prefix, j, elem);
            if (k == -1) {
                ans.push_back(0);
                rem = 0;
                j = 0;
            } else {
                ans.push_back(n - k);
                rem = 1LL*elem - (k - 1 >= 0 ? prefix[k - 1] : 0);
                j = k;
            }
        }
        return ans;
    }
};