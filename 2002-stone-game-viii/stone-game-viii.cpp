class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& prefix) {
        if (i == prefix.size()-1)
            return prefix[i];

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = prefix[i] - solve(i + 1, prefix);

        int skip = solve(i + 1, prefix);

        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        dp.assign(n, INT_MIN);

        return solve(1, prefix);
    }
};